OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: main_arbre.exe

main_arbre.exe: main_arbre.o listIOint.o
	g++ -o main_arbre.exe main_arbre.o listIOint.o
	rm *.o

main_arbre.o: main_arbre.cpp arbreBin.hpp listIOint.hpp
	g++ -c main_arbre.cpp $(OPCIONS)

listIOint.o: listIOint.cpp listIOint.hpp
	g++ -c listIOint.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch