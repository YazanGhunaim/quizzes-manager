#include "headers/section/CSection.hpp"

CSection::CSection(const std::string &name, const std::vector<std::shared_ptr<CQuestion>> &questions)
    : m_name(name), m_questions(questions) {}

CSection::~CSection()
{
}

int CSection::getScore() const
{
    return m_score;
}

int CSection::totalQuestions() const
{
    return m_questions.size();
}

std::string CSection::getName() const
{
    return m_name;
}

void CSection::display()
{
    std::cout << "Section: " << m_name << std::endl;
    for (auto &question : m_questions)
    {
        while (true)
        {
            try
            {
                question->display();
                if (question->check_answer())
                {
                    std::cout << "\033[1;32mCorrect!\033[0m\n"
                              << std::endl;
                    m_score += 1;
                }
                else
                    std::cout << "\033[1;31mIncorrect!\033[0m\n"
                              << std::endl;
                break;
            }
            // my exception is std::invalid_argument
            catch (std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                std::cout << "\033[1m>Please try again<\033[0m\n"
                          << std::endl;
            }
        }
    }
}

void CSection::displayResults() const
{
    std::cout << "\033[1;36mSection: " << m_name << std::endl;
    std::cout << "Score: " << m_score << "/" << m_questions.size() << "\033[0;0m" << std::endl;
}
