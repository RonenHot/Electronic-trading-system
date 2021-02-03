#include "mainDecler.h"

const int LEN = 22; //max for name string

int main()
{
	{
		RandH sys; //the name of the system - R and H
		cout << "Hello, Welcome to R&H " << endl;
		
		int numOfUsers = 0;
		loadAllUsers("RonenAndHen.txt", numOfUsers, sys);
		
		printMenu(sys);
	}
	return 0;
}

//----------------------------------------------------------------------//
void printMenu(RandH& sys)
{
	bool isOverFlow = false;
	int login, newBos; //Bos- buyer or seller
	cout << "Menu:\n";
	cout << "New user - to register press 1 \nUser exist - to enter press 2\n";
	cout << "Press 3 to view all buyer information\n";
	cout << "Press 4 to view all seller information\n";
	cout << "Press 5 to view all buyer - seller information\n";
	cout << "Press 6 to view a specific user\n";
	cout << "Press 7 to view all products with a specific name\n";
	cout << "Press 8 to view the realization of the operators\n";
	cout << "Press 9 to EXIT\n";
	cin >> login;
	if (login > 9 || login < 1)
	{
		cout << "wrong input, please try again\n";
		printMenu(sys);
	}
	system("cls");

	switch (login)
	{
	case 1:
		cout << "Buyer user - press 1\n";
		cout << "Seller user - press 2\n";
		cout << "Buyer-Seller user - press 3\n";
		cin >> newBos;

		switch (newBos)
		{
		case 1:
			isOverFlow = readUser(sys, BUYER);
			break;

		case 2:
			isOverFlow = readUser(sys, SELLER);
			break;
		case 3:
			isOverFlow = readUser(sys, BUYERSELLER);
			break;

		default:
			cout << "wrong input\n";
			break;
		}
		if (isOverFlow == OverFlow)
		{
			break;
		}
		printMenu(sys);
		break;

	case 2:
		int indexExist, Bos;
		cout << "log in: \n";
		isOverFlow = logIn(sys, indexExist, Bos);
		//return the index that belong to the user
		if (isOverFlow == OverFlow)
		{
			break;
		}
		if (indexExist == ERROR)
		{
			system("cls");
			cout << "The user does not exist in the system" << endl;
			printMenu(sys);
		}
		else
		{ //Routing each user to the appropriate menu
			system("cls");
			cout << "Hi, " << (sys.getAllUsers()[indexExist]->getName()) << endl;
			if (Bos == BUYER)
			{
				Buyer* b = dynamic_cast<Buyer*>((sys.getAllUsers())[indexExist]);
				isOverFlow = buyerMenu(sys, b);
			}
			if (Bos == SELLER)
			{
				Seller* s = dynamic_cast<Seller*>((sys.getAllUsers())[indexExist]);
				isOverFlow = sellerMenu(sys, s);
			}
			if (Bos == BUYERSELLER)
			{
				int bsSelect;
				BuyerSeller* bs = dynamic_cast<BuyerSeller*>((sys.getAllUsers())[indexExist]);

				bsSelect = BSmenu();
				while (bsSelect != ERROR)
				{
					switch (bsSelect)
					{
					case SELLER:
						isOverFlow = sellerMenu(sys, bs);
						if (!isOverFlow)
						{
							bsSelect = BSmenu();
						}
						break;
					case BUYER:
						isOverFlow = buyerMenu(sys, bs);
						if (!isOverFlow)
						{
							bsSelect = BSmenu();
						}
						break;
					case ERROR:
						break;
					}
				}
			}
			if (isOverFlow == OverFlow)
			{
				break;
			}
			printMenu(sys);
			break;
		}
		break;

	case 3:
		//view all buyer information
		if (sys.getUsersSize() > EMPTY)
		{
			for (int i = 0; i < sys.getUsersSize(); i++)
			{
				if (typeid(*(sys.getAllUsers()[i])) == typeid(Buyer))
				{
					(sys.getAllUsers()[i])->show();
					cout << "\n";
				}
			}
		}
		else
		{
			cout << "there are no buyers in the system\n";
		}
		printMenu(sys);
		break;

	case 4:
		//view all seller information
		if (sys.getUsersSize() > EMPTY)
		{
			for (int i = 0; i < sys.getUsersSize(); i++)
			{
				if (typeid(*(sys.getAllUsers()[i])) == typeid(Seller))
				{
					(sys.getAllUsers()[i])->show();
					cout << "\n";
				}
			}
		}
		else {
			cout << "there are no sellers in the system\n";
		}
		printMenu(sys);
		break;
	case 5:
		//view all buyer- seller information
		if (sys.getUsersSize() > EMPTY)
		{
			for (int i = 0; i < sys.getUsersSize(); i++)
			{
				if (typeid(*(sys.getAllUsers()[i])) == typeid(BuyerSeller))
				{
					(sys.getAllUsers()[i])->show();
					cout << "\n";
				}
			}
		}
		else {
			cout << "there are no buyer- seller users in the system\n";
		}
		printMenu(sys);
		break;
	case 6:
		//view a specific users (buyer\seller\buyer-seller)
		int sUser;
		if (sys.getUsersSize() > EMPTY)
		{
			cout << "Enter user type:\n0- Seller\n1- Buyer\n2- Buyer-Seller\n";
			cin >> sUser;
			if (sUser == SELLER || sUser == BUYER || sUser == BUYERSELLER)
			{
				for (int i = 0; i < sys.getUsersSize(); i++)
				{
					if ((sUser == SELLER) && (typeid(*(sys.getAllUsers()[i])) == typeid(Seller)))
					{
						sys.getAllUsers()[i]->show();
					}
					else if ((sUser == BUYER) && (typeid(*(sys.getAllUsers()[i])) == typeid(Buyer)))
					{
						sys.getAllUsers()[i]->show();
					}
					else if ((sUser == BUYERSELLER) && (typeid(*(sys.getAllUsers()[i])) == typeid(BuyerSeller)))
					{
						sys.getAllUsers()[i]->show();
					}
				}
			}
			else
			{
				cout << "wrong input\n";
			}
		}

		else
		{
			cout << "no users exists at the system\n";
		}
		printMenu(sys);
		break;

	case 7:
		//view all products with a specific name
		isOverFlow = showProducts(sys);
		if (isOverFlow == OverFlow)
		{
			break;
		}
		printMenu(sys);
		break;

	case 8:
		//view therealization of the operators
		checkOperators();

		printMenu(sys);
		break;
	case 9:
	
		cout << "Goodbye, Looking forward to see you again";
		{

			ofstream outFile("RonenAndHen.txt", ios::trunc);

			if (sys.getUsersSize() == EMPTY)
			{
				outFile << EMPTY << endl;
			}

			else
			{
				outFile << sys.getUsersSize() << endl;

				for (int i = 0; i < sys.getUsersSize(); i++)
				{
					(sys.getAllUsers()[i])->write(outFile);
				}
			}

			outFile.close();
		
		}

		break;
	default:
		cout << "wrong input\n";
		break;
	}
}


