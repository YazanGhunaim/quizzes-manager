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
    // WHILE WE SHOULD ANSWER WITH FORMAT a or b WE SHOULD PASS THE ANSWER AS A STRING to the set_userAnswer() method
    std::cout << std::boolalpha;

    // correct use of single choice question
    CAnswer *answer1 = new CMultipleChoiceAnswer{std::vector<std::string>{"a"}};
    CSingleChoiceQuestion questionMC1{"Who is currently the president of the United States?",
                                      answer1,
                                      std::vector<std::string>{"Joe Biden", "Barack Obama", "Osama Bin Laden", "Donald Trump"}};
    questionMC1.display();
    std::cout << questionMC1.check_answer() << std::endl;

    // should prompt error trying to use single choice question with multiple answers
    CAnswer *answer2 = new CMultipleChoiceAnswer{std::vector<std::string>{"a"}};
    CSingleChoiceQuestion questionMC2{"Who is currently the president of the United States?",
                                      answer2,
                                      std::vector<std::string>{"Joe Biden", "Barack Obama", "Osama Bin Laden", "Donald Trump"}};
    questionMC2.display();
    std::cout << questionMC2.check_answer() << std::endl;

    CAnswer *answer3 = new CIntervalAnswer{"1914-1918"};
    CSingleChoiceQuestion questionIA1{
        "when was WW1?",
        answer3,
        std::vector<std::string>{"1914-1918", "1915-1919", "1916-1920", "1917-1921"}};
    questionIA1.display();
    std::cout << questionIA1.check_answer() << std::endl;

    return 0;
}
