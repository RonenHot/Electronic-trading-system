#include "RandH.h"

RandH::~RandH()
{
	//free all memory 

	for (int k = 0; k < _productsArr.size(); k++)
	{
		delete _productsArr[k];
	}
	_productsArr.clear();

	for (int i = 0; i < _userArr.size(); i++)
	{
		delete _userArr[i];
	}
	_userArr.clear();

}

RandH& RandH::operator+=(User& other)
{
	_userArr.push_back(&other);
	return *this;
}


void RandH::addProduct(Product* newProduct)
{
	_productsArr.push_back(newProduct);
}

const vector<Product*>& RandH::getAllProducts() const
{
	return _productsArr;
}

int RandH::getProductSize() const
{
	return (int)_productsArr.size();
}

const vector<User*>& RandH::getAllUsers() const
{
	return _userArr;
}
int RandH::getUsersSize() const
{
	return (int)_userArr.size();
}