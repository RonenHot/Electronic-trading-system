#include "feedback.h"
#include"Buyer.h"

Feedback::Feedback(const string& assess, const Date& date, Buyer& newBuyer)
	:_date(date)
{
	setAssess(assess);
	setBuyer(newBuyer);
}

void Feedback::setAssess(const string& assess)
{
	_assessment = assess;
}

void Feedback::setBuyer(Buyer& newBuyer)
{
	if (_theBuyer != &newBuyer)
	{
		_theBuyer = &newBuyer;
		if (_theBuyer != nullptr)
			_theBuyer->setFeedback(this);
	}
}

const Feedback& Feedback::operator=(const Feedback& other)
{
	if (this != &other)
	{
		_date = other._date;
		_assessment = other._assessment;
		_theBuyer = nullptr;
		_theBuyer = other._theBuyer;

	}
	return *this;
}
//--------------------------//
ostream& operator<<(ostream& os, const Feedback& feedback)
{
	os << "from: " << feedback._theBuyer->getName() << "\nat :";
	os << feedback._date;
	os << "\nfeedback: \n" << feedback._assessment << endl;
	return os;
}