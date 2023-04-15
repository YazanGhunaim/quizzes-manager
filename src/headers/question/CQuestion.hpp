#pragma once

#include <string>
#include <iostream>
#include "../answer/CAnswer.hpp"

class CQuestion
{
protected:
    std::string m_question;
    CAnswer *m_answer;

public:
    CQuestion(const std::string &question, CAnswer *answer) : m_question(std::move(question)), m_answer(answer) {}
    virtual ~CQuestion() {}
    virtual void display() = 0; // display questions and prompts user for answers
    virtual bool check_answer() const = 0;
    virtual void set_userAnswer(const std::string &answer) = 0;
};