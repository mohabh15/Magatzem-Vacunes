OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o magatzem.o cambra.o sistema.o 
		g++ -c program.cpp magatzem.o cambra.o sistema.o 

#./test.exe < /jocs_de_prova/sample1.inp

program.o: program.cpp magatzem.hpp cambra.hpp sistema.hpp
		g++ -c program.cpp $(OPCIONS)

magatzem.o: magatzem.cpp magatzem.hpp cambra.hpp 
		g++ -c magatzem.cpp $(OPCIONS)

cambra.o: cambra.cpp cambra.hpp sistema.hpp
		g++ -c cambra.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe