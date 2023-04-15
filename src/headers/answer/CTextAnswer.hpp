#pragma once

#include "CAnswer.hpp"

class CTextAnswer : public CAnswer
{
private:
    std::string m_correctAnswer;
    std::string m_userAnswer;

public:
    CTextAnswer(const std::string &correctAnswer);
    ~CTextAnswer() override {}
    std::string get_correctAnswer() const override;
    std::string format_info() const override;
    void set_userAnswer(const std::string &userAnswer) override;
    bool format_error() const override;
    bool evaluate_answer() override;
};

/*
    Example Answer:
    Thomas Edison
*/