//the function get from the user his data (name, password, address, etc)
bool readUser(RandH& sys, int user)
{
	bool isOverflow = false;
	string tempPS;
	string tempN;
	cin.ignore(); // clean the buffer
	cout << "please enter username (Up to 20 characters): \n";
	getline(cin, tempN);
	//cin.getline(tempN, LEN);
	checkLength(tempN);
	if (isOverflow == OverFlow)
	{
		return OverFlow;
	}
	//Check that the name does not appear in the array
	while (!(checkName(sys, tempN)))
	{
		cout << "This username is already occupied, please choose another name: ";
		getline(cin, tempN);
		checkLength(tempN);
		if (isOverflow == OverFlow)
		{
			return OverFlow;
		}
	}
	cout << "please enter your password (Up to 20 characters):\n";
	getline(cin, tempPS);
	isOverflow = checkLength(tempPS);
	if (isOverflow == OverFlow)
	{
		return OverFlow;
	}
	string AC;
	string AS;
	cout << "please enter your addrees  (Up to 20 characters):\n";
	cout << "City: \n";
	getline(cin, AC);

	isOverflow = checkLength(AC);
	if (isOverflow == OverFlow)
	{
		return OverFlow;
	}
	cout << "Street Name : \n";
	getline(cin, AS);

	isOverflow = checkLength(AS);
	if (isOverflow == OverFlow)
	{
		return OverFlow;
	}
	int AH;
	cout << "House number : " << endl;
	cin >> AH;

	//create the user:
	if (user == BUYER)
	{
		User* user = new Buyer(tempN, tempPS, Address(AC, AS, AH));
		sys += *user;
	}
	if (user == SELLER)
	{
		User* user = new Seller(tempN, tempPS, Address(AC, AS, AH));
		sys += *user;
	}
	if (user == BUYERSELLER)
	{
		User* user = new BuyerSeller(tempN, tempPS, Address(AC, AS, AH));
		sys += *user;
	}
	return isOverflow;
}

