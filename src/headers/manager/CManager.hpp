#pragma once

#include <iostream>
#include "../quiz/CQuiz.hpp"
#include "../parser/CXMLParser.hpp"

class CManager
{
private:
    std::vector<std::shared_ptr<CQuiz>> m_quizzes;
    std::vector<std::string> m_filePaths;
    CXMLParser m_parser;

public:
    explicit CManager(const std::vector<std::string> &filePaths);
    ~CManager();
    void display() const;
    void run() const;

private:
    size_t getQuizChoice() const;
};