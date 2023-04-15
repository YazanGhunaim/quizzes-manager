#include "headers/question/CSingleChoiceQuestion.hpp"

// class CSingleChoiceQuestion
// {
// private:
//     std::vector<std::string> m_options;

// public:
//     CSingleChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options);
//     ~CSingleChoiceQuestion() override;
//     void display() override;
//     bool check_answer() const override;
//     void set_userAnswer(const std::string &answer) override;
// };

// constructor
CSingleChoiceQuestion::CSingleChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options)
    : CQuestion(question, answer), m_options(options) {}

// destructor
CSingleChoiceQuestion::~CSingleChoiceQuestion()
{
    delete m_answer;
}

void CSingleChoiceQuestion::display_options() const
{
    std::cout << "\nOptions: " << std::endl;
    for (size_t i = 0; i < m_options.size(); ++i)
    {
        std::cout << std::setw(5) << static_cast<unsigned char>('A' + i) << " : " << m_options[i] << std::endl;
    }
    std::cout << std::endl;
}
void CSingleChoiceQuestion::display()
{
    std::string user_answer;
    std::cout << "\033[33mQ: " << m_question << "\033[0m" << m_answer->format_info() << std::endl;
    display_options();
    std::cout << "\033[33mA: ";
    getline(std::cin, user_answer);
    std::cout << "\033[0m";
    set_userAnswer(user_answer);
}

bool CSingleChoiceQuestion::check_answer() const
{
    return m_answer->evaluate_answer();
}

void CSingleChoiceQuestion::set_userAnswer(const std::string &answer)
{
    if (answer.length() > 1)
    {
        m_answer->set_userAnswer(answer);
        return;
    }
    char cAnswer = answer[0];
    size_t index = static_cast<int>(std::toupper(cAnswer)) - static_cast<int>('A');
    m_answer->set_userAnswer(m_options[index]);
    return;
}