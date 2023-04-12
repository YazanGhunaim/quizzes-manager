#pragma once

#include <string>
#include "CAnswer.hpp"
// Single answer class derived from CAnswer abstract class

class CSingleAnswer : public CAnswer<std::string>
{
private:
    std::string m_correctAnswer;

public:
    CSingleAnswer(const std::string &ans) : m_correctAnswer(move(ans)) {}
    ~CSingleAnswer(){};
    std::string get_answer() const override { return m_correctAnswer; }
};