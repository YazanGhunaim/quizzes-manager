#pragma once

#include <string>
#include <set>
#include <vector>
// Abstract Question Class
class CQuestion
{
protected:
    std::vector<std::string> m_question;
    std::set<std::string> m_answer;
    std::string m_userAnswer;

public:
    CQuestion(const std::vector<std::string> &question, const std::set<std::string> &answers)
        : m_question(question), m_answer(answers){};
    virtual ~CQuestion(){};
    virtual std::vector<std::string> get_question() const = 0;
    virtual std::set<std::string> get_answers() const = 0;
    virtual void answer_question(const std::string &user_answer) = 0;
    virtual bool evaluate_question() const = 0;
};