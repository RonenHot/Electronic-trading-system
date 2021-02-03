
#include "funcDeclaration.h"
#include "RandH.h"
#include "order.h"
#include "buyer.h"
#include "seller.h"
#include "feedback.h"
#include "payment.h"
#include "product.h"
#include "BuyerSeller.h"
#include "User.h"
#include "Array.h"


const bool SHOPCART = 1;
const bool ORDER = 0;
const bool EXISTS = 1;
const bool OverFlow = 1;
const int EMPTY = 0;
const int ERROR = -1;
const int CATEGORY = 5;
const int BUYER = 1;
const int SELLER = 0;
const int BUYERSELLER = 2;

//system functions
bool checkLength(const string& word);
void printMenu(RandH& sys);
bool logIn(RandH& sys, int& userIndex, int& Bos);
bool isExist(const RandH& sys, int& uesrindex, const string& username, const string& password, int& Bos);
bool readUser(RandH& sys, int user);
bool checkName(RandH& sys, const string& name);
void checkOperators();


//buyer function
bool buyerMenu(RandH& sys, Buyer* b);

//seller function
bool sellerMenu(RandH& sys, Seller* s);

//buyer-seller functions:
int BSmenu();

//product:
Product* readProduct(bool* isOverflow);
int categoryChoose();
bool showProducts(RandH& sys);


//order:
bool makeNewOrder(Buyer* b);
void moveToCurrentOrder(Buyer* b, vector<Product*>pcurr, int sizeCurr);

double calculateTotal(Buyer* b, bool type);
Payment* readCredit(double total, bool* resCredit, bool* isOverFlow);
void moveToOrderHistory(Buyer* b, vector<Order*> o, int size);
bool payment(Buyer* b, bool* isOverFlow);


//feedback:
Feedback* addFeedback(Buyer* b, bool* isOverFlow);
bool buyerAddFeedback(RandH& sys, Buyer* b);

//file function:
void loadAllUsers(const char* fileName, int& numOfUsers, RandH& sys);