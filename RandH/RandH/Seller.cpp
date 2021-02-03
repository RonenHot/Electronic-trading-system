#include "seller.h"

Seller::Seller(const string& sellerName, const string& sellerPassword, const Address& sellerAddress)
	:User(sellerName, sellerPassword, sellerAddress)
{
	_product = nullptr;
}

Seller::Seller(const Seller& other)
	: User(other)
{
	*this = other;
}

Seller::Seller(Seller&& other) : User(move(other))
{
	_sellerProductsArr = other._sellerProductsArr;
	_feedback = other._feedback;
	_product = other._product;
}

//--------------------------------------------------------------------------------//
Seller::~Seller()
{
	_sellerProductsArr.clear();
}
//--------------------------------------------------------------------------------//

void Seller::addProduct(Product* newProduct)
{
	_sellerProductsArr.push_back(newProduct);
}

const vector<Product*>& Seller::getAllSellerProducts() const
{
	return _sellerProductsArr;
}

int Seller::getProductArrSize() const
{
	return (int)_sellerProductsArr.size();
}

void Seller::setProduct(Product* newProduct)
{
	if (_product != newProduct)
	{
		_product = newProduct;
		if (_product != nullptr)
			_product->setSeller(this);
	}
}
//---------------------------------------------//
void Seller::addFeedbacks(Feedback* newFeedback)
{
	_feedback += newFeedback;
}

const Array<Feedback*>& Seller::getAllFeedback() const
{
	return _feedback;
}

int Seller::getFeedbackArrSize() const
{
	return  _feedback.getArrSize();

}
//--------------------------------------//

void Seller::show() const
{
	User::show();
}

const Seller& Seller::operator=(const Seller& other)
{
	if (this != &other)
	{
		User::operator=(other);
		_sellerProductsArr.clear();
		_sellerProductsArr = other._sellerProductsArr;
		_feedback = other._feedback;
		_product = nullptr;
		_product = other._product;
	}
	return *this;
}

void Seller::write(ofstream& outFile) const
{
	User::write(outFile);
}

Seller::Seller(ifstream& inFile) : User(inFile)
{
}