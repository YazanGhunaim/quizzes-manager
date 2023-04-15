#pragma once

#include "CQuestion.hpp"

class CMultiChoiceQuestion : public CQuestion
{
private:
    std::vector<std::string> m_options;

public:
    CMultiChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options);
    ~CMultiChoiceQuestion() override;
    void display() override;
    void display_options() const;
    bool check_answer() const override;
    void set_userAnswer(const std::string &answer) override;
};

/*
    Example Question:
    Who was the inventor of the first light bulb?
        Options:
        A: Thomas Edison
        B: Nikola Tesla
        C: Adolf Hitler
*/