#ifndef __SELLER_H
#define __SELLER_H

#include "product.h"
#include "feedback.h"
#include"User.h"
#include "Array.h"
class Feedback;

class Seller : virtual public User
{
public:
	Seller(const string& sellerName, const string& sellerPassword, const Address& sellerAddress);
	Seller(const Seller& other);
	Seller(Seller&& other);
	Seller(ifstream& inFile);
	virtual ~Seller();


public:
	void addProduct(Product* newProduct);
	const vector<Product*>& getAllSellerProducts() const;
	int getProductArrSize() const;
	void setProduct(Product* newProduct);

public:
	virtual void addFeedbacks(Feedback* newFeedback);
	const Array<Feedback*>& getAllFeedback() const;
	virtual int getFeedbackArrSize() const;

public:
	virtual void show() const override;

public:
	const Seller& operator=(const Seller& Seller);
	virtual void write(ofstream& outFile) const override;

protected:

	vector<Product*> _sellerProductsArr;
	Product* _product; //the product to the buyer
	Array<Feedback*> _feedback;
};
#endif // __SELLER_H