#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "../answer/CAnswer.hpp"

/*
 * CQuestion is an abstract class that represents a question.
 * It has a pure virtual method display() that displays the question and prompts the user for an answer.
 * It has a pure virtual method check_answer() that returns true if the answer is correct, false otherwise.
 * It has a pure virtual method format_error() that returns true if the answer has a format error, false otherwise.
 * It has a pure virtual method set_userAnswer() that sets the user's answer.
 * It has a pure virtual method format_info() that returns a string with how the question should be answered.
 */

class CQuestion
{
protected:
    std::string m_question;
    CAnswer *m_answer;

public:
    CQuestion(const std::string &question, CAnswer *answer) : m_question(std::move(question)), m_answer(answer) {}
    virtual ~CQuestion() {}
    virtual void display() = 0;
    virtual bool check_answer() const = 0;
    virtual bool format_error(const std::string &answer) const = 0;
    virtual void set_userAnswer(const std::string &answer) = 0;
    virtual std::string format_info() const = 0;
};