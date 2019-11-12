output: SULibTest.o PayRoll.o
	g++ -std=c++11 SULibTest.o PayRoll.o -o main
SULibTest.o: SULibTest.cpp
	g++ -c -g -std=c++11 SULibTest.cpp
PayRoll.o: PayRoll.h PayRoll.cpp
	g++ -c -g -std=c++11 PayRoll.cpp
clean:
	rm -f *.o main
