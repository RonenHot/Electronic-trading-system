#ifndef __ORDER_H
#define __ORDER_H

#include "funcDeclaration.h"
#include "Payment.h"

class Product;
class Buyer;
class Payment;

class Order {

public:
	Order();
	Order(const Order& other);
	Order(Order&& other);
	~Order();

public:
	void addProducts(Product* addProduct);
	const vector<Product*>& getProducts() const;
	int getOrderSize() const;

public:
	void setPayment(Payment* p);

	const Order& operator=(const Order& other);

private:
	vector<Product*> _productsOrdered;
	Buyer* _buyerOrder;
	Payment* _payment;
};

#endif // __ORDER_H