//Check that the username does not appear in the array
bool checkName(RandH& sys, const string& name)
{
	if (sys.getUsersSize() > 0)
	{
		for (int i = 0; i < sys.getUsersSize(); i++)
		{
			if ((sys.getAllUsers()[i]->getName()) == name)
				return false;
		}
	}
	return true;
}

//the function get system and bool parameter that point on buyer/seller (isFound)
//and ask the user to enter his data, if the user exist , the function return user index
bool logIn(RandH& sys, int &userIndex, int& Bos)
{
	bool isOverflow = false;
	string tempPS;
	string tempN;
	cin.ignore(); // clean the buffer
	cout << "User name: \n";
	getline(cin, tempN);
	isOverflow = checkLength(tempN);
	if (isOverflow == OverFlow)
	{
		return OverFlow;
	}
	cout << "Password: \n";
	getline(cin, tempPS);
	isOverflow = checkLength(tempPS);
	if (isOverflow == OverFlow)
	{
		return OverFlow;
	}
	//if the user exist, return it's index from array (buyer\seller) 
	bool res = false;
	res = isExist(sys, userIndex, tempN, tempPS, Bos);
	//function that search the user at buyer\seler array
	if (res != EXISTS)
	{
		userIndex = ERROR; //"user not exist"
	}
	return isOverflow;
}

//The function checks whether the user exists on the system,
//compares the user's name and password, with existing users on the system
bool isExist(const RandH& sys, int& index, const string& username, const string& password, int& Bos)
{
	//Bos- to know who to return the buyer\seller\buyer-seller
	for (int i = 0; i < (sys.getUsersSize()); i++)
	{
		if (((sys.getAllUsers()[i]->getName()) == username) && ((sys.getAllUsers()[i]->getPassword()) == password))
		{
			index = i;
			if (typeid(*(sys.getAllUsers()[i])) == typeid(Buyer))
			{
				Bos = BUYER;
			}
			else if (typeid(*(sys.getAllUsers()[i])) == typeid(Seller))
			{
				Bos = SELLER;
			}
			else if (typeid(*(sys.getAllUsers()[i])) == typeid(BuyerSeller))
			{
				Bos = BUYERSELLER;
			}
			return EXISTS;
		}
	}
	return false;
}

