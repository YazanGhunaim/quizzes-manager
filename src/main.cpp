#include <iostream>
#include "headers/parser/CXMLParser.hpp"
#include "headers/quiz/CQuiz.hpp"
#include "headers/manager/CManager.hpp"

int main()
{
    CXMLParser parser("src/xml/main.xml");
    auto quiz = parser.parse();

    CXMLParser parser2("src/xml/temp.xml");
    auto quiz2 = parser2.parse();

    CManager manager({quiz, quiz2});
    manager.display();
    return 0;
}
