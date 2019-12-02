SUStackMain: SUStackDriver.o SUQueueMain payroll.o 
	g++ -o SUStackMain -std=c++11 SUStackDriver.o payroll.o
SUQueueMain: SUQueueDriver.o payroll.o
	g++ -o SUQueueMain -std=c++11 SUQueueDriver.o payroll.o
SUStackDriver.o: SUStackDriver.cpp SUStack.h SUStack.cpp SUList.h SUList.cpp
	g++ -c SUStackDriver.cpp -std=c++11
SUQueueDriver.o: SUQueueDriver.cpp SUQueue.h SUQueue.cpp SUList.h SUList.cpp
	g++ -c SUQueueDriver.cpp -std=c++11
payroll.o: payroll.h payroll.cpp
	g++ -c payroll.cpp -std=c++11
clean:
	rm -f *.o SUStackMain SUQueueMain
