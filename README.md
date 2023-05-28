# About

My quizzes manager is a terminal based application where users can engage in answering and even in creating their own custom quizzes.

The project makes use of proper OOP-Principles and functionalities such as abstract classes, polymorphism, inheritance and encapsulation.

# Building Blocks

An abstract class Answer representing answers to questions, to which 4 types of answers are derived from:

1- Interval answers (X-X such that X is a number) 
    
    	ex: 2010-2020

2- Multiple answers 
    
    	ex: apples,oranges,bananas

4- True/False answers

3- Text Answers

These answers can be combined to different types of questions that will be mentioned later on.

An abstract class Question representing questions, to which 3 types  of questions are derived from:

1- Text Question
	
	ex: who was the inventor of the first lightbulb

2- Single Choice Question 

	ex: Who was the inventor of the first light bulb?
		A: Thomas Edison
		B: Nikola Tesla
		C: Adolf Hitler

3- Multiple Choice Question (same as single choice but can support multiple correct options)

These questions can be paired with different types of answers, here are some examples

Text question with multiple answers:

	Name the two days in the weekend:
	Saturday, sunday

Single choice question with interval answers:

	When did WW1 take place:
	1914-1918
	2021-2022

A class Section which is a collection of questions, these sections can be displayed by making use of functionalities already built by CQuestion and CAnswer classes, each question in the section is displayed and is continuously prompted until a valid answer is written.

A class Quiz which is the core building block of the application, this is a collection of sections which makes use of functionalities already built by all previous classes, the user is welcomed to the quiz and prompted which section he would like to start with and moves on to answering each question of each section, which after all sections related to a quiz are done, he receives his/her final evaluation.

The CXMLParser class is a C++ class that provides functionality for parsing an XML file containing quiz data and constructing a quiz object from the parsed data using the libxml2 library.
The main method of the CXMLParser class is the parse() method, which reads the XML file, extracts the quiz title, sections, and questions, and creates a quiz object.
This method calls several other private methods to extract different parts of the quiz data, such as the section titles, question titles, answer types, and options.
The CXMLParser class also has several private methods for extracting different parts of the quiz data, such as the setup() method for initializing the parser context and parsing the XML file, the addToQuestVec() method for adding a new question to the vector of questions in a section, the getOptions() method for extracting the options for a question from the XML node, and the getQuestions() method for extracting the details of a question from an XML node and adding it to the vector of questions.  Overall, the CXMLParser class provides a convenient way to parse XML files containing quiz data and construct a quiz object from the parsed data.

A class CXMLBuilder that provides functionality in which a user can from the terminal, create his own custom quiz which will be saved as an XML, without the need to have any XML knowledge however must follow and know the types of questions and answers and how they should be formatted.

A class CManager which holds everything together, provides interfaces for the entire app, displaying available quizzes, providing interfaces for different options such as creating of quiz and is overall what interacts with every aspect of the application.

# Makefile
To build the application make use of command 
	
	make run.
Cleanup of files generated by build process can be done using 

	make clean.

# Summary
Overall my project contains 4 different types of answers, 3 different types of questions, sections and transitioning between different sections, user interface for creating and filling with automatic evaluation of a quiz along with exporting and importing quizzes with the help of libxml library.


# UML-Class Diagram
![uml-diagram](https://github.com/YazanGhunaim/quizzes-manager/assets/87646431/539d0636-d960-4708-8a52-494d3213a25f)
