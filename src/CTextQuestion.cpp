#include "CTextQuestion.hpp"

CTextQuestion::CTextQuestion(const std::vector<std::string> &question, const std::set<std::string> &answers)
    : CQuestion(question, answers) {}

CTextQuestion::~CTextQuestion() {}

std::vector<std::string> CTextQuestion::get_question() const { return CQuestion::m_question; }

std::set<std::string> CTextQuestion::get_answers() const { return CQuestion::m_answer; }

void CTextQuestion::answer_question(const std::string &user_answer) { CQuestion::m_userAnswer = user_answer; }

bool CTextQuestion::evaluate_question() const
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