#pragma once

#include <string>
#include <set>
#include "CQuestion.hpp"
// Text question class derived from CQuestion abstract class
class CTextQuestion : public CQuestion
{
public:
    CTextQuestion(const std::vector<std::string> &question, const std::set<std::string> &answers);
    ~CTextQuestion();
    std::vector<std::string> get_question() const override;
    std::set<std::string> get_answers() const override;
    void answer_question(const std::string &user_answer) override;
    bool evaluate_question() const override;
};
