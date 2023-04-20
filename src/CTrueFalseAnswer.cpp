#include "headers/answer/CTrueFalseAnswer.hpp"

CTrueFalseAnswer::CTrueFalseAnswer(const std::string correctAnswer) : m_correctAnswer(correctAnswer) {}

std::string CTrueFalseAnswer::get_correctAnswer() const
{
    return m_correctAnswer;
}

std::string CTrueFalseAnswer::format_info() const
{
    std::stringstream ss;
    ss << "\033[36m[Your answer should be True/False]\033[0m ";
    return ss.str();
}

void CTrueFalseAnswer::set_userAnswer(const std::string &userAnswer)
{
    m_userAnswer = userAnswer;
}

bool CTrueFalseAnswer::format_error() const
{
    return m_userAnswer != "true" && m_userAnswer != "false";
}

bool CTrueFalseAnswer::evaluate_answer()
{
    CAnswer::tolower(m_userAnswer);
    CAnswer::tolower(m_correctAnswer);

    if (format_error())
    {
        std::cout << "\033[31m[ERROR] Wrong format for T/F answer.\033[0m" << std::endl;
        throw std::invalid_argument("[ERROR] Wrong format for T/F answer.");
    }
    return m_userAnswer == m_correctAnswer;
}
