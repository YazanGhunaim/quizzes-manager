#include <iostream>
#include "headers/manager/CManager.hpp"
#include "headers/builder/CXMLBuilder.hpp"

int main()
{
    std::vector<std::string> filePaths{"src/xml/main.xml", "src/xml/temp.xml", "src/xml/custom.xml"};
    CManager manager{filePaths};
    manager.display();
    // Create a new quiz
    // CXMLBuilder builder("test quiz");

    // // Add a new section
    // builder.add_section("world war knowledge");

    // // Add a text question
    // builder.add_question("text", "Germany won WW1");
    // builder.add_answer("T/F", std::vector<std::string>{"false"});

    // // Add a single choice question
    // builder.add_question("single", "When was WW1?");
    // builder.add_option("1914-1918");
    // builder.add_option("1915-1919");
    // builder.add_option("1916-1920");
    // builder.add_option("1917-1921");
    // builder.add_answer("interval", std::vector<std::string>{"1914-1918"});

    // // Add a multiple choice question
    // builder.add_question("multi", "Who were the allies in WW1");
    // builder.add_option("France UK Italy Japan USA");
    // builder.add_option("Germany Russia Jordan");
    // builder.add_option("Italy France UK Germany");
    // builder.add_option("There were no allies");
    // builder.add_answer("text", std::vector<std::string>{"France UK Italy Japan USA"});

    // // Add another text question
    // builder.add_question("text", "who was the dictator of Germany from 1933 until his suicide in 1945.");
    // builder.add_answer("text", std::vector<std::string>{"adolf hitler"});

    // // Add another section
    // builder.add_section("counter strike knowledge");

    // // Add a text question
    // builder.add_question("text", "What is the name of the map that is played the most in competitive play?");
    // builder.add_answer("text", std::vector<std::string>{"mirage"});

    // // Add another text question
    // builder.add_question("text", "Whats the name of the preffered sniper rife");
    // builder.add_answer("text", std::vector<std::string>{"awp"});

    // // Add a single choice question
    // builder.add_question("single", "Who won the 2019 Major");
    // builder.add_option("Faze");
    // builder.add_option("Astralis");
    // builder.add_option("Cloud9");
    // builder.add_option("NIP");
    // builder.add_answer("text", std::vector<std::string>{"Cloud9"});

    // // Add another text question
    // builder.add_question("text", "whats the highest rank achievable in CSGO");
    // builder.add_answer("text", std::vector<std::string>{"Global Elite"});

    // // Add a multiple choice question
    // builder.add_question("multi", "what are the two main rifles in CSGO?");
    // builder.add_option("Scout");
    // builder.add_option("M4a4");
    // builder.add_option("Zeus");
    // builder.add_option("ak-47");
    // builder.add_answer("multi", std::vector<std::string>{"M4a4", "ak-47"});

    // // Add another text question
    // builder.add_question("text", "Whats the period of years were astralis were unbeatable");
    // builder.add_answer("interval", std::vector<std::string>{"2013-2014"});

    // // Save the quiz to an XML file
    // builder.save_quiz("yazan.xml");

    return 0;
}
