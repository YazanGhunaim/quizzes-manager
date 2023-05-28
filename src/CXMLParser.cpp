#include "headers/parser/CXMLParser.hpp"

CXMLParser::CXMLParser(const std::string &filePath)
    : m_filePath(std::move(filePath)) {}

CXMLParser::~CXMLParser() {}

void CXMLParser::setup(xmlParserCtxtPtr &context, xmlDocPtr &doc, xmlNodePtr &root)
{
    // initialize the parser context
    context = xmlNewParserCtxt();
    // parse the XML file
    doc = xmlCtxtReadFile(context, m_filePath.c_str(), nullptr, 0);
    // get the root element
    root = xmlDocGetRootElement(doc);
}

void CXMLParser::addToQuestVec(const std::string &questionType, const std::string &questionTitle, const std::string &answerType, const std::vector<std::string> &answers, const std::vector<std::string> &options, std::vector<std::shared_ptr<CQuestion>> &vec)
{
    CAnswer *answer = nullptr;

    // get the answer type and create the answer
    auto answerIt = m_answerTypes.find(answerType);
    if (answerIt != m_answerTypes.end()) // if the answer type is found, create the answer
    {
        answer = answerIt->second(answers);
    }
    else // if the answer type is not found, throw an exception
    {
        throw std::runtime_error("\033[1;31mUnknown answer type: " + answerType + "\033[0m");
    }

    // get the question type and create the question
    auto questionIt = m_questionTypes.find(questionType);
    if (questionIt != m_questionTypes.end()) // if the question type is found, create the question
    {
        vec.push_back(questionIt->second(questionTitle, answer, options));
    }
    else // if the question type is not found, throw an exception
    {
        throw std::runtime_error("\033[1;31mUnknown question type: " + answerType + "\033[0m");
    }
}

void CXMLParser::getOptions(xmlNodePtr &node, std::vector<std::string> &vec)
{
    for (xmlNodePtr optionChild = node->children; optionChild != nullptr; optionChild = optionChild->next)
    {
        // options are in tags <text> </text> within <options> </options>
        if (optionChild->type == XML_ELEMENT_NODE && xmlStrcmp(optionChild->parent->name, (const xmlChar *)"options") == 0 && xmlStrcmp(optionChild->name, (const xmlChar *)"text") == 0)
        {
            std::string option = reinterpret_cast<const char *>(xmlNodeGetContent(optionChild));
            vec.push_back(option);
        }
    }
}

void CXMLParser::getQuestions(xmlNodePtr &node, std::vector<std::shared_ptr<CQuestion>> &vec)
{
    // Extract the question and answers
    std::string questionType;
    std::string questionTitle;
    std::string answerType;
    std::vector<std::string> options;
    std::vector<std::string> answers;

    // Extract the question details
    for (xmlNodePtr child = node->children; child != nullptr; child = child->next)
    {
        xmlAttrPtr attr = node->properties;
        questionType = reinterpret_cast<const char *>(xmlGetProp(node, attr->name));
        if (child->type == XML_ELEMENT_NODE)
        {
            if (questionType == "multi" || questionType == "single")
            {
                getOptions(child, options);
            }
            if (xmlStrcmp(child->name, (const xmlChar *)"text") == 0)
            {
                questionTitle = reinterpret_cast<const char *>(xmlNodeGetContent(child));
            }

            else if (xmlStrcmp(child->name, (const xmlChar *)"answer") == 0)
            {
                xmlAttrPtr attr = child->properties;
                answerType = reinterpret_cast<const char *>(xmlGetProp(child, attr->name));

                for (xmlNodePtr answerChild = child->children; answerChild != nullptr; answerChild = answerChild->next)
                {
                    // add the answers to the vector
                    if (answerChild->type == XML_ELEMENT_NODE && xmlStrcmp(answerChild->name, (const xmlChar *)"text") == 0)
                    {
                        std::string answer = reinterpret_cast<const char *>(xmlNodeGetContent(answerChild));
                        answers.push_back(answer);
                    }
                }
                try
                {
                    addToQuestVec(questionType, questionTitle, answerType, answers, options, vec);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                }
                catch (...)
                {
                    std::cerr << "\033[1;31mUnknown error\033[0m" << '\n';
                }

                answers.clear();
            }
        }
    }
}

std::shared_ptr<CQuiz> CXMLParser::parse()
{
    xmlParserCtxtPtr context;
    xmlDocPtr doc;
    xmlNodePtr root;

    setup(context, doc, root);

    // Extract the quiz title
    std::string quizTitle = reinterpret_cast<const char *>(xmlGetProp(root, (const xmlChar *)"title"));
    std::vector<std::shared_ptr<CSection>> sections;

    // Extract the sections
    for (xmlNodePtr node = root->children; node != nullptr; node = node->next)
    {
        std::string sectionTitle;
        std::vector<std::shared_ptr<CQuestion>> questions;

        // sections
        if (node->type == XML_ELEMENT_NODE && xmlStrcmp(node->name, (const xmlChar *)"section") == 0)
        {
            // Extract the section title
            sectionTitle = reinterpret_cast<const char *>(xmlGetProp(node, (const xmlChar *)"title"));

            // Extract the questions in the section
            for (xmlNodePtr questionPtr = node->children; questionPtr != nullptr; questionPtr = questionPtr->next)
            {
                // questions in sections
                getQuestions(questionPtr, questions);
            }
            // Add the section to the vector of sections
            sections.emplace_back(std::make_shared<CSection>(sectionTitle, questions));
        }
    }
    // Clean up
    xmlFreeDoc(doc);
    xmlFreeParserCtxt(context);
    return std::make_shared<CQuiz>(quizTitle, sections);
}