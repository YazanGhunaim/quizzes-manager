#pragma once

#include "CQuestion.hpp"

class CSingleChoiceQuestion : public CQuestion
{
private:
    std::vector<std::string> m_options;

public:
    CSingleChoiceQuestion(const std::string &question, CAnswer *answer, const std::vector<std::string> &options);
    ~CSingleChoiceQuestion() override;
    void display() override;
    void display_options() const;
    bool check_answer() const override;
    void set_userAnswer(const std::string &answer) override;
};