output: main.o PayRoll.o
	g++ -std=c++11 main.o PayRoll.o -o main
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp
PayRoll.o: PayRoll.h PayRoll.cpp
	g++ -c -g -std=c++11 PayRoll.cpp
clean:
	rm -f *.o main
