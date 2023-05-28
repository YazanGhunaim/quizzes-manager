CIntervalAnswer.o: src/CIntervalAnswer.cpp \
  src/headers/answer/CIntervalAnswer.hpp src/headers/answer/CAnswer.hpp
CManager.o: src/CManager.cpp src/headers/manager/CManager.hpp \
  src/headers/manager/../quiz/CQuiz.hpp \
  src/headers/manager/../quiz/../section/CSection.hpp \
  src/headers/manager/../quiz/../section/../question/CQuestion.hpp \
  src/headers/manager/../quiz/../section/../question/../answer/CAnswer.hpp \
  src/headers/manager/../parser/CXMLParser.hpp \
  src/headers/manager/../parser/../quiz/CQuiz.hpp \
  src/headers/manager/../parser/../question/CMultiChoiceQuestion.hpp \
  src/headers/manager/../parser/../question/CSingleChoiceQuestion.hpp \
  src/headers/manager/../parser/../question/CTextQuestion.hpp \
  src/headers/manager/../parser/../answer/CTextAnswer.hpp \
  src/headers/manager/../parser/../answer/CMultipleChoiceAnswer.hpp \
  src/headers/manager/../parser/../answer/CIntervalAnswer.hpp \
  src/headers/manager/../parser/../answer/CTrueFalseAnswer.hpp \
  src/headers/manager/../builder/CXMLBuilder.hpp \
  src/headers/manager/../builder/../quiz/CQuiz.hpp \
  src/headers/manager/../builder/../question/CMultiChoiceQuestion.hpp \
  src/headers/manager/../builder/../question/CSingleChoiceQuestion.hpp \
  src/headers/manager/../builder/../question/CTextQuestion.hpp \
  src/headers/manager/../builder/../answer/CTextAnswer.hpp \
  src/headers/manager/../builder/../answer/CMultipleChoiceAnswer.hpp \
  src/headers/manager/../builder/../answer/CIntervalAnswer.hpp \
  src/headers/manager/../builder/../answer/CTrueFalseAnswer.hpp
CMultiChoiceQuestion.o: src/CMultiChoiceQuestion.cpp \
  src/headers/question/CMultiChoiceQuestion.hpp \
  src/headers/question/CQuestion.hpp \
  src/headers/question/../answer/CAnswer.hpp
CMultipleChoiceAnswer.o: src/CMultipleChoiceAnswer.cpp \
  src/headers/answer/CMultipleChoiceAnswer.hpp \
  src/headers/answer/CAnswer.hpp
CQuiz.o: src/CQuiz.cpp src/headers/quiz/CQuiz.hpp \
  src/headers/quiz/../section/CSection.hpp \
  src/headers/quiz/../section/../question/CQuestion.hpp \
  src/headers/quiz/../section/../question/../answer/CAnswer.hpp
CSection.o: src/CSection.cpp src/headers/section/CSection.hpp \
  src/headers/section/../question/CQuestion.hpp \
  src/headers/section/../question/../answer/CAnswer.hpp
CSingleChoiceQuestion.o: src/CSingleChoiceQuestion.cpp \
  src/headers/question/CSingleChoiceQuestion.hpp \
  src/headers/question/CQuestion.hpp \
  src/headers/question/../answer/CAnswer.hpp
CTextAnswer.o: src/CTextAnswer.cpp src/headers/answer/CTextAnswer.hpp \
  src/headers/answer/CAnswer.hpp
CTextQuestion.o: src/CTextQuestion.cpp \
  src/headers/question/CTextQuestion.hpp \
  src/headers/question/CQuestion.hpp \
  src/headers/question/../answer/CAnswer.hpp
CTrueFalseAnswer.o: src/CTrueFalseAnswer.cpp \
  src/headers/answer/CTrueFalseAnswer.hpp src/headers/answer/CAnswer.hpp
CXMLBuilder.o: src/CXMLBuilder.cpp src/headers/builder/CXMLBuilder.hpp \
  src/headers/builder/../quiz/CQuiz.hpp \
  src/headers/builder/../quiz/../section/CSection.hpp \
  src/headers/builder/../quiz/../section/../question/CQuestion.hpp \
  src/headers/builder/../quiz/../section/../question/../answer/CAnswer.hpp \
  src/headers/builder/../question/CMultiChoiceQuestion.hpp \
  src/headers/builder/../question/CSingleChoiceQuestion.hpp \
  src/headers/builder/../question/CTextQuestion.hpp \
  src/headers/builder/../answer/CTextAnswer.hpp \
  src/headers/builder/../answer/CMultipleChoiceAnswer.hpp \
  src/headers/builder/../answer/CIntervalAnswer.hpp \
  src/headers/builder/../answer/CTrueFalseAnswer.hpp
CXMLParser.o: src/CXMLParser.cpp src/headers/parser/CXMLParser.hpp \
  src/headers/parser/../quiz/CQuiz.hpp \
  src/headers/parser/../quiz/../section/CSection.hpp \
  src/headers/parser/../quiz/../section/../question/CQuestion.hpp \
  src/headers/parser/../quiz/../section/../question/../answer/CAnswer.hpp \
  src/headers/parser/../question/CMultiChoiceQuestion.hpp \
  src/headers/parser/../question/CSingleChoiceQuestion.hpp \
  src/headers/parser/../question/CTextQuestion.hpp \
  src/headers/parser/../answer/CTextAnswer.hpp \
  src/headers/parser/../answer/CMultipleChoiceAnswer.hpp \
  src/headers/parser/../answer/CIntervalAnswer.hpp \
  src/headers/parser/../answer/CTrueFalseAnswer.hpp
main.o: src/main.cpp src/headers/manager/CManager.hpp \
  src/headers/manager/../quiz/CQuiz.hpp \
  src/headers/manager/../quiz/../section/CSection.hpp \
  src/headers/manager/../quiz/../section/../question/CQuestion.hpp \
  src/headers/manager/../quiz/../section/../question/../answer/CAnswer.hpp \
  src/headers/manager/../parser/CXMLParser.hpp \
  src/headers/manager/../parser/../quiz/CQuiz.hpp \
  src/headers/manager/../parser/../question/CMultiChoiceQuestion.hpp \
  src/headers/manager/../parser/../question/CSingleChoiceQuestion.hpp \
  src/headers/manager/../parser/../question/CTextQuestion.hpp \
  src/headers/manager/../parser/../answer/CTextAnswer.hpp \
  src/headers/manager/../parser/../answer/CMultipleChoiceAnswer.hpp \
  src/headers/manager/../parser/../answer/CIntervalAnswer.hpp \
  src/headers/manager/../parser/../answer/CTrueFalseAnswer.hpp \
  src/headers/manager/../builder/CXMLBuilder.hpp \
  src/headers/manager/../builder/../quiz/CQuiz.hpp \
  src/headers/manager/../builder/../question/CMultiChoiceQuestion.hpp \
  src/headers/manager/../builder/../question/CSingleChoiceQuestion.hpp \
  src/headers/manager/../builder/../question/CTextQuestion.hpp \
  src/headers/manager/../builder/../answer/CTextAnswer.hpp \
  src/headers/manager/../builder/../answer/CMultipleChoiceAnswer.hpp \
  src/headers/manager/../builder/../answer/CIntervalAnswer.hpp \
  src/headers/manager/../builder/../answer/CTrueFalseAnswer.hpp \
  src/headers/builder/CXMLBuilder.hpp
