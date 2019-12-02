#include "payroll.h" // Header file
#include <iostream>  // cout, endl
#include <string>

/* Ryan Rosiak
 *
 * Implementaion file for payroll.h:
 * 
*/ 

/* 
 * Default Constructor:
 * Initializes all members to default values.
*/
PayRoll::PayRoll() {
	name = "";
	payrate = 0.0;
	hours = 0.0;
}
/*
 * Non-Default Constructor:
 * Takes a string, double, and another double as arguments and assigns them to 
 * name, payrate, and hours.
*/
PayRoll::PayRoll(std::string n, double pr, double hr) {
	name = n;
	payrate = pr;
	hours = hr;
}

/*
 * Payrate Setter:
 * Takes a double as an argument and assigns it to payrate
 */
void PayRoll::setRate(double pr) {
	payrate = pr;
}

/*
 * Name Setter:
 * Takes a string as an argument and assigns it to name
 */
void PayRoll::setName(std::string n) {
	name = n;
}

/*
 * Hours Setter:
 * Takes an double as an arugment and assigns it to hours
*/
void PayRoll::setHours(double h) {
	hours = h;
}

/*
 * Calculate Function:
 * Calculates the total pay by returning the value of hours
 * multiplied by pay
*/
double PayRoll::calculatePay() {
	return hours * payrate;
}

/*
 * PrintInfo Function:
 * Displays all possible info in given class
*/
void PayRoll::printInfo() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "PayRate: " << payrate << std::endl;
	std::cout << "Hours: " << hours << std::endl;
	std::cout << "Total Pay: " << calculatePay() << std::endl;	
}

/*
 * Name Getter:
 * Returns a string that is the name of said object
*/
std::string PayRoll::getName() {
	return name;
}

/*
 * PayRate Getter:
 * Returns the rate of the current object
 */
double PayRoll::getRate() {
	return payrate;
}

/*
 * Hours Getter:
 * Returns the hours of the current object
 */
double PayRoll::getHours() {
	return hours;
}

/*
 * Overloaded operator<< Function:
 * Returns a reference to the ouput stream and prints out payroll members
 */
std::ostream& operator<<(std::ostream& os, PayRoll& p) {
	p.printInfo();
	return os;
}
