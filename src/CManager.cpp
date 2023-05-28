#include "headers/manager/CManager.hpp"
#include <limits>
#include <algorithm>

CManager::CManager()
{
    // Get all xml files in src/xml directory
    const std::string dirPath = "src/xml";
    for (const auto &entry : std::filesystem::directory_iterator(dirPath))
    {
        if (entry.is_regular_file())
        {
            m_filePaths.push_back(entry.path().string());
        }
    }

    // Parse all xml files
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
    std::string name;
    std::getline(std::cin, name);
    while (name.empty())
    {
        std::cout << "\033[1;31m[ERROR]You must enter a name!\033[0m" << std::endl;
        std::getline(std::cin, name);
    }
    return name;
}

void CManager::getCorrectAnswer(std::vector<std::string> &vec, bool prompt) const
{
    if (!prompt)
    {
        std::cout << "\033[1;32mPlease enter the correct answer:\033[0m ";
        std::string answer;
        std::getline(std::cin, answer);
        while (answer.empty())
        {
            std::cout << "\033[1;31m[ERROR]You must enter an answer!\033[0m" << std::endl;
            std::getline(std::cin, answer);
        }
        vec.push_back(answer);
    }
    else
    {
        std::cout << "\033[1;32mPlease enter the number of correct answer:\033[0m ";
        int number;
        while (!(std::cin >> number) || number < 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer up to and including newline
            std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a positive integer:\033[0m ";
        }
        std::cin.ignore();

        for (int i = 0; i < number; ++i)
        {
            std::cout << "\033[1;32m\nPlease enter correct answer number " << i + 1 << ":\033[0m ";
            std::string answer;
            std::getline(std::cin, answer);
            while (answer.empty())
            {
                std::cout << "\033[1;31m[ERROR]You must enter an answer!\033[0m" << std::endl;
                std::getline(std::cin, answer);
            }
            vec.push_back(answer);
        }
    }
}

void CManager::answers(CXMLBuilder &builder, bool single) const
{
    if (single) // no multiple answers for single choice questions
    {
        std::cout << std::endl;
        std::cout << "\033[1;32mSpecify type of answer\033[0m" << std::endl;
        std::cout << "\033[1;33m1-Interval Answer\033[0m" << std::endl;
        std::cout << "\033[1;33m2-Text Answer\033[0m" << std::endl;
        std::cout << "\033[1;33m3-True False Answer\033[0m" << std::endl;

        std::cout << "\033[1;32mPlease enter the type of answer: \033[0m ";
        int answerType = 0;
        while (!(std::cin >> answerType) || answerType < 1 || answerType > 3) // loop until an integer is entered
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer up to and including newline
            std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a positive integer:\033[0m ";
        }
        std::cin.ignore();

        std::vector<std::string> correctAnswer;
        switch (answerType)
        {
        case 1:
            getCorrectAnswer(correctAnswer);
            builder.add_answer("interval", correctAnswer);
            break;
        case 2:
            getCorrectAnswer(correctAnswer);
            builder.add_answer("text", correctAnswer);
            break;
        case 3:
            getCorrectAnswer(correctAnswer);
            builder.add_answer("T/F", correctAnswer);
            break;
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "\033[1;32mSpecify type of answer\033[0m" << std::endl;
        std::cout << "\033[1;33m1-Interval Answer\033[0m" << std::endl;
        std::cout << "\033[1;33m2-Multiple Answers\033[0m" << std::endl;
        std::cout << "\033[1;33m3-Text Answer\033[0m" << std::endl;
        std::cout << "\033[1;33m4-True False Answer\033[0m" << std::endl;

        std::cout << "\033[1;32mPlease enter the type of answer: \033[0m ";
        int answerType = 0;
        while (!(std::cin >> answerType) || answerType < 1 || answerType > 4) // loop until an integer is entered
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer up to and including newline
            std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a positive integer:\033[0m ";
        }
        std::cin.ignore();

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
}

void CManager::textQuestion(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the question:\033[0m";
    std::string question;
    std::getline(std::cin, question);
    while (question.empty())
    {
        std::cout << "\033[1;31m[ERROR]You must enter a question!\033[0m" << std::endl;
        std::getline(std::cin, question);
    }
    builder.add_question("text", question);
    answers(builder);
}

void CManager::singleQuestion(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the question:\033[0m ";
    std::string question;
    std::getline(std::cin, question);
    while (question.empty())
    {
        std::cout << "\033[1;31m[ERROR]You must enter a question!\033[0m" << std::endl;
        std::getline(std::cin, question);
    }
    builder.add_question("single", question);
    options(builder);
    answers(builder, true);
}

void CManager::multiQuestion(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the question:\033[0m ";
    std::string question;
    std::getline(std::cin, question);
    while (question.empty())
    {
        std::cout << "\033[1;31m[ERROR]You must enter a question!\033[0m" << std::endl;
        std::getline(std::cin, question);
    }
    builder.add_question("multi", question);
    options(builder);
    answers(builder);
}

void CManager::options(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the number of options you would like to add:\033[0m ";
    int options = 1;
    while (!(std::cin >> options) || options < 1)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a positive integer:\033[0m ";
    }
    std::cin.ignore();

    for (int i = 0; i < options; ++i)
    {
        std::cout << "\033[1;32m\nPlease enter option number " << i + 1 << ":\033[0m ";
        std::string option;
        std::getline(std::cin, option);
        while (option.empty())
        {
            std::cout << "\033[1;31m[ERROR]You must enter a option!\033[0m" << std::endl;
            std::getline(std::cin, option);
        }
        builder.add_option(option);
    }
}

void CManager::questions(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the number of questions you would like to add:\033[0m ";
    int questions = 1;
    while (!(std::cin >> questions) || questions < 1) // loop until an integer is entered
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer up to and including newline
        std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a positive integer:\033[0m ";
    }
    std::cin.ignore();
    for (int i = 0; i < questions; ++i)
    {
        std::cout << std::endl;
        std::cout << "\033[1;32mSpecify type of question " << i + 1 << ":\033[0m" << std::endl;
        std::cout << "\033[1;33m1-Single Choice\033[0m" << std::endl;
        std::cout << "\033[1;33m2-Multiple Choice\033[0m" << std::endl;
        std::cout << "\033[1;33m3-Text\033[0m" << std::endl;

        std::cout << "\033[1;32mPlease enter the number of question type: \033[0m ";
        int questionType = 0;
        while (!(std::cin >> questionType) || questionType > 3 || questionType < 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer up to and including newline
            std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a valid positive integer:\033[0m ";
        }
        std::cin.ignore();

        if (questionType == 1)
            singleQuestion(builder);
        else if (questionType == 2)
            multiQuestion(builder);
        else
            textQuestion(builder);
    }
}

void CManager::sections(CXMLBuilder &builder) const
{
    std::cout << "\033[1;32mPlease enter the number of sections you would like to add:\033[0m ";
    int sections = 1;
    while (!(std::cin >> sections) || sections < 1) // loop until an integer is entered
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer up to and including newline
        std::cout << "\033[1;31m[ERROR]Invalid input! Please enter a positive integer:\033[0m ";
    }
    std::cin.ignore();
    if (sections <= 0)
    {
        throw std::invalid_argument("\033[1;31m[ERROR]Invalid number of sections!\033[0m");
    }

    for (int i = 0; i < sections; ++i)
    {
        std::cout << "\033[1;32m\nPlease enter the name of section " << i + 1 << ":\033[0m ";
        builder.add_section(getSectionName());
        questions(builder);
    }
}

void CManager::build() const
{
    std::cout << "\n\033[1;36mWelcome to the quiz builder!\033[0m" << std::endl;
    std::string name;
    try
    {
        name = getQuizName();
        CXMLBuilder builder{name};
        sections(builder);
        builder.save_quiz(builder.get_name() + ".xml");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        build();
    }
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
