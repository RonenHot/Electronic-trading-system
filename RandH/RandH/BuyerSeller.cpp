#include"BuyerSeller.h"

BuyerSeller::BuyerSeller(const string& Name, const string& Password, const Address& Address)
	:User(Name, Password, Address), Buyer(Name, Password, Address), Seller(Name, Password, Address)
{
}


BuyerSeller::BuyerSeller(ifstream& inFile) : User(inFile), Buyer(inFile), Seller(inFile)
{
}

void BuyerSeller::show() const
{
	User::show();
}

void BuyerSeller::write(ofstream& outFile) const
{
	User::write(outFile);
}