//------------------------------------------------------------------------------------------------//
bool sellerMenu(RandH& sys, Seller* s)
{
	bool isOverflow = false;
	int sellerchose;
	Product* p1;
	cout << "Press 1 to add a product \n";
	cout << "Press 2 to see your customer feedback \n";
	cout << "Press 3 to log out \n";
	cin >> sellerchose;
	system("cls");

	switch (sellerchose)
	{
	case 1:
		/*create product, insert the product into the seller's array,
		and into the array of all products in the sys */
		p1 = readProduct(&isOverflow);
		if (isOverflow == OverFlow)
		{
			break;
		}
		p1->setSeller(s); //set the seller at the product details
		s->addProduct(p1); //add the product to the seller
		sys.addProduct(p1); //add the product to the sysytem products array 

		system("cls");
		cout << "The product has been successfully added\n";
		sellerMenu(sys, s);
		break;
	case 2:
		if (s->getFeedbackArrSize() == EMPTY)
		{
			cout << "No feedbacks yet" << endl;
		}
		else
		{
			for (int i = 0; i < s->getFeedbackArrSize(); i++)
			{

				cout << *(s->getAllFeedback()[i]);

			}
		}
		sellerMenu(sys, s);
		break;
	case 3:
		break;
	default:
		cout << "wrong input" << endl;
		sellerMenu(sys, s);
		break;
	}

	return isOverflow;
}

//create new product , get the data from seller user
Product* readProduct(bool *isOverflow)
{
	*isOverflow = false;
	int categoryCh;
	categoryCh = categoryChoose();
	string name;
	cin.ignore(); // clean the buffer
	cout << "Enter product name (Up to 20 characters): ";
	getline(cin, name);
	*isOverflow = checkLength(name);
	if (*isOverflow == OverFlow)
	{
		return nullptr;
	}
	double price;
	cout << "Enter price: ";
	cin >> price;
	while (price <= 0)
	{
		cout << "Negative or zero price cannot be entered, please try again: ";
		cin >> price;
	}

	return new Product(name, price, (Product::eProductsCategory)categoryCh);
}
//-----------------------------------------------------------------------------------------------------------//
bool buyerMenu(RandH& sys, Buyer* b)
{
	bool isOverFlow = false;
	int buyerchoose;
	cout << "Press 1 to add a product to the shopping cart\n";
	cout << "Press 2 to place an order  \n";
	cout << "Press 3 to payment for an existing order \n";
	cout << "Press 4 to add feedback to the seller\n";
	cout << "Press 5 to Log out \n";
	cin >> buyerchoose;
	system("cls");

	switch (buyerchoose)
	{
	case 1:
		//add a product to the shopping cart:	
		int categoryNum;
		categoryNum = categoryChoose();
		if ((sys.getProductSize()) > 0) 	//if there are products in the system:
		{
			int counterProducts = 0;
			for (int i = 0; i < (sys.getProductSize()); i++)
			{
				if (((sys.getAllProducts())[i]->getCategory()) == categoryNum)
				{
					counterProducts++;
					sys.getAllProducts()[i]->showProducts();
					cout << "if you want to add this product to the shopping cart press '1', else press '0' : \n";
					cin >> buyerchoose;
					if (buyerchoose == 1) {
						Product* tempP1 = (sys.getAllProducts())[i];

						//add to the shopping cart the product that the buyer chose;
						b->addToCart(tempP1);
						cout << "The product has been successfully added" << endl;
					}

				}
			}
			if (counterProducts == 0)
			{
				cout << "The list is empty, There are no products related to the category\n";
			}
		}
		else
		{
			cout << "There are no products related to the category\n";
		}
		if (b->getCartArrSize() > EMPTY)
		{//set the price of all the products that belong to the shopping cart
			b->setTotalPriceCart(calculateTotal(b, SHOPCART));
		}
		buyerMenu(sys, b); //back to the buyer menu
		break;

	case 2:
		//place an order:
		int buyerOrder; //buyer choose
		if ((b->getCurrOrderArrSize() > 0)) //if there is order exist
		{
			cout << "You have an existing order\n";
			cout << "to make a new order press 1 -  (The existing order will be deleted)\n";
			cout << "back to menu press 2\n";
			cin >> buyerOrder;
			if (buyerOrder == 1)
			{
				isOverFlow = makeNewOrder(b);
				if (isOverFlow == OverFlow)
				{
					break;
				}
			}
		}
		else if ((b->getCartArrSize()) <= 0)
		{
			system("cls");
			cout << "Sorry, your shopping cart is empty, order cannot be placed\n";
		}

		else if ((b->getCurrOrderArrSize() == 0) && ((b->getCartArrSize()) > 0))
		{
			isOverFlow = makeNewOrder(b);
			if (isOverFlow == OverFlow)
			{
				break;
			}
		}
		buyerMenu(sys, b);
		break;

	case 3:
		//payment
		if (b->getCurrOrderArrSize() > EMPTY)
		{
			bool payNow;
			payNow = payment(b, &isOverFlow);
			if (isOverFlow == OverFlow)
			{
				return OverFlow;
			}
			if (payNow == true) //succsesfull payment
			{
				system("cls");
				cout << "\nThank you! Your order was successfully paid" << endl;

				//move all the products that the buyer buy from his shopping cart to the order history
				moveToOrderHistory(b, b->getCurrOrder(), (int)(b->getCurrOrder().size()));
				b->clearCurrentOrder();
				//add the order to the buyer order history

			}
			else
			{
				cout << "\n your order will be save" << endl;
			}
		}
		else {
			cout << "\n no order exist" << endl;
		}
		buyerMenu(sys, b);
		break;
	case 4:
		//feedback:
		bool add;
		add = buyerAddFeedback(sys, b);
		if (add == OverFlow)
		{
			return OverFlow;
		}
		buyerMenu(sys, b);
		break;

	case 5:
		break;

	default:
		cout << "wrong input" << endl;
		buyerMenu(sys, b);
		break;
	}
	return isOverFlow;
}

