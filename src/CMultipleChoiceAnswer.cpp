#include "headers/answer/CMultipleChoiceAnswer.hpp"

CMultipleChoiceAnswer::CMultipleChoiceAnswer(const std::vector<std::string> &correctAnswers)
    : m_correctAnswers(correctAnswers) {}

std::string CMultipleChoiceAnswer::get_correctAnswer() const // iterates through the vector and returns a string consisting of all the correct answers separated by a space
{
    std::string correctAnswer;
    for (const auto &answer : m_correctAnswers)
    {
        correctAnswer += answer + " ";
    }
    return correctAnswer;
}

std::string CMultipleChoiceAnswer::format_info() const
{
    std::stringstream ss;
    ss << "\033[1;36m[Your answer should be in form (Option 1,Option 2,Option 3, ... etc )]\033[0m ";
    return ss.str();
}

void CMultipleChoiceAnswer::set_userAnswer(const std::string &userAnswer)
{
    std::stringstream ss{userAnswer}; // convert the string to a stringstream
    std::string answer;
    while (std::getline(ss, answer, ',')) // iterate through the stringstream and push each answer into the vector with a comma as a delimiter
    {
        m_userAnswer.push_back(answer);
    }
}

bool CMultipleChoiceAnswer::format_error() const
{
    return m_userAnswer.size() == 0;
}

bool CMultipleChoiceAnswer::evaluate_answer()
{
    if (format_error())
    {
        throw std::invalid_argument("\033[1;31m[ERROR] Wrong format for multiple choice answer.\033[0m");
    }

    if (m_correctAnswers.size() != m_userAnswer.size())
    {
        return false;
    }

    for (auto &str : m_correctAnswers)
    {
        CAnswer::tolower(str);
    }
    for (auto &str : m_userAnswer)
    {
        CAnswer::tolower(str);
    }

    // after converting strings to lower case and sorting them vector comparison is possible
    std::sort(m_correctAnswers.begin(), m_correctAnswers.end());
    std::sort(m_userAnswer.begin(), m_userAnswer.end());
    return m_correctAnswers == m_userAnswer;
}