#include "product.h"
#include "seller.h"
long int Product::counter = 1000;


Product::Product(const string& productName, double price, Product::eProductsCategory pc)
{
	_price = price;
	_theSeller = nullptr;
	setName(productName);
	setCategory(pc);
	_serialNo = ++counter;
}


//-----------------------------------------------------//
void Product::setName(const string& productName)
{
	_productName = productName;
}

const string& Product::getName() const
{
	return _productName;
}

//--------------------------------------------------//
long int Product::getSerialNo() //static function no const
{
	return counter;
}

//---------------------------------------------------//
double Product::getPrice() const
{
	return _price;
}

//------------------------------------------------//

void Product::setCategory(Product::eProductsCategory pc)
{
	_pc = pc;
}

Product::eProductsCategory Product::getCategory() const
{
	return _pc;
}

//------------------------------------------------------------------------------//

void Product::setSeller(Seller* newSeller)
{
	if (_theSeller != newSeller) //if the current buyer is not the new buyer
	{
		if (_theSeller != nullptr) //if the buyer is exist
			_theSeller->setProduct(nullptr); //set the buyer to nullptr

		_theSeller = newSeller;
		if (_theSeller != nullptr)
			_theSeller->setProduct(this);
	}
}
Seller* Product::getSeller() const
{
	return _theSeller;
}

void Product::showProducts() const
{
	cout << "product name: " << _productName << "\t" << "price: " << _price << "\t" << "serial number: " << _serialNo << endl;
}


const Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		setName(other._productName);
		setCategory(other._pc);
		_price = other._price;
		_theSeller = nullptr;
		_theSeller = other._theSeller;
	}
	return *this;
}
