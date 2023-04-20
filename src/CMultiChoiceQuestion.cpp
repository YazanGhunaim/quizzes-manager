#include "headers/question/CMultiChoiceQuestion.hpp"

// constructor
CMultiChoiceQuestion::CMultiChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options)
    : CQuestion(question, answer)
{
    for (size_t i = 0; i < options.size(); ++i)
    {
        m_options[static_cast<unsigned char>('a' + i)] = options[i];
    }
}

// destructor
CMultiChoiceQuestion::~CMultiChoiceQuestion()
{
    delete m_answer;
}

void CMultiChoiceQuestion::display_options() const
{
    std::cout << "\nOptions: " << std::endl;
    for (const auto &[option, question] : m_options)
    {
        std::cout << std::setw(5) << option << " : " << question << std::endl;
    }
    std::cout << std::endl;
}
void CMultiChoiceQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[33mQ: " << m_question << "\033[0m\n" << m_answer->format_info() << std::endl;
    display_options();
    std::cout << "\033[33mA: ";
    getline(std::cin, user_answer);
    std::cout << "\033[0m";
    set_userAnswer(user_answer);
}

bool CMultiChoiceQuestion::check_answer() const
{
    return m_answer->evaluate_answer();
}

bool CMultiChoiceQuestion::format_error(const std::string &answer) const
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
        std::cout << "\033[31mInvalid answer format\033[0m" << std::endl;
        throw std::invalid_argument("[ERROR] Wrong format for multi choice question.");
        return;
    }

    m_answer->set_userAnswer(answer);
}
