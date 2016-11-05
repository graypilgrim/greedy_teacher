CXX = g++
CXXFLAGS = -c -Wall -pedantic
LINKFLAGS = --std=c++11

SOURCES = \
		GreedyTeacher.cpp \
		Tester.cpp \
		Interpreter.cpp \
		main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

greedy-teacher: $(OBJECTS)
	$(CXX) $(LINKFLAGS) $^ -o $@
	@rm -f *.o *.gch
	@echo Built completed

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@rm -f greedy-teacher
	@rm -f *.o *.gch

.PHONY:
	clean
