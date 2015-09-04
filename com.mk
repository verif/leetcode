all: a.out

a.out: t.cpp
	g++ -std=c++0x -Wall t.cpp -o a.out

.PHONY:
