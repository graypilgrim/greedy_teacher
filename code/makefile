CXX = g++
CXXFLAGS = -c -Wall -Werror -pedantic
LINKFLAGS = --std=c++11

SOURCES = \
		GreedyTeacher.cpp \
		main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

main: $(OBJECTS)
	$(CXX) $(LINKFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o
	rm main

.PHONY:
	clean
