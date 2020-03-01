//Grant Dawson COSC 220
The lab's goal was to have a linked list of the PayRoll.
The list is organized/sorted by the amount each person is paid.

insert will automatically sort your list as you go
insert(pay, hours, name)or(PayRoll)

At the end it will print all of your items in the list.

The file is eds has to be named inputs.txt unless you are willing to change the code
-you can go in any order the function will sort from the file and user input

The information saved is just printed into the console

How to compile and run:
  make - compiles code and mains the ./main executable
  ./main - runs the executable made by the make
    -any errors try make clean to re whipe the .o files

Lab4=============
	 Added the ability to make new nodes and delete and overight but inreguards to the index that is inputted
	 also overloaded [int] to reutrn a PayRoll*from a give in index
	 added copy constructor 