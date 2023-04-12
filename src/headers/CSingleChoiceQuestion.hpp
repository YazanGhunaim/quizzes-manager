#pragma once

#include <string>
#include <set>
#include "CQuestion.hpp"
// Single Choice question class derived from CQuestion abstract class
class CSingleChoiceQuestion : public CQuestion
{
private:
    int m_correctIndex;

public:
    CSingleChoiceQuestion(const std::vector<std::string> &question,
                          const std::set<std::string> &answers,
                          int correctIndex);
    ~CSingleChoiceQuestion();
    std::vector<std::string> get_question() const override;
    std::set<std::string> get_answers() const override;
    void answer_question(const std::string &user_answer) override;
    bool evaluate_question() const override;
};
