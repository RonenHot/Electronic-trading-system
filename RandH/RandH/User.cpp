#include"User.h"
#include "RandH.h"


User::User(const string& userName, const string& userPassword, const Address& userAddress) : _userAddress(userAddress)
{
	setName(userName);
	setPassword(userPassword);
}

User::User(ifstream& in)
{
	string name;
	in >> name;
	setName(name);

	string pass;
	in >> pass;
	setPassword(pass);

	_userAddress.read(in);
}


void User::setName(const string& userName)
{
	_userName = userName;
}

const string& User::getName() const
{
	return _userName;
}
void  User::setPassword(const string& userPassword)
{
	_userPassword = userPassword;
}

const string& User::getPassword() const
{
	return _userPassword;
}

const User& User:: operator=(const User& other)
{
	if (this != &other)
	{
		_userName = other._userName;
		_userPassword = other._userPassword;
		_userAddress = other._userAddress;
	}
	return *this;
}

void User::show() const
{
	cout << "Name: " << getName() << "\n Address: " << _userAddress;

}

void User::write(ofstream& outFile) const
{
	outFile << typeid(*this).name() + 6 << '\n' << getName() << '\n' << getPassword();
	_userAddress.write(outFile);
	outFile << endl;
}