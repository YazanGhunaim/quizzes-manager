#include "headers/question/CMultiChoiceQuestion.hpp"

CMultiChoiceQuestion::CMultiChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options)
    : CQuestion(question, answer)
{
    for (size_t i = 0; i < options.size(); ++i) // converting the vector of options to a map of options with key being a letter
    {
        m_options[static_cast<unsigned char>('a' + i)] = options[i];
    }
}

CMultiChoiceQuestion::~CMultiChoiceQuestion() {}

void CMultiChoiceQuestion::display_options() const
{
    std::cout << "\nOptions: " << std::endl;
    for (const auto &[option, question] : m_options)
    {
        std::cout << std::setw(5) << option << " : " << question << std::endl;
    }
    std::cout << std::endl;
}

std::string CMultiChoiceQuestion::format_info() const
{
    std::stringstream ss;
    ss << "\033[1;36m[Please choose the correct options]\033[0m ";
    return ss.str();
}

void CMultiChoiceQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[1;33mQ: " << m_question << "\033[0m\n" << format_info() << std::endl;
    display_options();
    std::cout << "\033[33mA: ";
    getline(std::cin, user_answer);
    std::cout << "\033[0m";
    set_userAnswer(user_answer);
}

bool CMultiChoiceQuestion::check_answer() const
{
    return m_answer->evaluate_answer(); // uses answer's evaluate method
}

bool CMultiChoiceQuestion::format_error(const std::string &answer) const // if the options doesnt exist or no answer is given
{
    for (const auto &c : answer)
    {
        if (c != ' ')
        {
            if (m_options.find(c) == m_options.end())
            {
                return true;
            }
        }
    }
    return false;
}

void CMultiChoiceQuestion::set_userAnswer(const std::string &answer)
{
    if (format_error(answer))
    {
        throw std::invalid_argument("\033[1;31m[ERROR] Wrong format for multi choice question.\033[0m");
    }

    std::string user_answer;
    for (const auto &c : answer)
    {
        if (c != ' ')
        {
            if (!user_answer.empty())
            {
                user_answer += ",";
            }
            user_answer += m_options.at(c);
        }
    }
    m_answer->set_userAnswer(user_answer); // uses answer's set_userAnswer method
}
