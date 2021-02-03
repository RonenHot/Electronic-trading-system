#ifndef __RANDH_H
#define __RANDH_H

#include "funcDeclaration.h"
#include "User.h"
#include "Product.h"

class RandH
{
public:
	
	RandH() {};
	~RandH();
	
private:
	RandH(const RandH& other);
public:

	const vector<User*>& getAllUsers() const;
	int  getUsersSize() const;

	void addProduct(Product* newProduct);
	const vector<Product*>& getAllProducts() const;
	int  getProductSize() const;

public:
	RandH& operator+=(User& other);

private:
	vector<Product*> _productsArr;
	vector<User*> _userArr;
};
#endif // _RandH_H
