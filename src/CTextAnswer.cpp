#include "headers/answer/CTextAnswer.hpp"

CTextAnswer::CTextAnswer(const std::string &correctAnswer) : m_correctAnswer(correctAnswer) {}

std::string CTextAnswer::get_correctAnswer() const
{
    return m_correctAnswer;
}

std::string CTextAnswer::format_info() const
{
    std::stringstream ss;
    ss << "\033[1;36m[Your answer should be in text form]\033[0m ";
    return ss.str();
}

void CTextAnswer::set_userAnswer(const std::string &userAnswer)
{
    m_userAnswer = userAnswer;
}

bool CTextAnswer::format_error() const // if the answer is empty -> format error
{
    return m_userAnswer.size() == 0;
}

bool CTextAnswer::evaluate_answer()
{
    if (format_error())
    {
        throw std::invalid_argument("\033[1;31m[ERROR] Wrong format for text answer.\033[0m");
    }
    
    // convert both answers to lower case
    CAnswer::tolower(m_correctAnswer);
    CAnswer::tolower(m_userAnswer);
    return m_correctAnswer == m_userAnswer;
}