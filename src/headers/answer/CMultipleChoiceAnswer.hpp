#pragma once

#include "CAnswer.hpp"
#include <vector>

// where more than one answer is correct
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
    bool multiple_answers() const override { return m_correctAnswers.size() > 1; }
    bool evaluate_answer() override;
};

/*
    Example Answer:
    1 2 3
*/