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

    // // lets try having a single question with a text answer
    // multi question with multiple choice answer
    CAnswer *answer1 = new CMultipleChoiceAnswer{std::vector<std::string>{"a"}};
    CSingleChoiceQuestion questionMC1{"what statments are correct?", answer1, std::vector<std::string>{"yazan is him", "yazan is batman", "ayham is batman"}};
    questionMC1.display();
    std::cout << questionMC1.check_answer() << std::endl;

    CAnswer *answer2 = new CMultipleChoiceAnswer{std::vector<std::string>{"a"}};
    CSingleChoiceQuestion questionMC2{"who defeated thanos?", answer2, std::vector<std::string>{"tony", "stalin", "avengers"}};
    questionMC2.display();
    std::cout << questionMC2.check_answer() << std::endl;

    return 0;
}
