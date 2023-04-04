#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <string>
#include <set>
#include "answer.hpp"

class CQuestion
{
private:
    std::string m_question;
    std::set<CAnswer> m_possibleAnswers;
    std::set<CAnswer> m_correctAnswer;

public:
    CQuestion(const std::string &question, const std::set<CAnswer> &possible_answers, const std::set<CAnswer> &correct_answer);
    ~CQuestion() {}
    std::string get_question() const;
    std::set<CAnswer> get_answers() const;
    std::set<CAnswer> get_solution() const;
    /// @brief virtual method to be overloaded by each type of question, achieving polymorphism
    virtual bool evaluate_answer() const;
};

#endif // QUESTION_HPP