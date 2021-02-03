#include "creditCard.h"

//--------------------------------------------------------------------------------//
CreditCard::CreditCard(const string& name, int creditNumber, short int cvv, const Date& date)
	:_creditDate(date)
{
	_cardHoldersName = name;
	_creditNumber = creditNumber;
	_cvv = cvv;
}
//-----------------------------------------------------------------------------//
const string& CreditCard::getCardholdersName() const
{
	return _cardHoldersName;
}

//--------------------------------------------------------------------------------//
int CreditCard::getCreditNumber() const
{
	return _creditNumber;
}
//--------------------------------------------------------------------------------//

const CreditCard& CreditCard::operator=(const CreditCard& other)
{
	if (this != &other)
	{
		_cardHoldersName = other._cardHoldersName;
		_creditNumber = other._creditNumber;
		_cvv = other._cvv;
	}
	return *this;
}