#pragma once

#include <iostream>
#include "../quiz/CQuiz.hpp"
#include "../parser/CXMLParser.hpp"
#include "../builder/CXMLBuilder.hpp"

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
    void getCorrectAnswer(std::vector<std::string> &vec, bool prompt = false) const;
    void answers(CXMLBuilder &builder) const;
    void textQuestion(CXMLBuilder &builder) const;
    void questions(CXMLBuilder &builder) const;
    void sections(CXMLBuilder &builder) const;
    std::string getSectionName() const;
    std::string getQuizName() const;
    size_t getQuizChoice() const;
    void build() const;
};