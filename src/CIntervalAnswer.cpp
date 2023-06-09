#include "headers/answer/CIntervalAnswer.hpp"

CIntervalAnswer::CIntervalAnswer(const std::string &correctAnswer)
    : m_correctAnswer(std::move(correctAnswer)) {}

std::string CIntervalAnswer::get_correctAnswer() const
{
    return m_correctAnswer;
}

std::string CIntervalAnswer::format_info() const
{
    std::stringstream ss;
    ss << "\033[1;36m[Your answer should be in interval form (X-X)]\033[0m ";
    return ss.str();
}

void CIntervalAnswer::set_userAnswer(const std::string &userAnswer)
{
    m_userAnswer = userAnswer;
}

bool CIntervalAnswer::format_error() const // correct format would be X-X where X is a number
{
    int dashCount = std::count(m_userAnswer.begin(), m_userAnswer.end(), '-');
    return (m_userAnswer.size() < 3 || dashCount == 0 || dashCount > 1);
}

bool CIntervalAnswer::evaluate_answer()
{
    if (format_error())
    {
        throw std::invalid_argument("\033[1;31m[ERROR] Wrong format for interval answer.\033[0m");
    }

    // seperating the user answer into start and end
    std::string userAnswerStart = m_userAnswer.substr(0, m_userAnswer.find('-'));
    std::string userAnswerEnd = m_userAnswer.substr(m_userAnswer.find('-') + 1);

    // Check if the user answer is within the correct interval
    int userStart = std::stoi(userAnswerStart);
    int userEnd = std::stoi(userAnswerEnd);
    int correctStart = std::stoi(m_correctAnswer.substr(0, m_correctAnswer.find('-')));
    int correctEnd = std::stoi(m_correctAnswer.substr(m_correctAnswer.find('-') + 1));
    return (userStart == correctStart && userEnd == correctEnd);
}