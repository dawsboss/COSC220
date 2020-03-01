output: main.o PayRoll.o payrolllist.o
	g++ -std=c++11 main.o PayRoll.o payrolllist.o -o main

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

PayRoll.o: PayRoll.cpp PayRoll.h
	g++ -c -std=c++11 PayRoll.cpp
    
payrolllist.o: payrolllist.cpp payrolllist.h
	g++ -c -std=c++11 payrolllist.cpp
    
clean:
	rm *.o -f main
