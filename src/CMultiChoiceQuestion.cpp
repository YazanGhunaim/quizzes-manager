#include "CMultiChoiceQuestion.hpp"

CMultiChoiceQuestion::CMultiChoiceQuestion(const std::vector<std::string> &question,
                                           const std::set<std::string> &answers,
                                           const std::vector<int> &correct_indices)
    : CQuestion(question, answers), m_correctIndices(correct_indices) {}

CMultiChoiceQuestion::~CMultiChoiceQuestion() {}

std::vector<std::string> CMultiChoiceQuestion::get_question() const { return CQuestion::m_question; }

std::set<std::string> CMultiChoiceQuestion::get_answers() const { return CQuestion::m_answer; }

void CMultiChoiceQuestion::answer_question(const std::string &user_answer) { CQuestion::m_userAnswer = user_answer; }

bool CMultiChoiceQuestion::evaluate_question() const
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