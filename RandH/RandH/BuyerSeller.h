#ifndef __BUYER_SELLER_H
#define __BUYER_SELLER_H

#include"Seller.h"
#include"Buyer.h"

class BuyerSeller : virtual public Buyer, virtual public Seller
{
public:
	BuyerSeller(const string& Name, const string& Password, const Address& Address);
	BuyerSeller(ifstream& inFile);

public:
	virtual void show() const override;
	virtual void write(ofstream& outFile) const override;
};

#endif //_BUYER_SELLER

