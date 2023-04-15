#include <iostream>
#include "headers/answer/CTextAnswer.hpp"
#include "headers/answer/CIntervalAnswer.hpp"
#include "headers/answer/CTrueFalseAnswer.hpp"
#include "headers/answer/CMultipleChoiceAnswer.hpp"
#include "headers/question/CTextQuestion.hpp"

int main()
{
    std::cout << std::boolalpha;

    // lets try having a text question with a text answer
    CAnswer *answer1 = new CTextAnswer{"Thomas Edison"};
    CTextQuestion questionTA{"Who invented the first light bulb?", answer1};
    questionTA.display();
    std::cout << questionTA.check_answer() << std::endl;

    // text question with interval answer
    CAnswer *answer2 = new CIntervalAnswer{"1914-1918"};
    CTextQuestion questionIA{"When did WW1 start and end?", answer2};
    questionIA.display();
    std::cout << questionIA.check_answer() << std::endl;

    // text question with true false answer
    CAnswer *answer3 = new CTrueFalseAnswer{"true"};
    CTextQuestion questionTF{"Did yazan pass BIE-PA1?", answer3};
    questionTF.display();
    std::cout << questionTF.check_answer() << std::endl;

    // text question with multiple choice answer
    CAnswer *answer4 = new CMultipleChoiceAnswer{std::vector<std::string>{"YazAn", "MohaNNad"}};
    CTextQuestion questionMC{"who two single handedly defeat dying light 2?", answer4};
    questionMC.display();
    std::cout << questionMC.check_answer() << std::endl;

    return 0;
}
