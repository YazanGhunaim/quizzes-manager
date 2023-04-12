#pragma once

#include <string>
#include <set>
#include "CQuestion.hpp"
// Multi Choice question class derived from CQuestion abstract class
class CMultiChoiceQuestion : public CQuestion
{
private:
    std::vector<int> m_correctIndices;

public:
    CMultiChoiceQuestion(const std::vector<std::string> &question,
                         const std::set<std::string> &answers,
                         const std::vector<int> &correct_indices);
    ~CMultiChoiceQuestion();
    std::vector<std::string> get_question() const override;
    std::set<std::string> get_answers() const override;
    void answer_question(const std::string &user_answer) override;
    bool evaluate_question() const override;
};
