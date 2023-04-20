#include "headers/answer/CMultipleChoiceAnswer.hpp"

CMultipleChoiceAnswer::CMultipleChoiceAnswer(const std::vector<std::string> &correctAnswers)
    : m_correctAnswers(correctAnswers) {}

std::string CMultipleChoiceAnswer::get_correctAnswer() const
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
    ss << " \033[36m[Your answer should be in form (Option 1 Option 2 Option 3 ... etc )]\033[0m ";
    return ss.str();
}

void CMultipleChoiceAnswer::set_userAnswer(const std::string &userAnswer)
{
    std::stringstream ss{userAnswer};
    std::vector<std::string> userAnswer_vec{std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>()};
    m_userAnswer = userAnswer_vec;
}

bool CMultipleChoiceAnswer::format_error() const
{
    return m_userAnswer.size() == 0;
}

bool CMultipleChoiceAnswer::evaluate_answer()
{
    if (format_error())
    {
        std::cout << "\033[31m[ERROR] Wrong format for multiple choice answer.\033[0m" << std::endl;
        throw std::invalid_argument("[ERROR] Wrong format for multiple choice answer.");
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

    std::sort(m_correctAnswers.begin(), m_correctAnswers.end());
    std::sort(m_userAnswer.begin(), m_userAnswer.end());
    return m_correctAnswers == m_userAnswer;
}