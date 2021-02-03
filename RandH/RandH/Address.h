
#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "funcDeclaration.h"

class Address
{
public:
	Address();
	Address(const string& city, const string& streetName, int houseNumber);

public:
	void setCity(const string& city);
	void setStreet(const string& streetName);
	void setHNumber(int houseNumber);

	const string& getCity() const;
	const string& getStreet() const;
	int getHNumber() const;

public:
	friend ostream& operator<<(ostream& os, const Address& address);

public:
	void write(ofstream& outFile) const;
	void read(ifstream& inFile);

private:
	string _city;
	string _streetName;
	int _houseNumber;
};

#endif // __Address_H