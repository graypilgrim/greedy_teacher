CXX = g++
CXXFLAGS = -Wall -Werror -pedantic
LINKFLAGS = --std=c++11

lib_SOURCES = \
		gt.hpp

lib_OBJECTS=$(lib_SOURCES:.cpp=.o)

SOURCES = \
		gt.cpp \
		main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

main: $(OBJECTS)
	$(CXX) -o $@ $^ $(LINKFLAGS)

%.o : %.cpp
	$(CXX) -c -o $@  $< $(CXXFLAGS)

clean:
	rm -f *.o
	rm main

.PHONY:
	clean
