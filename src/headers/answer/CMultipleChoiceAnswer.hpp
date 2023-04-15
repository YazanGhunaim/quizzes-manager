#pragma once

#include "CAnswer.hpp"
#include <vector>

class CMultipleChoiceAnswer : public CAnswer
{
private:
    std::vector<std::string> m_correctAnswers;
    std::vector<std::string> m_userAnswer;

public:
    CMultipleChoiceAnswer(const std::vector<std::string> &correctAnswers);
    ~CMultipleChoiceAnswer() override {}
    std::string get_correctAnswer() const override;
    std::string format_info() const override;
    void set_userAnswer(const std::string &userAnswer) override;
    bool format_error() const override;
    bool evaluate_answer() override;
};

/*
    Example Answer:
    1 2 3
*/