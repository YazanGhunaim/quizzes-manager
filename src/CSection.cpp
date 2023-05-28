#include "headers/section/CSection.hpp"

CSection::CSection(const std::string &name, const std::vector<std::shared_ptr<CQuestion>> &questions)
    : m_name(name), m_questions(questions), m_status(false) {}

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

bool CSection::getStatus() const
{
    return m_status;
}

void CSection::setStatus(const bool status)
{
    m_status = status;
}

/*
    This is the main function of the section.
    It displays the questions of the section and checks the answers.
    This uses polymorphism to display the questions and to check the answers.
*/
void CSection::display()
{
    std::cout << "\033[46mSection: " << getName() << std::endl;
    std::cout << "\033[0m" << std::endl;
    for (auto &question : m_questions)
    {
        // question is continuosly displayed until the user enters a valid answer
        while (true)
        {
            try
            {
                question->display();
                if (question->check_answer())
                {
                    std::cout << "\033[1;32mCorrect!\033[0m\n" << std::endl;
                    m_score += 1;
                }
                else
                    std::cout << "\033[1;31mIncorrect!\033[0m\n" << std::endl;
                break;
            }
            catch (std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                std::cout << "\033[1m>Please try again<\033[0m\n" << std::endl;
            }
        }
    }
}

void CSection::displayResults() const
{
    std::cout << "\033[1;36mSection: " << getName() << std::endl;
    std::cout << "Score: " << getScore() << "/" << totalQuestions() << "\033[0;0m" << std::endl;
}
