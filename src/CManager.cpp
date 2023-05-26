#include "headers/manager/CManager.hpp"

CManager::CManager(const std::vector<std::string> &filePaths)
    : m_filePaths(filePaths)
{
    for (const auto &filePath : m_filePaths)
    {
        m_parser = CXMLParser{filePath};
        m_quizzes.push_back(m_parser.parse());
    }
}

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
    if (choice > m_quizzes.size() || choice < 0)
    {
        throw std::invalid_argument("\033[1;31m[ERROR]Invalid choice!\033[0m");
    }
    return choice;
}

std::string CManager::getQuizName() const
{
    std::cout << "\033[1;32mPlease enter the name of your quiz:\033[0m ";
    std::string name;
    std::getline(std::cin, name);
    if (name.empty())
    {
        throw std::invalid_argument("\033[1;31m[ERROR]You must enter a name!\033[0m");
    }
    return name;
}

std::string CManager::getSectionName() const
{
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    if (name.empty())
    {
        throw std::invalid_argument("\033[1;31m[ERROR]You must enter a name!\033[0m");
    }
    return name;
}

void CManager::getCorrectAnswer(std::vector<std::string> &vec, bool prompt) const
{
    if (!prompt)
    {
        std::cout << "\033[1;32mPlease enter the correct answer:\033[0m ";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer.empty())
        {
            throw std::invalid_argument("\033[1;31m[ERROR]You must enter an answer!\033[0m");
        }
        vec.push_back(answer);
    }
    else
    {
        std::cout << "\033[1;32mPlease enter the number of correct answer:\033[0m ";
        int number;
        std::cin >> number;
        if (number <= 0)
        {
            throw std::invalid_argument("\033[1;31m[ERROR]You must enter a number!\033[0m");
        }
        for (int i = 0; i < number; ++i)
        {
            std::cout << "\033[1;32mPlease enter the correct answer:\033[0m ";
            std::string answer;
            std::cin.ignore();
            std::getline(std::cin, answer);
            if (answer.empty())
            {
                throw std::invalid_argument("\033[1;31m[ERROR]You must enter an answer!\033[0m");
            }
            vec.push_back(answer);
        }
    }
}

void CManager::answers(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mSpecify type of answer\033[0m" << std::endl;
    std::cout << "\033[1;33m1-Interval Answer\033[0m" << std::endl;
    std::cout << "\033[1;33m2-Multiple Answers\033[0m" << std::endl;
    std::cout << "\033[1;33m3-Text Answer\033[0m" << std::endl;
    std::cout << "\033[1;33m4-True False Answer\033[0m" << std::endl;

    std::cout << "\033[1;32mPlease enter the type of answer: \033[0m ";
    int answerType = 0;
    std::cin >> answerType;
    if (answerType <= 0 || answerType > 4)
    {
        throw std::invalid_argument("\033[1;31m[ERROR]Invalid answer type!\033[0m");
    }

    std::vector<std::string> correctAnswer;
    switch (answerType)
    {
    case 1:
        getCorrectAnswer(correctAnswer);
        builder.add_answer("interval", correctAnswer);
        break;
    case 2:
        getCorrectAnswer(correctAnswer, true);
        builder.add_answer("multi", correctAnswer);
        break;
    case 3:
        getCorrectAnswer(correctAnswer);
        builder.add_answer("text", correctAnswer);
        break;
    case 4:
        getCorrectAnswer(correctAnswer);
        builder.add_answer("T/F", correctAnswer);
        break;
    }
}

void CManager::textQuestion(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the question:\033[0m ";
    std::string question;
    std::cin.ignore();
    std::getline(std::cin, question);
    if (question.empty())
    {
        throw std::invalid_argument("\033[1;31m[ERROR]You must enter a question!\033[0m");
    }
    builder.add_question("text", question);
    answers(builder);
}

void CManager::questions(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the number of questions you would like to add:\033[0m ";
    int questions;
    std::cin >> questions;
    if (questions <= 0)
    {
        throw std::invalid_argument("\033[1;31m[ERROR]Invalid number of questions!\033[0m");
    }

    for (int i = 0; i < questions; ++i)
    {
        std::cout << "\033[1;32mSpecify type of question" << i + 1 << ":\033[0m" << std::endl;
        std::cout << "\033[1;33m1-Single Choice\033[0m" << std::endl;
        std::cout << "\033[1;33m2-Multiple Choice\033[0m" << std::endl;
        std::cout << "\033[1;33m3-Text\033[0m" << std::endl;

        std::cout << "\033[1;32mPlease enter the number of question type: \033[0m ";
        int questionType = 0;
        std::cin.ignore();
        std::cin >> questionType;
        if (questionType <= 0 || questionType > 3)
        {
            throw std::invalid_argument("\033[1;31m[ERROR]Invalid question type!\033[0m");
        }

        if (questionType == 3)
        {
            textQuestion(builder);
        }
    }
}

void CManager::sections(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the number of sections you would like to add:\033[0m ";
    int sections;
    std::cin >> sections;
    if (sections <= 0)
    {
        throw std::invalid_argument("\033[1;31m[ERROR]Invalid number of sections!\033[0m");
    }

    for (int i = 0; i < sections; ++i)
    {
        std::cout << "\033[1;32mPlease enter the name of section " << i + 1 << ":\033[0m ";
        builder.add_section(getSectionName());
        questions(builder);
    }
}

void CManager::build() const
{
    std::cout << "\n\033[1;36mWelcome to the quiz builder!\033[0m" << std::endl;
    std::string name = getQuizName();
    CXMLBuilder builder{name};
    sections(builder);
    builder.save_quiz(builder.get_name() + ".xml");
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
    std::cout << "\033[1;33m" << m_quizzes.size() + 1 << "-Create your own quiz\033[0m" << std::endl;
    std::cout << "\n\033[1;36mPlease enter the number of the quiz you would like to take:\033[0m ";

    try
    {
        int choice = getQuizChoice();
        if (choice == (int)m_quizzes.size()) // create own quiz
        {
            build();
        }
        else
        {
            m_quizzes[choice]->display();
            m_quizzes[choice]->displayResults();
        }
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

void CManager::run() const
{
    display();
}
