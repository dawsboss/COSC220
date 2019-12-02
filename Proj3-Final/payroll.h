#ifndef PAYROLL_H_
#define PAYROLL_H_
#include <string>

class PayRoll {
	friend std::ostream& operator<<(std::ostream&, PayRoll&);
private:
	std::string name;
	double payrate;
	double hours;
public:	
	PayRoll(); 				// default ctor
	PayRoll(std::string, double, double);	// non-default ctor
	double getRate();			// returns payrate
	double getHours();			// returns hours
	void setRate(double);			// assigns payrate
	void setName(std::string);		// assigns name
	void setHours(double);			// assigns hours
	double calculatePay(); 			// "getTotal()" returns the pay
	void printInfo();			// prints info of all data members plus total pay
	std::string getName();			// returns name
};

#endif
