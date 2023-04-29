#include <iostream>
#include "headers/parser/CXMLParser.hpp"
#include "headers/quiz/CQuiz.hpp"

int main()
{
    CXMLParser parser("src/xml/main.xml");
    auto quiz = parser.parse();

    quiz->display();
    quiz->displayResults();

    return 0;
}
