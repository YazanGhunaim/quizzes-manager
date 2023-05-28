#pragma once

#include "../section/CSection.hpp"

/*
 * CQuiz class represents a quiz.
 * It contains a name, a vector of sections, a score and a status.
 * The score is the sum of all the scores of the sections.
 * The status is true if the quiz is finished, false otherwise.
 * The quiz is finished when all the sections are finished.
 */

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
    bool checkStatus();
    std::string getName() const;

private:
    void sectionChoice();
    void validSectionChoice(const std::string &choice);
};