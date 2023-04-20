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
    CAnswer *answer1 = new CMultipleChoiceAnswer{std::vector<std::string>{"usa", "germany"}};
    CTextQuestion questionMC1{
        "what two countries fought in WW1?",
        answer1,
    };
    questionMC1.display();
    std::cout << questionMC1.check_answer() << std::endl;

    CAnswer *answer2 = new CIntervalAnswer{"1914-1918"};
    CTextQuestion questionIA1{
        "when was WW1?",
        answer2,
    };

    questionIA1.display();
    std::cout << questionIA1.check_answer() << std::endl;

    CAnswer *answer3 = new CTextAnswer{"yazan ghunaim"};
    CTextQuestion questionT1{
        "who defeated the roman forces?",
        answer3,
    };
    questionT1.display();
    std::cout << questionT1.check_answer() << std::endl;

    CAnswer *answer4 = new CTrueFalseAnswer{"true"};
    CTextQuestion questionTF1{
        "was yazan him",
        answer4,
    };
    questionTF1.display();
    std::cout << questionTF1.check_answer() << std::endl;

    return 0;
}
