#include "headers/question/CTextQuestion.hpp"

// constructor
CTextQuestion::CTextQuestion(const std::string &question, CAnswer *answer)
    : CQuestion(question, answer) {}

// destructor
CTextQuestion::~CTextQuestion()
{
    delete m_answer;
}

void CTextQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[33mQ: " << m_question << "\033[0m\n" << m_answer->format_info() << std::endl;
    std::cout << "\033[33mA: ";
    getline(std::cin, user_answer);
    std::cout << "\033[0m";
    set_userAnswer(user_answer);
}

bool CTextQuestion::check_answer() const
{
    return m_answer->evaluate_answer();
}

bool CTextQuestion::format_error(const std::string &answer) const
{
    return answer.empty();
}

void CTextQuestion::set_userAnswer(const std::string &answer)
{
    m_answer->set_userAnswer(answer);
    return;
}