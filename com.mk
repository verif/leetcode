all: a.out
	./a.out

a.out: t.cpp
	g++ -g -std=c++0x -Wall t.cpp -o a.out

clean:
	\rm -f a.out

.PHONY:
