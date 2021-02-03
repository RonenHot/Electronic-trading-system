#include "order.h"

Order::Order()
{
	_buyerOrder = nullptr;
	_payment = nullptr;
}

Order::Order(const Order& other)
{
	*this = other;
}

Order::Order(Order&& other)
{
	_payment = other._payment;
	_buyerOrder = other._buyerOrder;
	_productsOrdered = other._productsOrdered;
}

Order::~Order()
{

	if (_payment != nullptr)
	{
		delete _payment;
	}
	_productsOrdered.clear();
}


void Order::addProducts(Product* addProduct)
{
	_productsOrdered.push_back(addProduct);
}

const vector<Product*>& Order::getProducts() const
{
	return _productsOrdered;
}

int Order::getOrderSize() const
{
	return (int)_productsOrdered.size();
}

void Order::setPayment(Payment* p)
{
	if (_payment != nullptr)
	{
		delete _payment;
	}
	_payment = p;
}

const Order& Order::operator=(const Order& other)
{
	if (this != &other)
	{
		_payment = nullptr;
		_payment = other._payment;
		_buyerOrder = nullptr;
		_buyerOrder = other._buyerOrder;
		_productsOrdered.clear();
		_productsOrdered = (other._productsOrdered);
	}
	return *this;
}