#pragma once

#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stdexcept>
// abstract answer class

class CAnswer
{
public:
    virtual ~CAnswer() {}
    virtual std::string get_correctAnswer() const = 0;
    virtual void set_userAnswer(const std::string &userAnswer) = 0;
    virtual std::string format_info() const = 0;
    virtual bool evaluate_answer() = 0;
    virtual bool format_error() const = 0;
    virtual bool multiple_answers() const = 0;

    static void tolower(std::string &string)
    {
        std::for_each(string.begin(), string.end(), [](char &c)
                      { c = std::tolower(static_cast<unsigned char>(c)); });
    }
};