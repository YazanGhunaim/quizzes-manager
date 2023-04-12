#pragma once

#include "CAnswer.hpp"
// T/F answer class derived from CAnswer abstract class
class CTrueFalseAnswer : public CAnswer<bool>
{
private:
    bool m_answer;

public:
    CTrueFalseAnswer(const bool ans) : m_answer(ans) {}
    ~CTrueFalseAnswer() {}
    bool get_answer() const override { return m_answer; }
};