#pragma once

#include <iostream>
#include <filesystem>
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
    explicit CManager();
    ~CManager();
    void display() const;
    void run() const;

private:
    void getCorrectAnswer(std::vector<std::string> &vec, bool prompt = false) const;
    void options(CXMLBuilder &builder) const;
    void answers(CXMLBuilder &builder, bool single = false) const;
    void textQuestion(CXMLBuilder &builder) const;
    void singleQuestion(CXMLBuilder &builder) const;
    void multiQuestion(CXMLBuilder &builder) const;
    void questions(CXMLBuilder &builder) const;
    void sections(CXMLBuilder &builder) const;
    std::string getSectionName() const;
    std::string getQuizName() const;
    size_t getQuizChoice() const;
    void build() const;
};