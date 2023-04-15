#include "headers/question/CMultiChoiceQuestion.hpp"

// constructor
CMultiChoiceQuestion::CMultiChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options)
    : CQuestion(question, answer), m_options(options) {}

// destructor
CMultiChoiceQuestion::~CMultiChoiceQuestion()
{
    delete m_answer;
}

void CMultiChoiceQuestion::display_options() const
{
    std::cout << "\nOptions: " << std::endl;
    for (size_t i = 0; i < m_options.size(); ++i)
    {
        std::cout << std::setw(5) << static_cast<unsigned char>('A' + i) << " : " << m_options[i] << std::endl;
    }
    std::cout << std::endl;
}
void CMultiChoiceQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[33mQ: " << m_question << "\033[0m" << m_answer->format_info() << std::endl;
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

void CMultiChoiceQuestion::set_userAnswer(const std::string &answer)
{
    std::string finalAnswer;
    std::stringstream ss(answer);
    std::vector<std::string> userAnswers{std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>()};

    if (userAnswers.size() == 0)
    {
        m_answer->set_userAnswer(answer);
        return;
    }

    if (userAnswers[0].size() > 1)
    {
        m_answer->set_userAnswer(answer);
        return;
    }
    else // answer is of the form a b etc
    {
        for (const auto &ans : userAnswers)
        {
            char cAnswer = ans[0];
            size_t index = static_cast<int>(std::toupper(cAnswer)) - static_cast<int>('A');
            if (!finalAnswer.empty())
            {
                finalAnswer += " ";
            }
            finalAnswer += m_options[index];
        }
        m_answer->set_userAnswer(finalAnswer);
    }
}