//---------------------------------//
//Buyer- Seller menu:
int BSmenu()
{
	int bsSelect;
	cout << "Select a menu :\n To the buyer menu press 1\n To the seller menu press 0\n To exit press -1\n";
	cin >> bsSelect;

	if (bsSelect > 1 || bsSelect < -1) {
		cout << "wrong input\n";
		return ERROR;
	}
	return bsSelect;
}

//----------------------------------------------------------------------------------------------//
//order and payment functions:

bool makeNewOrder(Buyer* b)
{
	bool isOverFlow = false;
	bool res = false;
	int newOrder;
	system("cls");
	cout << "These are the products in your shopping cart:\n";
	for (int c = 0; c < (b->getCartArrSize()); c++)
	{
		cout << c << "- ";
		b->getCart()[c]->showProducts();
	}
	cout <<
		"To select all for payment press 1\n" <<
		"To select specific products for payment press 2 \n";
	cin >> newOrder;
	if (newOrder == 1)
	{	//Transfer products from shopping cart to order
		moveToCurrentOrder(b, b->getCart(), b->getCartArrSize());
		//delete from the shopping cart the products that payed //empty all the shopping cart 
		b->deleteAllFromCart();
		//Receives credit card details from buyer:
		res = payment(b, &isOverFlow);
		if (isOverFlow == OverFlow)
		{
			return OverFlow;
		}
		if (res == true) //succsesfull payment
		{
			system("cls");
			cout << "\nThank you! Your order was successfully paid" << endl;
			//move all the products that the buyer buy from he shopping cart to the order history
			moveToOrderHistory(b, b->getCurrOrder(), (int)(b->getCurrOrder().size()));
			b->clearCurrentOrder();
			//add the order to the buyer order history
		}
		else
		{
			cout << "\n your order will be save" << endl;
		}
	}
	else if (newOrder == 2)
	{ 	//select specific products for payment:
		int buyProduct;
		Order* tempO = new Order;
		system("cls");
		cout << "For each product, if you want to buy the product now, enter '1', else enter '0' :\n";
		for (int c = 0; c < (b->getCartArrSize()); c++)
		{
			cout << c << "- ";
			b->getCart()[c]->showProducts();
			cin >> buyProduct;
			if (buyProduct == 1)
			{
				Product* p = b->getCart()[c];
				tempO->addProducts(p);
				b->deleteFromCart(*p);
				c--;
			}
		}
		if (tempO->getOrderSize() > 0)
		{
			int payOback;
			b->addToCurrOrder(tempO);
			cout << "your order is ready, to switch to payment press 1\n";
			cout << "Back to the menu without paying, (the order will be saved.)  press 2\n ";
			cin >> payOback;
			if (payOback == 1)
			{
				res = payment(b, &isOverFlow);
				if (isOverFlow == OverFlow)
				{
					return OverFlow;
				}
				if (res == true) //succsesfull payment
				{
					system("cls");
					cout << "\nThank you! Your order was successfully paid" << endl;
					//move all the products that the buyer buy from he shopping cart to the order history

					moveToOrderHistory(b, b->getCurrOrder(), (int)(b->getCurrOrder().size()));
					b->clearCurrentOrder();
					//add the order to the buyer order history
				}
				else
				{
					cout << "\n you order will be save" << endl;
				}
			}
		}
		else
		{
			system("cls");
			cout << "No shopping cart items selected, no order placed\n";
			delete tempO;
		}
	}
	return isOverFlow;
}

