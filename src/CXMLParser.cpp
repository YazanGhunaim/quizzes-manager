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

    auto answerIt = m_answerTypes.find(answerType);
    if (answerIt != m_answerTypes.end())
    {
        answer = answerIt->second(answers);
    }
    else
    {
        throw std::runtime_error("\033[1;31mUnknown answer type: " + answerType + "\033[0m");
    }

    auto questionIt = m_questionTypes.find(questionType);
    if (questionIt != m_questionTypes.end())
    {
        vec.push_back(questionIt->second(questionTitle, answer, options));
    }
    else
    {
        throw std::runtime_error("\033[1;31mUnknown question type: " + answerType + "\033[0m");
    }
}

void CXMLParser::getOptions(xmlNodePtr &node, std::vector<std::string> &vec)
{
    for (xmlNodePtr optionChild = node->children; optionChild != nullptr; optionChild = optionChild->next)
    {
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

    std::string quizTite = reinterpret_cast<const char *>(xmlGetProp(root, (const xmlChar *)"title"));
    std::vector<std::shared_ptr<CSection>> sections;

    for (xmlNodePtr node = root->children; node != nullptr; node = node->next)
    {
        std::string sectionTitle;
        std::vector<std::shared_ptr<CQuestion>> questions;
        // sections
        if (node->type == XML_ELEMENT_NODE && xmlStrcmp(node->name, (const xmlChar *)"section") == 0)
        {
            sectionTitle = reinterpret_cast<const char *>(xmlGetProp(node, (const xmlChar *)"title"));

            for (xmlNodePtr questionPtr = node->children; questionPtr != nullptr; questionPtr = questionPtr->next)
            {
                // questions in sections
                getQuestions(questionPtr, questions);
            }
            sections.emplace_back(std::make_shared<CSection>(sectionTitle, questions));
        }
    }
    // Clean up
    xmlFreeDoc(doc);
    xmlFreeParserCtxt(context);
    return std::make_shared<CQuiz>(quizTite, sections);
}