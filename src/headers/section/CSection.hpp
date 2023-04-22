#pragma once

#include "../question/CQuestion.hpp"
#include <iomanip>

class CSection
{
private:
    std::string m_name;
    std::vector<std::shared_ptr<CQuestion>> m_questions;
    int m_score = 0;

public:
    CSection(const std::string &name, const std::vector<std::shared_ptr<CQuestion>> &questions);
    ~CSection();
    int getScore() const;
    int totalQuestions() const;
    std::string getName() const;
    void display();
    void displayResults() const;
};