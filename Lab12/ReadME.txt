````
bash-4.2$ make
g++ -o main -std=c++11 Employee.o main.o Hourly.o Executive.o
bash-4.2$ ./main
Employee Name:Grant payRate:10
Name:Brock payRate:10.1 Hours Worked:0
Name:Brock payRate:10.1 Hours Worked:10
Name:Brock payRate:10.1 Hours Worked:20
Brock will be paid: 202
Name:Brock payRate:10.1 Hours Worked:0
Name:Jack payRate:10000 Bonus:100
Jack will be paid:10100
Name:Jack payRate:10000 Bonus:0
+++++Testing with virtual stuffs+++++
Name:Jack payRate:10000 Bonus:0
Test 10000
Name:Jack payRate:10000 Bonus:0
bash-4.2$
````

This lab is to show the use to polymorphism and also to
show us the use of virtual functions and why they are so
important for polymorphism
