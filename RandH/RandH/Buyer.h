#ifndef __BUYER_H
#define __BUYER_H

#include "order.h"
#include"User.h"
#include "Product.h"
#include "feedback.h"

class Seller;


class Buyer : virtual public User
{
public:
	Buyer(const string& buyerName, const string& buyerPassword, const Address& buyerAddress);
	Buyer(const Buyer& other);
	Buyer(Buyer&& other);
	Buyer(ifstream& inFile);

	virtual ~Buyer();

public:
	void addToCart(Product* newProduct);
	const  vector<Product*>& getCart() const;
	int getCartArrSize() const;
	void deleteFromCart(Product& newProduct);
	void deleteAllFromCart();
	double getTotalPriceCart() const;
	void setTotalPriceCart(double cartPrice);

public:
	void setFeedback(Feedback* newFeedback);
	virtual void show() const override;

public:
	//order:
	void addToCurrOrder(Order* newOrder);
	vector<Order*> getCurrOrder() const;
	int getCurrOrderArrSize() const;
	void clearCurrentOrder();

	void addToOrderHistory(Order* newOrder);
	const vector<Order*>& getOrderHistory() const;
	int getHOrderArrSize() const;

public:
	void addToSellers(const string& sellerName);
	const vector<string>& getSellers() const;
	int getSellersArrSize() const;

public:
	bool operator>(const Buyer& other) const;
	const Buyer& operator=(const Buyer& other);
	virtual void write(ofstream& outFile) const override;


protected:
	vector< Product*> _shoppingCart;
	double _cartPrice;
	vector<Order*> _currentOrder;
	vector<Order*>_orderHistory;

	Feedback* _feedback;
	vector<string> _buyFromSellers;
	string _sellerName;
};

#endif //_BUYER
