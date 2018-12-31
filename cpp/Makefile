# These are examples of compilping commands in linux system.
CXX = g++
CXXFLAGS = -Wall -std=c++11 -O2
LDLIBS = -lmymathCC
LDFLAGS =

exec := $(patsubst %.cpp,%.out,$(wildcard %.cpp))
all: $(exec)
.PHONY: all tidy

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

tidy:
	rm *.out
	echo "remove all exec done!"


problem563.out: BinaryTree.h

