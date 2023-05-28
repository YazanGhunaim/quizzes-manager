#pragma once

#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stdexcept>

/*
 * CAnswer is an abstract class that represents an answer to a question.
 * It has a pure virtual method evaluate_answer() that returns true if the answer is correct, false otherwise.
 * It has a pure virtual method format_info() that returns a string with how the answer should be formatted.
 * It has a pure virtual method format_error() that returns true if the answer has a format error, false otherwise.
 * It has a pure virtual method multiple_answers() that returns true if the answer has multiple answers, false otherwise.
 * It has a pure virtual method get_correctAnswer() that returns the correct answer.
 * It has a pure virtual method set_userAnswer() that sets the user's answer.
 */

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