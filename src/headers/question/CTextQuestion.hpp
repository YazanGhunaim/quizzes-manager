#pragma once

#include "CQuestion.hpp"

class CTextQuestion : public CQuestion
{
public:
    CTextQuestion(const std::string &question, CAnswer *answer);
    ~CTextQuestion() override;
    void display() override;
    bool check_answer() const override;
    bool format_error(const std::string &answer) const override;
    void set_userAnswer(const std::string &answer) override;
};

/*
    Example Question:
    Who was the inventor of the first light bulb?
*/