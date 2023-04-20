#include "headers/question/CSingleChoiceQuestion.hpp"

// constructor
CSingleChoiceQuestion::CSingleChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options)
    : CQuestion(question, answer)
{
    if (answer->multiple_answers())
    {
        throw std::invalid_argument("[ERROR] Single choice question cannot have multiple answers.");
    }

    for (size_t i = 0; i < options.size(); ++i)
    {
        m_options[static_cast<unsigned char>('a' + i)] = options[i];
    }
}

// destructor
CSingleChoiceQuestion::~CSingleChoiceQuestion()
{
    delete m_answer;
}

void CSingleChoiceQuestion::display_options() const
{
    std::cout << "\nOptions: " << std::endl;
    for (const auto &[option, question] : m_options)
    {
        std::cout << std::setw(5) << option << " : " << question << std::endl;
    }
    std::cout << std::endl;
}

std::string CSingleChoiceQuestion::format_info() const
{
    std::stringstream ss;
    ss << "\033[36m[Please choose the correct option]\033[0m ";
    return ss.str();
}

void CSingleChoiceQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[33mQ: " << m_question << "\033[0m\n"
              << format_info() << std::endl;
    display_options();
    std::cout << "\033[33mA: ";
    getline(std::cin, user_answer);
    std::cout << "\033[0m";
    set_userAnswer(user_answer);
}

bool CSingleChoiceQuestion::check_answer() const
{
    return m_answer->evaluate_answer();
}

bool CSingleChoiceQuestion::format_error(const std::string &answer) const
{
    return answer.size() > 1 || m_options.find(answer[0]) == m_options.end();
}

void CSingleChoiceQuestion::set_userAnswer(const std::string &answer)
{
    if (format_error(answer))
    {
        std::cout << "\033[31mInvalid answer format\033[0m" << std::endl;
        throw std::invalid_argument("[ERROR] Wrong format for single choice question.");
        return;
    }
    m_answer->set_userAnswer(m_options.at(answer[0]));
}