//move all the products that the buyer buy from he shopping cart to the current order 
void moveToCurrentOrder(Buyer *b, vector<Product*>pcurr, int sizeCurr)
{
	Order* currO = new Order;
	for (int i = 0; i < sizeCurr; i++)
	{
		currO->addProducts(pcurr[i]);
	}
	b->addToCurrOrder(currO);
}

bool payment(Buyer* b, bool* isOverFlow)
{
	*isOverFlow = false;
	bool resCredit = false;
	double sumCalculate;// sum of the products price
	// Calculate the sum of all products 			
	sumCalculate = calculateTotal(b, ORDER);
	cout << "For your order, a total amount to pay is: " << sumCalculate << "$" << endl;
	//Receives credit card details from buyer:
	Payment* p = readCredit(sumCalculate, &resCredit, isOverFlow);
	if (*isOverFlow == OverFlow)
	{
		return OverFlow;
	}
	if (resCredit == true)
	{

		b->getCurrOrder()[0]->setPayment(p);
		//set the payment in the order
		return resCredit;
	}
	return resCredit;
}
//The function calculates the total price of the order/ shopping cart:
double calculateTotal(Buyer* b, bool type)
{
	double res = 0;
	if (type == SHOPCART)
	{
		for (int i = 0; i < b->getCartArrSize(); i++)
		{
			res += (b->getCart()[i]->getPrice());
		}
		return res;
	}
	else
	{
		for (int i = 0; i < b->getCurrOrder().size(); i++)
		{
			res += (b->getCurrOrder()[i]->getProducts()[i]->getPrice());
		}
		return res;
	}
}

//The function transfers the order after payment to the order history
void moveToOrderHistory(Buyer *b, vector<Order*> o, int size)
{
	Order* temp = new Order;
	for (int i = 0; i < size; i++)
	{
		temp->addProducts(o[0]->getProducts()[i]);
		//add the seller name to the buyer calss(for feedback):
		b->addToSellers(o[0]->getProducts()[i]->getSeller()->getName());
	}
	b->addToOrderHistory(temp);
}

//Function Reads Credit Information From Buyer and return new payment:
Payment* readCredit(double total, bool *resCredit, bool *isOverFlow)
{
	//for credit card
	string cardHoldersName;
	int creditNumber;
	short int cvv;
	int month, year;

	cin.ignore(); // clean the buffer
	cout << "Please enter credit details:\n";
	cout << "Cardholder's name:  (Up to 20 characters) ";
	getline(cin, cardHoldersName);
	*isOverFlow = checkLength(cardHoldersName);
	if (*isOverFlow == OverFlow)
	{
		return nullptr;
	}
	cout << "\nCredit card number: ";
	cin >> creditNumber;
	cout << "\ncvv :"; cin >> cvv;
	cout << "\nExpiry Date:\n month :";
	cin >> month; cout << "\nyear: "; cin >> year;

	int countTry = 0;
	while ((month > 12 || month < 0) || (year < 2020))
	{
		cout << "You cannot make an order payment" <<
			"- Expiry Date issue- \n";

		cout << "please try again: \n";
		cout << "\nExpiry Date:\n month :";
		cin >> month; cout << "\nyear: "; cin >> year;
		countTry++;
		if (countTry == 3)
		{
			cout << "Too many attempts, \n";
			*resCredit = false;
			return nullptr;
		}
	}
	*resCredit = true;
	return new Payment(total, CreditCard(cardHoldersName, creditNumber, cvv, Date(month, year)));
}

