#include "headers/answer/CTextAnswer.hpp"

CTextAnswer::CTextAnswer(const std::string &correctAnswer) : m_correctAnswer(correctAnswer) {}

std::string CTextAnswer::get_correctAnswer() const
{
    return m_correctAnswer;
}

std::string CTextAnswer::format_info() const
{
    std::stringstream ss;
    ss << " \033[36m[Your answer should be in text form]\033[0m ";
    return ss.str();
}

void CTextAnswer::set_userAnswer(const std::string &userAnswer)
{
    m_userAnswer = userAnswer;
}

bool CTextAnswer::format_error() const
{
    return m_userAnswer.size() == 0;
}

bool CTextAnswer::evaluate_answer()
{
    if (format_error())
    {
        std::cout << "[ERROR] Wrong format for T/F answer." << std::endl;
        throw std::invalid_argument("[ERROR] Wrong format for text answer.");
    }
    // convert both answers to lower case
    CAnswer::tolower(m_correctAnswer);
    CAnswer::tolower(m_userAnswer);
    return m_correctAnswer == m_userAnswer;
}