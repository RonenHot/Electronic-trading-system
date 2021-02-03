#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "funcDeclaration.h"

class Buyer;
class Seller;
class BuyerSeller;

class Product {

public:
	enum eProductsCategory { WOMEN, MEN, KIDS, ELECTRIC, HOME };
	const static constexpr char* productsCategoryStr[] = { "Women", "Men", "Kids", "Electric","Home" };

public:
	Product(const string& productName, double price, Product::eProductsCategory pc);

public:
	void setName(const string& productName);
	void setCategory(Product::eProductsCategory pc);

	double getPrice() const;
	const string& getName() const;
	static long int getSerialNo();
	Product::eProductsCategory getCategory() const;

public:
	void setSeller(Seller* newSeller);
	Seller* getSeller() const;

	void showProducts() const;
	const Product& operator=(const Product& other);

private:
	Seller* _theSeller; //the Seller of this product
	string _productName;
	static long int		counter;
	long int			_serialNo;
	double              _price;
	eProductsCategory   _pc;
};

#endif // __PRODUCT_H
