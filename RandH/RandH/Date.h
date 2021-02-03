
#ifndef __DATE_H
#define __DATE_H

#include "funcDeclaration.h"

class Date
{
public:
	Date();
	Date(int m, int y);

public:

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	friend ostream& operator<<(ostream& os, const Date& date);

private:
	int _day, _month, _year;
};

#endif // __DATE_H