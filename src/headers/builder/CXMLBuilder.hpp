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
#include <libxml/tree.h>

class CXMLBuilder
{
private:
    xmlNodePtr m_quizNode = NULL;
    xmlNodePtr m_currectSectionNode = NULL;
    xmlNodePtr m_currentQuestionNode = NULL;
    std::string m_title;

public:
    explicit CXMLBuilder(const std::string &title);
    std::string get_name() const;
    void add_section(const std::string &name);
    void add_question(const std::string &type, const std::string &text);
    void add_option(const std::string &text);
    void add_answer(const std::string &type, const std::vector<std::string> &answer_texts);
    void save_quiz(const std::string &filename);
};