//-----------------------------------------------------------------------------------------------//
//The function receives feedback from the buyer and returns a new feedback:
Feedback* addFeedback(Buyer* b, bool *isOverFlow)
{
	string assessment;
	cin.ignore();
	cout << "Please enter your assessment: (Up to 150 characters) \n";
	getline(cin, assessment);

	return new Feedback(assessment, Date(), *b);
}
//The function prints the existing categories and returns the user selection:
int categoryChoose()
{
	cout << " Choose a category: \n";
	int categoryNum;
	for (int j = 0; j < CATEGORY; j++)
	{
		cout << j << "-" << Product::productsCategoryStr[j] << "\n";
	}
	cin >> categoryNum;
	while (categoryNum<EMPTY || categoryNum>(CATEGORY - 1))
	{
		cout << "Invalid input, please try entering the category number again" << endl;
		cin >> categoryNum;
	}
	return categoryNum;
}


//the function check if the buyer can add a feedback- if he have order history 
//the buyer need to choose the seller to give him feedback
bool buyerAddFeedback(RandH& sys, Buyer* b)
{
	bool add = false;
	if (b->getHOrderArrSize() == EMPTY)
	{
		cout << "only members with order history are able to add a feedback\n";
	}
	else
	{
		int sellerIName; //seller index name
		system("cls");
		cout << "Please select the seller for whom you want to give feedback:\n";
		for (int i = 0; i < b->getSellersArrSize(); i++)
		{
			cout << i << " - " << b->getSellers()[i] << endl;
		}
		cin >> sellerIName;
		if (sellerIName<0 || sellerIName>((b->getSellersArrSize()) - 1))
		{
			cout << "Invalid input\n";
		}
		else
		{ //add the feedback
			bool isOverflow = false;

			Feedback* f = addFeedback(b, &isOverflow);
			if (isOverflow == OverFlow)
			{
				return OverFlow;
			}
			b->setFeedback(f);
			for (int i = 0; i < (sys.getUsersSize()); i++)
			{
				if ((sys.getAllUsers()[i]->getName()) == (b->getSellers()[sellerIName]))
				{
					Seller* temp = dynamic_cast<Seller*>((sys.getAllUsers()[i]));
					if (temp) //if not null
						temp->addFeedbacks(f);
				}
			}
			cout << "The feedback has been successfully added\n" << endl;
		}
	}
	return add;
}

//show the product (by product name) that exists in the system 
bool showProducts(RandH& sys)
{
	int counter = 0;
	bool isOverFlow = false;
	string tempName;
	cin.ignore();
	cout << "please enter the name of the product (Up to 20 characters): \n";
	getline(cin, tempName);
	isOverFlow = checkLength(tempName);
	if (isOverFlow == OverFlow)
	{
		return OverFlow;
	}

	if (sys.getProductSize() > EMPTY)
	{
		cout << "Search results for this name: \n";
		for (int i = 0; i < sys.getProductSize(); i++)
		{
			if ((sys.getAllProducts()[i]->getName()) == tempName)
			{
				sys.getAllProducts()[i]->showProducts();
				counter++;
			}
		}
		if (counter == EMPTY)
		{
			cout << "No product found for the entered name.\n";
		}
	}

	else
	{
		cout << "No product found for the entered name.\n";
	}
	return isOverFlow;
}

