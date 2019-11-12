output: main.o PayRoll.o PayRollStack.o
	g++ -std=c++11 main.o PayRoll.o PayRollStack.o -o main

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

PayRoll.o: PayRoll.cpp PayRoll.h
	g++ -c -std=c++11 PayRoll.cpp

PayRollStack.o: PayRollStack.cpp PayRollStack.h
	g++ -c -std=c++11 PayRollStack.cpp

clean:
	rm -f *.o main
