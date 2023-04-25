#pragma once

#include "../question/CQuestion.hpp"
#include <iomanip>

class CSection
{
private:
    std::string m_name;
    std::vector<std::shared_ptr<CQuestion>> m_questions;
    int m_score = 0;
    bool m_status;

public:
    CSection(const std::string &name, const std::vector<std::shared_ptr<CQuestion>> &questions);
    ~CSection();
    std::string getName() const;
    bool getStatus() const;
    void setStatus(const bool status); // done or not
    int getScore() const;
    int totalQuestions() const;
    void display();
    void displayResults() const;
};