#pragma once

#include "../section/CSection.hpp"

class CQuiz
{
private:
    std::string m_name;
    std::vector<std::shared_ptr<CSection>> m_sections;
    int m_score = 0;

public:
    CQuiz(const std::string &name, const std::vector<std::shared_ptr<CSection>> &sections);
    ~CQuiz();
    int getScore() const;
    int totalSections() const;
    int totalQuestions() const;
    std::string getName() const;
    void intro() const;
    void display();
    void displayResults() const;
};