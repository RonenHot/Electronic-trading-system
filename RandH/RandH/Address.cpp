#include "address.h"

Address::Address()
{
	_houseNumber = 0;
}
//--------------------------------------------------------------------------------//
Address::Address(const string& city, const string& streetName, int houseNumber)
{
	setCity(city);
	setStreet(streetName);
	setHNumber(houseNumber);
}

//--------------------------------------------------------------------------------//
void Address::setCity(const string& city)
{
	_city = city;
}
//--------------------------------------------------------------------------------//
void Address::setStreet(const string& streetName)
{
	_streetName = streetName;

}
//--------------------------------------------------------------------------------//
void Address::setHNumber(int houseNumber)
{
	_houseNumber = houseNumber;
}
//--------------------------------------------------------------------------------//
const string& Address::getCity() const
{
	return _city;
}
//--------------------------------------------------------------------------------//
const string& Address::getStreet() const
{
	return _streetName;
}
//--------------------------------------------------------------------------------//
int Address::getHNumber() const
{
	return _houseNumber;
}

//--------------------------------------------------------------------------------//
ostream& operator<<(ostream& os, const Address& address)
{
	os << "\nCity: " << address._city << "\nStreet: " << address._streetName << "\nHouse number: " << address._houseNumber << "\n";
	return os;
}

//--------------------------------------------------------------------------------//

void Address::write(ofstream& outFile) const
{
	outFile << '\n' << _city << '\n' << _streetName << '\n' << _houseNumber << '\n';
}

void Address::read(ifstream& inFile)
{
	string city;
	inFile >> city;
	setCity(city);

	string street;
	inFile >> street;
	setStreet(street);

	inFile >> _houseNumber;
}