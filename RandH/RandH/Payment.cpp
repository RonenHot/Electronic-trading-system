#include "payment.h"

Payment::Payment()
{
	_totalPrice = 0;
}

Payment::Payment(double totalPrice, const CreditCard& credit)
	:_credit(credit)
{
	_totalPrice = totalPrice;
}

double Payment::getTotalPrice() const
{
	return _totalPrice;
}