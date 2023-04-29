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

void CQuiz::validSectionChoice(const std::string &choice)
{
    if (choice.empty())
    {
        throw std::invalid_argument("\033[1;31mYou must choose!\033[0m");
    }
    size_t choiceID = std::stoi(choice) - 1;
    if (choiceID >= m_sections.size() || choiceID < 0 || m_sections[choiceID]->getStatus() == true)
    {
        throw std::invalid_argument("\033[1;31mInvalid choice!\033[0m");
    }
    std::cout << std::endl;
    m_sections[choiceID]->display();
    m_sections[choiceID]->setStatus(true);
    m_score += m_sections[choiceID]->getScore();
}

void CQuiz::sectionChoice()
{
    std::cout << "\033[1mChoose a section: \033[0m" << std::endl;
    std::string strChoice;
    for (size_t i = 0; i < m_sections.size(); ++i)
    {
        if (m_sections[i]->getStatus() == false)
            std::cout << "\033[1;33m" << i + 1 << ". " << m_sections[i]->getName()
                      << " (consists of " << m_sections[i]->totalQuestions()
                      << " total questions)\033[0m" << std::endl;
    }
    std::cout << "\033[1mSection: \033[0m";
    std::getline(std::cin, strChoice);
    validSectionChoice(strChoice);
}

void CQuiz::sectionChoiceView()
{
    sectionChoice();
}

void CQuiz::intro() const
{
    std::cout << std::endl;
    std::cout << "         \033[1;35mWelcome to " << getName() << std::endl;
    std::cout << "There are " << totalSections() << " sections and " << totalQuestions() << " questions in total." << std::endl;
    std::cout << "    👀 Let's see how much you know! 👀\033[0m\n"
              << std::endl;
}

bool CQuiz::checkStatus()
{
    for (const auto &sec : m_sections)
    {
        if (sec->getStatus() == false)
        {
            return false;
        }
    }
    m_status = true;
    return true;
}

void CQuiz::display()
{
    intro();
    while (checkStatus() == false)
    {
        try
        {
            sectionChoice();
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch (...)
        {
            std::cerr << "Unknown error" << std::endl;
        }
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
