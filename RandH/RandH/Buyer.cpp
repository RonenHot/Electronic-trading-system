#include "buyer.h"


Buyer::Buyer(const string& buyerName, const string& buyerPassword, const Address& buyerAddress)
	:User(buyerName, buyerPassword, buyerAddress)
{
	_cartPrice = 0;
	//------//
	_feedback = nullptr;
}

//-------------------------//
Buyer::Buyer(const Buyer& other)
	:User(other)
{
	*this = other;
}

Buyer::Buyer(Buyer&& other) : User(move(other))
{
	_sellerName = other._sellerName;
	_feedback = other._feedback;
	_shoppingCart = other._shoppingCart;
	_cartPrice = other._cartPrice;
	_orderHistory = other._orderHistory;
	_currentOrder = other._currentOrder;
	_buyFromSellers = other._buyFromSellers;

	other._feedback = nullptr;

}

//--------------------------------------------------------------------------------//
Buyer::~Buyer()
{
	vector<Order*>::const_iterator itr = this->_orderHistory.begin();
	vector<Order*>::const_iterator itrEnd = this->_orderHistory.end();
	for (; itr != itrEnd; ++itr)
		delete *itr;

	vector<Order*>::const_iterator itr1 = this->_currentOrder.begin();
	vector<Order*>::const_iterator itrEnd1 = this->_currentOrder.end();
	for (; itr1 != itrEnd1; ++itr1)
		delete* itr1;

	_shoppingCart.clear();
	_buyFromSellers.clear();
}
//--------------------------------------------------------------------------------//

void Buyer::addToCart(Product* newProduct)
{
	_shoppingCart.push_back(newProduct);
}

const vector<Product*>& Buyer::getCart() const
{
	return _shoppingCart;
}

int  Buyer::getCartArrSize() const
{
	return (int)_shoppingCart.size();
}

void Buyer::deleteAllFromCart()
{
	_shoppingCart.clear();
}

void Buyer::deleteFromCart(Product& newProduct)
{
	vector<Product*> tempCart;
	vector<Product*>::iterator itrBegin = _shoppingCart.begin();
	vector<Product*>::iterator itrEnd = _shoppingCart.end();
	for (; itrBegin != itrEnd; ++itrBegin)
	{
		if (*itrBegin != &newProduct)
		{
			tempCart.push_back(*itrBegin);
			*itrBegin = nullptr;
		}
	}
	_shoppingCart.clear();
	_shoppingCart = tempCart;
	tempCart.clear();
}

double Buyer::getTotalPriceCart() const
{
	return _cartPrice;
}
void Buyer::setTotalPriceCart(double cartPrice)
{
	_cartPrice = cartPrice;
}

//------------------------------------------------//
void Buyer::addToCurrOrder(Order* newOrder)
{
	_currentOrder.push_back(newOrder);
}

vector<Order*> Buyer::getCurrOrder() const
{
	return _currentOrder;
}

int Buyer::getCurrOrderArrSize() const
{
	return (int)_currentOrder.size();
}

void Buyer::clearCurrentOrder()
{
	vector<Order*>::const_iterator itr = this->_currentOrder.begin();
	vector<Order*>::const_iterator itrEnd = this->_currentOrder.end();
	for (; itr != itrEnd; ++itr)
		delete* itr;

	_currentOrder.clear();
}

void Buyer::addToOrderHistory(Order* newOrder)
{
	_orderHistory.push_back(newOrder);
}

const vector<Order*>& Buyer::getOrderHistory() const
{
	return _orderHistory;
}

int Buyer::getHOrderArrSize() const
{
	return (int)_orderHistory.size();
}

void Buyer::addToSellers(const string& sellerName)
{
	bool sellerExist = true;
	_sellerName = sellerName;

	if (_buyFromSellers.size() > 0) {
		for (int i = 0; i < _buyFromSellers.size(); i++)
		{  //if the name of the seller is already exist
			if (_buyFromSellers[i] == sellerName)
				sellerExist = false;
		}
	}
	if (sellerExist == true) {
		_buyFromSellers.push_back(sellerName);
	}
}

const vector<string>& Buyer::getSellers() const
{
	return _buyFromSellers;
}

int Buyer::getSellersArrSize() const
{
	return (int)_buyFromSellers.size();
}

void Buyer::setFeedback(Feedback* newFeedback)
{
	if (_feedback != newFeedback)
	{
		_feedback = newFeedback;
		if (_feedback != nullptr)
			_feedback->setBuyer(*this);
	}
}

//----------------------------//
void Buyer::show() const
{
	User::show();
}

//return if the left has bigger price of shopping cart
bool Buyer::operator>(const Buyer& other) const
{
	return ((*this)._cartPrice > other._cartPrice);
}

const Buyer& Buyer::operator=(const Buyer& other)
{
	if (this != &other)
	{
		User::operator=(other);
		_currentOrder.clear();
		_currentOrder = (other._currentOrder);
		_shoppingCart.clear();
		_shoppingCart = other._shoppingCart;
		_orderHistory.clear();
		_orderHistory = other._orderHistory;
		//The sellers that the buyer bought from them
		_buyFromSellers.clear();
		_buyFromSellers = other._buyFromSellers;
	}
	return *this;
}
void Buyer::write(ofstream& outFile) const
{
	User::write(outFile);
}

Buyer::Buyer(ifstream& inFile) : User(inFile)
{
}