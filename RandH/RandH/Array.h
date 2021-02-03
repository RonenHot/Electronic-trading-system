
#ifndef __ARRAY_H
#define __ARRAY_H

#include "funcDeclaration.h"

template<class T>
class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;

public:
	Array(char delimiter = ' ');
	Array(const Array& other);
	~Array();

	int getArrSize() const;

	const Array& operator=(const Array& other);
	Array& operator+=(T newVal);
	const T& operator[](int index) const;

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.logicalSize; i++)
			os << arr.arr[i] << arr.delimiter;
		return os;
	}

};

template<class T>
Array<T>::Array(char delimiter) :physicalSize(1), logicalSize(0), delimiter(delimiter)
{
	arr = new T[physicalSize];
	arr[logicalSize] = nullptr;
}


template<class T>
Array<T>::Array(const Array& other) : arr(NULL)
{
	*this = other;
}

template<class T>
Array<T>::~Array()
{
	for (int k = 0; k < logicalSize; k++)
	{
		delete arr[k];
	}
	delete[]arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		physicalSize = other.physicalSize;
		delimiter = other.delimiter;

		delete[] arr;
		logicalSize = other.logicalSize;
		arr = new T[logicalSize];
		for (int m = 0; m < logicalSize; m++)
			arr[m] = (other.arr[m]);
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator+=(T newVal)
{
	if (physicalSize == logicalSize)
	{
		physicalSize *= 2;
		T* tempArray = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
		{
			tempArray[i] = arr[i];
			arr[i] = nullptr;
		}
		delete[]arr;
		arr = tempArray;
	}
	if (logicalSize < physicalSize) {
		arr[logicalSize] = newVal;
		logicalSize++;
	}
	return *this;
}

template<class T>
int Array<T>::getArrSize() const
{
	return logicalSize;
}



template <class T>
const T& Array<T>::operator[](int index) const
{
	return (arr[index]);

}

#endif // __ARRAY_H
