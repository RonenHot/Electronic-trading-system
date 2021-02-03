
#ifndef __PAYMENT_H
#define __PAYMENT_H

#include "funcDeclaration.h"
#include "creditCard.h"

class Payment {

public:
	Payment();
	Payment(double totalPrice, const CreditCard& credit);

public:
	double getTotalPrice() const;

private:
	double		_totalPrice;
	CreditCard  _credit;
};

#endif // __PAYMENT_H