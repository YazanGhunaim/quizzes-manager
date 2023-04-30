#pragma once

#include <iostream>
#include "../quiz/CQuiz.hpp"

class CManager
{
private:
    std::vector<std::shared_ptr<CQuiz>> m_quizzes;

public:
    explicit CManager(const std::vector<std::shared_ptr<CQuiz>> &quizzes);
    ~CManager();
    void display() const;
    void evaluate() const;

private:
    size_t getQuizChoice() const;
};