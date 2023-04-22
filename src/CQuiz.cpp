#include "headers/quiz/CQuiz.hpp"

CQuiz::CQuiz(const std::string &name, const std::vector<std::shared_ptr<CSection>> &sections)
    : m_name(name), m_sections(sections) {}

CQuiz::~CQuiz() {}

int CQuiz::getScore() const
{
    return m_score;
}

int CQuiz::totalSections() const
{
    return m_sections.size();
}

int CQuiz::totalQuestions() const
{
    int total = 0;
    for (auto &section : m_sections)
    {
        total += section->totalQuestions();
    }
    return total;
}

std::string CQuiz::getName() const
{
    return m_name;
}
void CQuiz::intro() const
{
    std::cout << "         \033[1;35mWelcome to " << getName() << std::endl;
    std::cout << "There are " << totalSections() << " sections and " << totalQuestions() << " questions in total." << std::endl;
    std::cout << "    👀 Let's see how much you know! 👀\033[0m\n"
              << std::endl;
}

void CQuiz::display()
{
    intro();
    for (auto &section : m_sections)
    {
        section->display();
        m_score += section->getScore();
    }
}

void CQuiz::displayResults() const
{
    float percentage = static_cast<float>(m_score) / totalQuestions() * 100;

    if (percentage >= 80)
        std::cout << "\033[1;32mCongratulations! You scored " << percentage << "%. Great job!\033[0m" << std::endl;
    else if (percentage >= 50)
        std::cout << "\033[1;33mGood effort! You scored " << percentage << "%. Keep it up!\033[0m" << std::endl;
    else
        std::cout << "\033[1;31mSorry, you scored " << percentage << "%. Better luck next time.\033[0m" << std::endl;
}
