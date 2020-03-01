output: HanoiDisc.o HanoiStack.o main.o
	g++ -g -std=c++11 main.o HanoiDisc.o HanoiStack.o -o main

main.o: main.cpp
	g++ -c -std=c++11 main.cpp -g

HanoiDisc.o: HanoiDisc.cpp
	g++ -c -std=c++11 HanoiDisc.cpp -g

HanoiStack.o: HanoiStack.cpp
	g++ -c -std=c++11 HanoiStack.cpp -g

clean:
	rm *.o -f main 
