#include <iostream>
#include "headers/answer/CTextAnswer.hpp"
#include "headers/answer/CIntervalAnswer.hpp"
#include "headers/answer/CTrueFalseAnswer.hpp"
#include "headers/answer/CMultipleChoiceAnswer.hpp"
#include "headers/question/CTextQuestion.hpp"
#include "headers/question/CSingleChoiceQuestion.hpp"
#include "headers/question/CMultiChoiceQuestion.hpp"
#include "headers/section/CSection.hpp"
#include "headers/quiz/CQuiz.hpp"

int main()
{
    CAnswer *answer1 = new CMultipleChoiceAnswer{std::vector<std::string>{"usa", "germany"}};

    std::shared_ptr<CQuestion> questionMC1 = std::make_shared<CTextQuestion>(
        "what two countries fought in WW1?",
        answer1);

    CAnswer *answer2 = new CIntervalAnswer{"1914-1918"};
    std::shared_ptr<CQuestion> questionIA1 = std::make_shared<CTextQuestion>(
        "when was WW1?",
        answer2);

    CAnswer *answer3 = new CTextAnswer{"yazan ghunaim"};
    std::shared_ptr<CQuestion> questionT1 = std::make_shared<CTextQuestion>(
        "who defeated the roman forces?",
        answer3);

    CAnswer *answer4 = new CTrueFalseAnswer{"true"};
    std::shared_ptr<CQuestion> questionTF1 = std::make_shared<CTextQuestion>(
        "was yazan him",
        answer4);

    std::vector<std::shared_ptr<CQuestion>> questions1 = {questionMC1, questionIA1, questionT1, questionTF1};

    CSection section1{"Him Test", questions1};

    CQuiz quiz1{"yazans trivia", {std::make_shared<CSection>(section1)}};
    quiz1.display();
    quiz1.displayResults();
    return 0;
}
