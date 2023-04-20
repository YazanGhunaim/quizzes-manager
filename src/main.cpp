#include <iostream>
#include "headers/answer/CTextAnswer.hpp"
#include "headers/answer/CIntervalAnswer.hpp"
#include "headers/answer/CTrueFalseAnswer.hpp"
#include "headers/answer/CMultipleChoiceAnswer.hpp"
#include "headers/question/CTextQuestion.hpp"
#include "headers/question/CSingleChoiceQuestion.hpp"
#include "headers/question/CMultiChoiceQuestion.hpp"

int main()
{
    std::cout << std::boolalpha;

    // correct use of single choice question
    CAnswer *answer1 = new CMultipleChoiceAnswer{std::vector<std::string>{"Joe Biden", "OSAMA BIN LADEN"}};
    CMultiChoiceQuestion questionMC1{"Who is currently the president of the United States?",
                                     answer1,
                                     std::vector<std::string>{"Joe Biden", "Barack Obama", "Osama Bin Laden", "Donald Trump"}};
    questionMC1.display();
    std::cout << questionMC1.check_answer() << std::endl;

    CAnswer *answer2 = new CIntervalAnswer{"1914-1918"};
    CMultiChoiceQuestion questionIA1{
        "when was WW1?",
        answer2,
        std::vector<std::string>{"1914-1918", "1915-1919", "1916-1920", "1917-1921"}};
    questionIA1.display();
    std::cout << questionIA1.check_answer() << std::endl;

    CAnswer *answer3 = new CTextAnswer{"yazan ghunaim"};
    CMultiChoiceQuestion questionT1{
        "who defeated the roman forces?",
        answer3,
        std::vector<std::string>{"mohammad salah", "yazan ghunaim", "idk someone roman", "mr bean"}};
    questionT1.display();
    std::cout << questionT1.check_answer() << std::endl;

    CAnswer *answer4 = new CTrueFalseAnswer{"true"};
    CMultiChoiceQuestion questionTF1{
        "was yazan him",
        answer4,
        std::vector<std::string>{"true", "false"}};
    questionTF1.display();
    std::cout << questionTF1.check_answer() << std::endl;

    return 0;
}
