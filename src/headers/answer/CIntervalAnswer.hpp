#pragma once

#include "CAnswer.hpp"

class CIntervalAnswer : public CAnswer
{
private:
    std::string m_correctAnswer;
    std::string m_userAnswer;

public:
    CIntervalAnswer(const std::string &correctAnswer);
    ~CIntervalAnswer() override {}
    std::string get_correctAnswer() const override;
    std::string format_info() const override;
    void set_userAnswer(const std::string &userAnswer) override;
    bool evaluate_answer() override;
    bool format_error() const override;
};

/*
    Example Answer:
    2003-2023
*/