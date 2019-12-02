output: main.o Course.o Student.o StudentDB.o CourseDB.o
	g++ -g -std=c++11 main.o Course.o Student.o StudentDB.o CourseDB.o -o StudentDB

main.o: main.cpp
	g++ -c -std=c++11 main.cpp -g

Student.o: Student.cpp Student.h
	g++ -c -std=c++11 Student.cpp -g

Course.o: Course.cpp Course.h
	g++ -c -std=c++11 Course.cpp -g

CourseDB.o: CourseDB.h CourseDB.cpp
	g++ -c -std=c++11 CourseDB.cpp -g

StudentDB.o: Student.h StudentDB.cpp
	g++ -c -std=c++11 StudentDB.cpp -g

clean:
	rm *.o -f StudentDB
