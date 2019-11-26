GCC=g++
FLAGS=-std=c++11 -Wall

all: main

main: travelstate.o idlestate.o combatstate.o main.o
	$(GCC) $(FLAGS) -o main travelstate.o idlestate.o combatstate.o main.o

main.o: main.cpp
	$(GCC) $(FLAGS) -c main.cpp -o main.o

travelstate.o: travelstate.cpp gamestate.h travelstate.h
	$(GCC) $(FLAGS) -c travelstate.cpp -o travelstate.o

idlestate.o: idlestate.cpp gamestate.h idlestate.h
	$(GCC) $(FLAGS) -c idlestate.cpp -o idlestate.o

combatstate: combatstate.cpp combatstate.h gamestate.h
	$(GCC) $(FLAGS) -c combatstate.cpp -o combatstate.o
clean:
	rm *.o main
