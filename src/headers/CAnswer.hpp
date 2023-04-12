#pragma once

#include <string>
// Abstract Answer Class

template <typename T>
class CAnswer
{
private:
public:
    CAnswer() {}
    virtual ~CAnswer() {}
    virtual T get_answer() const = 0;
};