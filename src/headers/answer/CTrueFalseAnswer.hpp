#pragma once

#include "CAnswer.hpp"

class CTrueFalseAnswer : public CAnswer
{
private:
    std::string m_correctAnswer;
    std::string m_userAnswer;

public:
    CTrueFalseAnswer(const std::string correctAnswer);
    ~CTrueFalseAnswer() override {}
    std::string get_correctAnswer() const override;
    std::string format_info() const override;
    void set_userAnswer(const std::string &userAnswer) override;
    bool evaluate_answer() override;
    bool multiple_answers() const override { return false; }
    bool format_error() const override;
};

/*
    Example Answer:
    True
*/