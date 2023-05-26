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
    explicit CXMLBuilder(const std::string &title) : m_title(title)
    {
        // Create the top-level quiz node
        xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
        m_quizNode = xmlNewNode(NULL, BAD_CAST "quiz");
        xmlNewProp(m_quizNode, BAD_CAST "title", BAD_CAST title.c_str());
        xmlDocSetRootElement(doc, m_quizNode);
    }

    std::string get_name() const
    {
        return m_title;
    }

    void add_section(const std::string &name)
    {
        // Add a new section to the quiz
        xmlNodePtr section_node = xmlNewChild(m_quizNode, NULL, BAD_CAST "section", NULL);
        xmlNewProp(section_node, BAD_CAST "title", BAD_CAST name.c_str());

        // Update the current section pointer
        m_currectSectionNode = section_node;
    }

    void add_question(const std::string &type, const std::string &text)
    {
        // Add a new question to the current section
        xmlNodePtr question_node = xmlNewChild(m_currectSectionNode, NULL, BAD_CAST "question", NULL);
        xmlNewProp(question_node, BAD_CAST "type", BAD_CAST type.c_str());

        // Add the question text
        xmlNodePtr text_node = xmlNewChild(question_node, NULL, BAD_CAST "text", BAD_CAST text.c_str());

        // Update the current question pointer
        m_currentQuestionNode = question_node;
    }

    void add_option(const std::string &text)
    {
        // Add a new option to the current question
        xmlNodePtr options_node = xmlNewChild(m_currentQuestionNode, NULL, BAD_CAST "options", NULL);
        xmlNodePtr text_node = xmlNewChild(options_node, NULL, BAD_CAST "text", BAD_CAST text.c_str());
    }

    void add_answer(const std::string &type, const std::vector<std::string> &answer_texts)
    {
        // Add a new answer to the current question
        xmlNodePtr answer_node = xmlNewChild(m_currentQuestionNode, NULL, BAD_CAST "answer", NULL);
        xmlNewProp(answer_node, BAD_CAST "type", BAD_CAST type.c_str());

        // Add each answer text as a separate node
        for (const auto &answer_text : answer_texts)
        {
            xmlNodePtr text_node = xmlNewChild(answer_node, NULL, BAD_CAST "text", BAD_CAST answer_text.c_str());
        }
    }

    void save_quiz(const std::string &filename)
    {
        // Determine the full path to the output file
        std::string file_path = "src/xml/" + filename;

        // Save the quiz to an XML file at the specified location
        xmlSaveFormatFileEnc(file_path.c_str(), m_quizNode->doc, "UTF-8", 1);
        xmlFreeDoc(m_quizNode->doc);
        xmlCleanupParser();
    }
};