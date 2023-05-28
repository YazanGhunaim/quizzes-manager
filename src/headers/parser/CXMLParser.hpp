#pragma once

#include "../quiz/CQuiz.hpp"
#include "../question/CMultiChoiceQuestion.hpp"
#include "../question/CSingleChoiceQuestion.hpp"
#include "../question/CTextQuestion.hpp"
#include "../answer/CTextAnswer.hpp"
#include "../answer/CMultipleChoiceAnswer.hpp"
#include "../answer/CIntervalAnswer.hpp"
#include "../answer/CTrueFalseAnswer.hpp"
#include "../answer/CTextAnswer.hpp"
#include <libxml/parser.h>
#include <map>

/*
 * CXMLParser class represents a parser.
 * It contains a file path, a map of question types and a map of answer types.
 * The question types map contains a string and a function that returns a question.
 * The answer types map contains a string and a function that returns an answer.
 * The parser parses the XML file and returns a quiz.
 */

class CXMLParser
{
private:
    std::string m_filePath;

    std::unordered_map<std::string,
                       std::function<std::shared_ptr<CQuestion>(const std::string &, CAnswer *,
                                                                const std::vector<std::string> &)>>
        m_questionTypes = {
            {"text",
             [](const std::string &title, CAnswer *answer,
                [[maybe_unused]] const std::vector<std::string> &options)
             {
                 return std::make_shared<CTextQuestion>(title, answer);
             }},
            {"multi",
             [](const std::string &title, CAnswer *answer,
                const std::vector<std::string> &options)
             {
                 return std::make_shared<CMultiChoiceQuestion>(title, answer, options);
             }},
            {"single",
             [](const std::string &title, CAnswer *answer,
                const std::vector<std::string> &options)
             {
                 return std::make_shared<CSingleChoiceQuestion>(title, answer, options);
             }},
    };

    std::unordered_map<std::string,
                       std::function<CAnswer *(const std::vector<std::string> &)>>
        m_answerTypes = {
            {"text",
             [](const std::vector<std::string> &answers)
             {
                 return new CTextAnswer{
                     answers[0]};
             }},
            {"multi",
             [](const std::vector<std::string> &answers)
             {
                 return new CMultipleChoiceAnswer{
                     answers};
             }},
            {"interval",
             [](const std::vector<std::string> &answers)
             {
                 return new CIntervalAnswer{
                     answers[0]};
             }},
            {"T/F",
             [](const std::vector<std::string> &answers)
             {
                 return new CTrueFalseAnswer{
                     answers[0]};
             }}};

public:
    CXMLParser() {}
    explicit CXMLParser(const std::string &filePath);
    ~CXMLParser();
    std::shared_ptr<CQuiz> parse();

private:
    void setup(xmlParserCtxtPtr &context, xmlDocPtr &doc, xmlNodePtr &root);
    void getQuestions(xmlNodePtr &node, std::vector<std::shared_ptr<CQuestion>> &vec);
    void getOptions(xmlNodePtr &node, std::vector<std::string> &vec);
    void addToQuestVec(const std::string &questionType,
                       const std::string &questionTitle,
                       const std::string &answerType,
                       const std::vector<std::string> &answers,
                       const std::vector<std::string> &options, std::vector<std::shared_ptr<CQuestion>> &vec);
};