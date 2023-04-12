#pragma once

#include "CAnswer.hpp"
// Interval answer class derived from CAnswer abstract class
class CIntervalAnswer : public CAnswer<std::pair<int, int>>
{
private:
    std::pair<int, int> interval;

public:
    CIntervalAnswer(const int lo,const int hi) : interval(std::make_pair(lo, hi)) {}
    ~CIntervalAnswer() {}
    std::pair<int, int> get_answer() const override { return interval; }
};