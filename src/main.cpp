#include <iostream>
#include "headers/answer/CTextAnswer.hpp"
#include "headers/answer/CIntervalAnswer.hpp"
#include "headers/answer/CTrueFalseAnswer.hpp"
#include "headers/answer/CMultipleChoiceAnswer.hpp"
#include "headers/question/CTextQuestion.hpp"
#include "headers/question/CSingleChoiceQuestion.hpp"

int main()
{
    std::cout << std::boolalpha;

    // lets try having a text question with a text answer
    CAnswer *answer1 = new CTextAnswer{"Thomas Edison"};
    CSingleChoiceQuestion questionTA{"Who invented the first light bulb?", answer1, std::vector<std::string>{"Thomas Edison", "Nikola Tesla", "Adolf Hitler"}};
    questionTA.display();
    std::cout << questionTA.check_answer() << std::endl;

    // text question with interval answer
    CAnswer *answer2 = new CIntervalAnswer{"1914-1918"};
    CSingleChoiceQuestion questionIA{"When did WW1 start and end?", answer2, std::vector<std::string>{"2030-2321", "1914-1918", "1913-1919"}};
    questionIA.display();
    std::cout << questionIA.check_answer() << std::endl;

    // text question with true false answer
    CAnswer *answer3 = new CTrueFalseAnswer{"true"};
    CSingleChoiceQuestion questionTF{"Is one of these statements correct", answer3, std::vector<std::string>{"Yazan passed Pa1", "Elon Musk is secretly batman"}};
    questionTF.display();
    std::cout << questionTF.check_answer() << std::endl;

    // text question with multiple choice answer
    CAnswer *answer4 = new CMultipleChoiceAnswer{std::vector<std::string>{"YazAn", "MohaNNad"}};
    CSingleChoiceQuestion questionMC{"who two single handedly defeat dying light 2?", answer4, std::vector<std::string>{"Yazan Mohannad", "Saif and ayham", "caramel and laith"}};
    questionMC.display();
    std::cout << questionMC.check_answer() << std::endl;

    // lets try having a text question with a text answer
    CAnswer *answer11 = new CTextAnswer{"Thomas Edison"};
    CTextQuestion questionTA1{"Who invented the first light bulb?", answer11};
    questionTA1.display();
    std::cout << questionTA1.check_answer() << std::endl;

    // text question with interval answer
    CAnswer *answer22 = new CIntervalAnswer{"1914-1918"};
    CTextQuestion questionIA1{"When did WW1 start and end?", answer22};
    questionIA1.display();
    std::cout << questionIA1.check_answer() << std::endl;

    // text question with true false answer
    CAnswer *answer33 = new CTrueFalseAnswer{"true"};
    CTextQuestion questionTF1{"Did yazan pass BIE-PA1?", answer33};
    questionTF1.display();
    std::cout << questionTF1.check_answer() << std::endl;

    // text question with multiple choice answer
    CAnswer *answer44 = new CMultipleChoiceAnswer{std::vector<std::string>{"YazAn", "MohaNNad"}};
    CTextQuestion questionMC1{"who two single handedly defeat dying light 2?", answer44};
    questionMC1.display();
    std::cout << questionMC1.check_answer() << std::endl;

    return 0;
}
