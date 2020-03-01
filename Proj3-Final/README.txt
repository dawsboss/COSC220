Ryan Rosiak
COSC 220-001
Project 3 README File
11/23/19

Project Description:
This project demonstrates the programmers capabilities in remaking the List, Stack, and Queue
libraries that are already built in to the c++ libraries. This shows that you may need to 
create things from scratch in order to get exactly what you want out of these libraries. Not
only this, but it also demonstrates the deep understanding of how these libraries work 
behind the scenes because we are able to create the work ourselves.

Files to pay attention to:

SUStackDriver.o, SUQueueDriver.o, payroll.o - These are the compilation linker files

SUStackMain, SUQueueMain - Output file that is run when the program is executed by the user

Makefile - File tha tallows the user to compile without having to input specific commands

Makefile Instructions:

To compile the program:

Type "make" without the quotes and the program wil compile everything together for you. Then
proceed with using ./SUStackMain and ./SUQueueMain in order to run the program drivers.

Instructions for Program:

Follow the Makefilie instructions above to run the program without any manual work. If not 
using Makefile, then you must compile the .cpp files into .o files. (g++ -c main.cpp) Then 
you must link those with a final compilation all the while labeling the output file as the
name of the driver files provided.
**You must use -std=c++11 within your compilation steps
