#pragma once

#include "../section/CSection.hpp"

class CQuiz
{
private:
    std::string m_name;
    std::vector<std::shared_ptr<CSection>> m_sections;
    int m_score = 0;
    bool m_status;

public:
    CQuiz(const std::string &name, const std::vector<std::shared_ptr<CSection>> &sections);
    ~CQuiz();
    int getScore() const;
    int totalSections() const;
    int totalQuestions() const;
    void intro() const;
    void display();
    void displayResults() const;
    void sectionChoiceView();
    bool checkStatus();
    std::string getName() const;

private:
    void sectionChoice();
    void validSectionChoice(const std::string &choice);
};