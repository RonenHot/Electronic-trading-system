
#ifndef _CREDITCARD_H
#define _CREDITCARD_H

#include "funcDeclaration.h"
#include "date.h"

class Date;

class CreditCard
{

public:
	CreditCard() { _cvv = _creditNumber = 0; };
	CreditCard(const string& name, int creditNumber, short int cvv, const Date& date);

public:
	const string& getCardholdersName() const;
	int getCreditNumber() const;

	const CreditCard& operator=(const CreditCard& other);

private:
	string _cardHoldersName;
	Date _creditDate;
	int _creditNumber;
	short int _cvv;
};

#endif // __CREDITCARD_H