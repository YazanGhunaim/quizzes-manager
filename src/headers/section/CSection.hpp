#pragma once

#include "../question/CQuestion.hpp"
#include <iomanip>
#include <memory>

/*
CSection class
* A section is a collection of questions
* A section has a name, a vector of questions, a score, and a status (done or not)
* A section can display its questions
* A section can display its results
* A section can return its name
* A section can return its status
* A section can return its score
* A section can return the number of questions it has
* A section can set its status
* A section is finished when the user has answered all the questions of that section.
*/

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