#include "headers/question/CSingleChoiceQuestion.hpp"

CSingleChoiceQuestion::CSingleChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options)
    : CQuestion(question, answer)
{
    if (answer->multiple_answers())
    {
        throw std::invalid_argument("\033[1;31m[ERROR] Single choice question cannot have multiple answers.\033[0m");
    }

    for (size_t i = 0; i < options.size(); ++i) // converting the vector of options to a map of options
    {
        m_options[static_cast<unsigned char>('a' + i)] = options[i];
    }
}

CSingleChoiceQuestion::~CSingleChoiceQuestion()
{
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
    ss << "\033[1;36m[Please choose the correct option]\033[0m ";
    return ss.str();
}

void CSingleChoiceQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[1;33mQ: " << m_question << "\033[0m\n" << format_info() << std::endl;
    display_options();
    std::cout << "\033[33mA: ";
    getline(std::cin, user_answer);
    std::cout << "\033[0m";
    set_userAnswer(user_answer);
}

bool CSingleChoiceQuestion::check_answer() const
{
    return m_answer->evaluate_answer(); // uses answer's evaluate method
}

bool CSingleChoiceQuestion::format_error(const std::string &answer) const
{
    return answer.size() > 1 || m_options.find(answer[0]) == m_options.end(); // if the options doesnt exist or no answer is given
}

void CSingleChoiceQuestion::set_userAnswer(const std::string &answer)
{
    if (format_error(answer))
    {
        throw std::invalid_argument("\033[1;31m[ERROR] Wrong format for single choice question.\033[0m");
        return;
    }
    m_answer->set_userAnswer(m_options.at(answer[0])); // uses answer's set_userAnswer method with the correct answer to the key
}