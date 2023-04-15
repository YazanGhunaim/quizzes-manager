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
    std::cout << "Q: " << m_question << m_answer->format_info() << std::endl;
    std::cout << "A: ";
    getline(std::cin, user_answer);
    set_userAnswer(user_answer);
}

bool CTextQuestion::check_answer() const
{
    return m_answer->evaluate_answer();
}

void CTextQuestion::set_userAnswer(const std::string &answer)
{
    m_answer->set_userAnswer(answer);
    return;
}