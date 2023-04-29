#include "headers/manager/CManager.hpp"

CManager::CManager(const std::vector<std::shared_ptr<CQuiz>> &quizzes)
    : m_quizzes(quizzes) {}

CManager::~CManager() {}

size_t CManager::getQuizChoice() const
{
    std::string choiceStr;
    std::getline(std::cin, choiceStr);
    if (choiceStr.empty())
    {
        throw std::invalid_argument("\033[1;31m[ERROR]You must choose!\033[0m");
    }
    size_t choice = std::stoi(choiceStr) - 1;
    if (choice >= m_quizzes.size() || choice < 0)
    {
        throw std::invalid_argument("\033[1;31m[ERROR]Invalid choice!\033[0m");
    }
    return choice;
}
void CManager::display() const
{
    std::cout << "\n\033[1;36mWelcome to the quiz manager!\033[0m\n"
              << std::endl;
    std::cout << "\033[1;32mHere are the quizzes you can take:\033[0m" << std::endl;
    for (const auto &quiz : m_quizzes)
    {
        int index = &quiz - &m_quizzes[0] + 1;
        std::cout << "\033[1;33m" << index << "-" << quiz->getName() << "\033[0m" << std::endl;
    }
    std::cout << "\n\033[1;36mPlease enter the number of the quiz you would like to take:\033[0m ";

    try
    {
        int choice = getQuizChoice();
        m_quizzes[choice]->display();
        std::cout << "would yo like to evaluate" << std::endl;
        bool evaluate;
        std::cin >> evaluate;
        if (evaluate)
            m_quizzes[choice]->displayResults();
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        display();
    }
    catch (...)
    {
        std::cerr << "\033[1;31mSomething went wrong!\033[0m" << std::endl;
        display();
    }
}

void CManager::evaluate() const
{
    for (const auto &quiz : m_quizzes)
    {
        quiz->displayResults();
    }
}