//The function checks for overflow
bool checkLength(const string& word)
{
	if (word.length() > (LEN))
	{
		cout << "Overflow occured. Restart Application" << endl;
		return OverFlow;
	}
	return false;
}

void checkOperators()
{
	int op;
	cout << "1- operator <<\n";
	cout << "2- operator >\n";
	cout << "3- operator +=\n";
	cin >> op;
	if (op < 1 || op>3)
	{
		cout << "wrong input\n";
	}
	else
	{
		switch (op)
		{
		case 1:
			// operator << : //feedback, date, address
		{
			Date Dbdika;
			Address Abdika("TLV", "MTA ", 2);
			Buyer Bbdika("Chen and Ronen", "12345", Abdika);
			Feedback Fbdika(" Thank you for checking out our project, have a good day! :)", Dbdika, Bbdika);

			cout << "Date operator << : " << Dbdika << endl;
			cout << "FeedBack and Address operator << :\n" << Fbdika;
			cout << "see you later at: ";
			cout << Abdika;
		}

		break;
		case 2:
			//operator > :
		{
			Address Abdika("TLV", "MTA, building ", 2);
			Buyer Bbdika1("Chen", "12345", Abdika);
			Buyer Bbdika2("Ronen", "12345", Abdika);
			Product Pbdika1("c++ project", 1, (Product::eProductsCategory) 3);
			Product Pbdika2("c++ project", 100.5, (Product::eProductsCategory) 3);

			Bbdika1.addToCart(&Pbdika1);

			Bbdika1.setTotalPriceCart(calculateTotal(&Bbdika1, SHOPCART));
			Bbdika2.addToCart(&Pbdika2);
			Bbdika2.setTotalPriceCart(calculateTotal(&Bbdika2, SHOPCART));

			if (Bbdika2 > Bbdika1)
			{
				cout << "Yay !! , the operator '>' works\n";
				cout << "The shopping cart price of the buyer : " << Bbdika2.getName() << " is : " << Bbdika2.getTotalPriceCart() << endl;
				cout << "The shopping cart price of the buyer : " << Bbdika1.getName() << " is : " << Bbdika1.getTotalPriceCart() << endl;
				cout << Bbdika2.getTotalPriceCart() << " > " << Bbdika1.getTotalPriceCart() << endl;
			}
			else {
				cout << "opss, the operator '>' is not working\n";
			}
		}
		break;
		case 3:
			//operator += : 
		{
			RandH Rbdika;
			Address Abdika("TLV", "MTA, building ", 2);
			User* UB = new Buyer("Chen", "12345", Abdika);
			User* US = new Seller("Ronen", "12345", Abdika);
			Rbdika += *US; //add seller to the system
			Rbdika += *UB; //add buyer to the system			


			cout << "Added seller and buyer are:\n";
			cout << "Seller: \n";
			Rbdika.getAllUsers()[SELLER]->show();
			cout << "Buyer:\n";
			Rbdika.getAllUsers()[BUYER]->show();
		}
		break;
		}
	}

}

void loadAllUsers(const char* fileName, int& numOfUsers, RandH& sys)
{
	ifstream inFile(fileName, ios::in);
	inFile >> numOfUsers;

	if (numOfUsers == EMPTY)
	{
		inFile.close();
	}

	else
	{

		cout << "reading users from file\n";

		for (int i = 0; i < numOfUsers; i++)
		{
			string type;
			inFile >> type;
			User* temp;
			if (type == (typeid(Buyer).name() + 6))
			{
				temp = new Buyer(inFile);
				sys += *temp;

			}
			else if (type == (typeid(Seller).name() + 6))
			{
				temp = new Seller(inFile);
				sys += *temp;

			}

			else if (type == (typeid(BuyerSeller).name() + 6))
			{
				temp = new BuyerSeller(inFile);
				sys += *temp;

			}
		}
		inFile.close();
	}
}