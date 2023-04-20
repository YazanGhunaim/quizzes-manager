#pragma once

#include "CQuestion.hpp"
#include <map>

class CSingleChoiceQuestion : public CQuestion
{
private:
    std::map<char, std::string> m_options;

public:
    CSingleChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options);
    ~CSingleChoiceQuestion() override;
    void display() override;
    void display_options() const;
    bool check_answer() const override;
    bool format_error(const std::string &answer) const override;
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