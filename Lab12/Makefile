output: Employee.o main.o Hourly.o Executive.o
	g++ -o main -std=c++11 Employee.o main.o Hourly.o Executive.o
Employee.o: Employee.cpp Employee.h
	g++ -c -g -std=c++11 Employee.cpp
Hourly.o: Hourly.h Hourly.cpp
	g++ -c -g -std=c++11 Hourly.cpp
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp
Executive.o: Executive.h Executive.cpp
	g++ -c -g -std=c++11 Executive.cpp
clean:
	rm -f *.o main
