#ifndef __USER_H
#define __USER_H

#include "address.h"

class User
{
public:
	User() {};
	User(const string& userName, const string& userPassword, const Address& userAddress);
	User(ifstream& in);
	virtual ~User() {};

public:
	virtual void        setName(const string& userName);
	virtual const string& getName() const;
	virtual void        setPassword(const string& userPassword);
	virtual const string& getPassword() const;

public:


	virtual const User& operator=(const User& other);
	virtual void show() const = 0;
	virtual void write(ofstream& outFile) const = 0;

protected:
	string _userName;
	string _userPassword;
	Address	_userAddress;

};

#endif //_USER