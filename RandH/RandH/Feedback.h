#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "funcDeclaration.h"
#include "date.h"
class Buyer;

class Feedback {

public:
	Feedback(const string& assess, const Date& date, Buyer& newBuyer);
public:
	void setAssess(const string& assess);
	void setBuyer(Buyer& newBuyer);

public:
	const Feedback& operator=(const Feedback& other);
	friend ostream& operator<<(ostream& os, const Feedback& feedback);

private:
	Buyer* _theBuyer; //the user that gave the feedback
	Date	_date;
	string _assessment;
};

#endif // __FEEDBACK_H
