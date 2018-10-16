COMPILER = g++
LIBS =  -L$(lib)/gsl/lib
LINKS =  -lgsl -lgslcblas -lmymath -lmymathCC
FLAGS =  -O2 -Wall -std=c++11
problem788 : problem788.cpp
	$(COMPILER) $(FLAGS) $(LIBS) -o $@ $^ $(LINKS)
