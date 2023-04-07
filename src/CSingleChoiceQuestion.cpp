#include "CSingleChoiceQuestion.hpp"

CSingleChoiceQuestion::CSingleChoiceQuestion(const std::vector<std::string> &question,
                                             const std::set<std::string> &answers,
                                             int correctIndex)
    : CQuestion(question, answers), m_correctIndex(correctIndex) {}

CSingleChoiceQuestion::~CSingleChoiceQuestion() {}

std::vector<std::string> CSingleChoiceQuestion::get_question() const { return CQuestion::m_question; }

std::set<std::string> CSingleChoiceQuestion::get_answers() const { return CQuestion::m_answer; }

void CSingleChoiceQuestion::answer_question(const std::string &user_answer) { CQuestion::m_userAnswer = user_answer; }

bool CSingleChoiceQuestion::evaluate_question() const
{
    for (const auto &answer : CQuestion::m_answer)
    {
        if (CQuestion::m_userAnswer != answer)
        {
            return false;
        }
    }
    return true;
}