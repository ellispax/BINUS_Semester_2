/*
	 **filename     : linkedlist.h

	 **description  : contains (Product)Stock and (Employees)user classes with their linked-list classes respectively
					  the lists work with their respective classes and are dynamic in nature
					  -it also contains getters and setters for an easier manipulation
					  -methods for easy traversing and manipulation, display and checking if a file exists `<bool> exists()`
					  -read and write methods for the lists to implement
						  ==[read - adds content to the calling list],
						  ==[write - appends list data to the file]
					  -also contains an OVERWRITE method just in case it gets needed
						  ==[OVERWRITE - truncates(removes) the current data and writes to file]

					  -+ hint: an easier way to implement is to have to lists , another one coming from the file
							   and another one for the current session so that

	  **author(s)    : paxman

	 -------------------------------------------------------------------------------------------------------
*/

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <time.h>
//#include "json.hpp"
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;
namespace stocktake
{

	void createFileIfNotExist(const string s);
}

//******************* STOCK  

class Stock {

private:
	string name,
		barcode, batchNo,date;
		
	unsigned int qty;
	double price;
	

public:
	Stock* next; // Pointer to successor

	//constructor(s)

	Stock(string Product_Name = "Product", string Barcode = "0000000000000", unsigned int Quantity = 0, double Price = 0.00, string BatchNo = "0000000", string Datetime = "dd-mm-yy hh-mm-ss", Stock* N = NULL)
	{
		name = Product_Name;
		barcode = Barcode;
		qty = Quantity;
		price = Price;
		batchNo = BatchNo;
		date = Datetime;
		next = N;
	}

	Stock(Stock& item)
	{
		name = item.getName();
		barcode = item.getBarcode();
		qty = item.getQty();
		price = item.getPrice();
		batchNo = item.getBatchNo();
		date = item.getDatetime();
		next = item.getNext();
	}

	//getters

	const unsigned int& getQty() { return qty; };
	const double& getPrice() { return price; };
	const string& getName() { return name; };
	const string& getBarcode() { return barcode; };
	const string& getBatchNo() { return batchNo; }
	const string& getDatetime() { return date; }
	Stock* getNext() { return next; };

	//setters

	void setQty(const unsigned int& Quantity) { qty = Quantity; }
	void setPrice(const  double& Price) { price = Price; }
	void setName(const string& Name) { name = Name; }
	void setBarcode(const string& Barcode) { barcode = Barcode; }
	void setBatchNo(const string& BatchNo) { batchNo = BatchNo; }
	void setDatetime(const string& Datetime) { date = Datetime; }

	//friend(s)
	friend class LinkedList;

	//method(s)
	const string toString()
	{
		stringstream outStream;
		string str = "";

		//barcode
		outStream << "{" << left << setfill(' ') << setw(20) << this->getBarcode() << "}";
		//name
		outStream << " Name ";
		outStream << ": " << left << setfill(' ') << setw(20) << this->getName();
		//quantity
		outStream << ", Quantity " << ": " << setfill(' ') << setw(5) << this->getQty();
		//price
		outStream << ", Price " << ": $" << this->getPrice();
		//batch number
		outStream << ", |Batch " << ": #" << this->getBatchNo();
		//date
		outStream << ", |Date " << ": " << this->getDatetime();
		str = outStream.str();

		return str;
	}

	void display()
	{
		cout << this->toString() << endl;
	}

	const string toCsv()
	{
		stringstream os;
		os << this->getBarcode() << "," << this->getName() << ',' << this->getQty() << ',' << this->getPrice() << ',' << this->getBatchNo() << ',' << this->getDatetime();
		return os.str();
	}

};
/*os << stk.getBarcode() << " ";
	//name
	os << left << setfill(' ') << setw(6) << "Name ";
	os << ": " << left << setfill(' ') << setw(20) << stk.getName();
	//quantity
	os << ", Quantity " << ": " << setfill(' ') << setw(5) << stk.getQty();
	//price
	os << ", |Price " << ": $" << stk.getPrice();
	//batch number
	os << ", |Batch " << ":#" << stk.getBatchNo();
	//date
	os << ", Date " << ": " << stk.getDatetime();
	return os;*/
ostream& operator<<(ostream& os, Stock& stk)
{
	//barcode
	os << stk.getBarcode() << "\t\t ";
	//name
	os << left << setfill(' ') << setw(6) << "";
	os << "" << left << setfill(' ') << setw(20) << stk.getName();
	//quantity
	os << "\t\t " << "" << setfill(' ') << setw(5) << stk.getQty();
	//price
	os << "\t\t " << "" << stk.getPrice();
	//batch number
	os << "\t\t " << "" << stk.getBatchNo();
	//date
	os << "\t\t " << "" << stk.getDatetime();
	return os;
}

//linked list [ for stock ]

class Linkedlist {

private:
	Stock* first, * last;

public:
	//constructor(s)

	Linkedlist()
	{
		first = last = NULL;
	}

	//destructor

	~Linkedlist()
	{
		Stock* pT1 = first, * next = NULL;
		for (; pT1 != NULL; pT1 = next)
		{
			next = pT1->next;
			delete pT1;
		}

	};

	// method(s)
/*
----- LInked List main functionality methods
-------*/

	Stock* front() const
	{
		return first;
	}

	Stock* end() const
	{
		return last;
	}

	//--adds list item at the back
	void pushBack(Stock& Object)
	{
		Stock* pT1 = new Stock(Object);
		if (last == NULL)  //if empty
			first = last = pT1;
		else
			last->next = pT1, last = pT1;
	}

	//--removes list entry at the front
	void popFront()
	{
		if (first != NULL)  //list isn't empty
		{
			Stock* pT1 = first;	         /* 1. Save the first list item */
			first = first->next;	 /* 2. Move over to next list item */
			delete pT1;              /* 3. Remove previous first list item */
			if (first == NULL)   //list is empty
				last = NULL;
		}
	}


	void dumb()
	{
		int num;
		
		num = count();
		while (num>0, num--)
		{
			popFront();
			
		}

	
	}

	/*
	------- Other subsidiary functions
	------------*/

	int count()
	{
		int count = 0;

		Stock* ptrSt = this->front();
		if (ptrSt == NULL)
			count = 0;
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
			count++;
		return count;
	}

	void display()
	{
		Stock* ptrSt = this->front();
		int count = 0;

		cout << endl;
		if (ptrSt == NULL)
			cout << " ***list is empty!*** ";
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
		{
			cout << ++count << ". -" << *ptrSt << endl;
		}

	}

	string atBarcode(const string posstr)
	{
		stringstream bcodeVals;

		Stock* ptrSt = this->front();
		if (ptrSt == NULL)
			bcodeVals << "**none**";
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
		{
			if (ptrSt->getBarcode() == posstr)
			{
				bcodeVals << ptrSt->toString() << endl;
			}
		}

		return bcodeVals.str();
	}

	int remove(string& search)
	{
		//vars to use
		bool found = false;
		int i = 0, pos = -1;
		Stock* iBefore = nullptr;

		//check for search-value
		while (true)
		{
			Stock* ptrSt = this->front();
			if (ptrSt == NULL)
				break;
			for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
			{
				i++;
				if (ptrSt->getBarcode() == search)
				{
					if (iBefore != NULL)  // isn't empty
					{
						Stock* pT1 = ptrSt;					//keep val
						iBefore->next = ptrSt->getNext();	//jump it and assign the current val
						delete pT1;
					}
					found = true;
					pos = i;
					break;
				}
				//keep first item
				iBefore = ptrSt;
			}
			if (found)break;
		}

		//if search is found and removed removed
		return pos;
	}

	void toShop(string& search,string& batch, int& Qty)
	{
		Stock* ptrSt = this->front();
		if (ptrSt == NULL)
		{
			cout << " **none found| [ list is emty ! ]** \n";
			return;
		}
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())//loop through list
		{
			if (ptrSt->getBarcode() == search)//check barcode
			{
				if (ptrSt->getBatchNo() == batch) 
				{
					int QuantityLeft = ptrSt->getQty() - Qty;
					if (QuantityLeft < 0)
					{
						cout << "\a[!]**Invalid request Stock lacks: " << QuantityLeft * (-1) << " of `" << ptrSt->getName() << "` !** \n";
						return;
					}
					else
					{
						ptrSt->setQty(QuantityLeft);
						return;
					}
				}
				else 
				{
					cout << "Barcode & Batch Number did not macth ! Please Try again.";
					return;
				}
			}
		}
	}

	int countItem(const string barcode)
	{
		int icnt = 0;
		Stock* ptrSt = this->front();
		if (ptrSt == NULL)
			return icnt;
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
		{
			if (ptrSt->getBarcode() == barcode)
			{
				icnt++;
			}
		}

		return icnt;
	}

	bool exists(const string Barcode)
	{
		int confirm = this->countItem(Barcode);//get count 
		return confirm > 0 ? true : false;
	}

	string toString()
	{
		Stock* ptrSt = this->front();
		int count = 0;
		stringstream os;


		cout << endl;
		if (ptrSt == NULL)
			return " ***list is empty!*** ";
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
		{
			os << ++count << ". -" << ptrSt->toString() << endl;
		}

		return os.str();
	}

	string toCsv()
	{
		//declare vars
		Stock* ptrSt = this->front();
		int count = 0;
		stringstream os;

		//if empty
		if (ptrSt == NULL)
		{
			return "";
		}

		//loop through adding values
		for (; ptrSt != NULL; ptrSt = ptrSt->getNext())
		{
			os << ptrSt->toCsv() << "\n";
		}
		//tell user and exit
		return os.str();
	}

	void read(string filePath = "products.csv")
	{

		fstream ifile;
		ios::openmode imode = ios::in;
		int initCount, finalCount = 0;
		//check for file
		stocktake::createFileIfNotExist(filePath);
		//open file
		ifile.open(filePath, imode);
		if (ifile.is_open())
		{
			//vars to use
			vector<string> dataList;
			string data = "";
			int i = 0;
			initCount = this->count();

			// get object from file
			for (; getline(ifile, data);)
			{

				string fulltoken{ data };

				//split on comma `,` and get value
				for (auto token = strtok(&fulltoken[0], ","); token != NULL; token = strtok(NULL, ","))
				{
					dataList.push_back(token);
				}
				//extract variables [ using postfixed iterator `i` {ukaisa rimwe data hazvizonetse,  kungoisa i++ than kuchinja pese}]
				string name = dataList.at(i++),
					barcode = dataList.at(i++),
					quantity = dataList.at(i++),
					price = dataList.at(i++),
					batchNo = dataList.at(i++),
					date = dataList.at(i++);
				//change to respective values
				int quantityInt = stoi(quantity);
				double priceDouble = stod(price);

				//temp val
				Stock temp(barcode, name, quantityInt, priceDouble,batchNo,date);
				//add new data to `self`
				this->pushBack(temp);

				//clear vector for new data and reset iterator `i`
				dataList.clear();
				i = 0;
			}

			//get final count
			finalCount = this->count();
			//closing the file when done
			ifile.close();
		}
		else
		{
			cerr << "\a[!] file: '" << filePath << "' , could not be opened\n";
			return;
		}
		//show results and then leave
		cout << "[+] ListSizes => Before::" << initCount << ", After::" << finalCount << ", NEWVALUES::" << finalCount - initCount << "\n";
		return;
	}

	void write(string filePath = "products.csv")
	{
		fstream ofile;
		ios::openmode omode = ios::app | ios::out;
		//open file
		ofile.open(filePath, omode);
		if (ofile.is_open())
		{
			ofile << this->toCsv();
			ofile.close();
			cout << "[+] " << this->count() << ". entries have been added..\n";
		}
		else
		{
			cerr << "\a[!] file: '" << filePath << "' , could not be opened\n";
			return;
		}

		return;
	}

	void OVERWRITE(string filePath = "products.csv")
	{

		fstream ofile;
		ios::openmode omode = ios::trunc | ios::out;
		//open file
		ofile.open(filePath, omode);
		if (ofile.is_open())
		{
			ofile << this->toCsv();
			ofile.close();
			cout << "[+] " << this->count() << ". entries have been added..\n";
		}
		else
		{
			cerr << "\a[!] file: '" << filePath << "' , could not be opened\n";
			return;
		}

		return;
	}

};

//********************* USER

class User
{
private:
	string name, id, pincode;
	User* next;

public:


	static int idCount;

	//constructor(s)
	User()
	{
		name = "Name";
		id = "EMP";
		pincode = "1234";
		//generate ID
		stringstream ids;
		if (idCount == NAN || idCount == NULL) idCount = 0;
		ids << id << setw(4) << setfill('0') << right << ++idCount;
		//load value into id
		id = ids.str();
	}
	User(string Name, string Pin)
	{
		name = Name;
		id = "EMP";
		pincode = Pin;
		//generate ID
		stringstream ids;
		if (idCount == NAN || idCount == NULL) idCount = 0;
		ids << id << setw(4) << setfill('0') << right << ++idCount;
		//load value into id
		id = ids.str();
	}
	User(string Name, string Id, string Pin) :name(Name), id(Id), pincode(Pin)
	{	//check for count then add
		if (idCount == NAN || idCount == NULL) idCount = 0;
		idCount++;
	}

	//getters
	const string& getName() { return name; }
	const string& getId() { return id; }
	const string& getPincode() { return pincode; }
	const int& getTotal() { return idCount; }
	User* getNext()const { return next; };

	//setters
	void setName(const string& Name) { name = Name; }
	void setId(const string& Id) { id = Id; }
	void setPincode(const string& Pin) { pincode = Pin; }
	void setTotal(const int& uNum) { idCount = uNum; }

	//friend(s)
	friend class UsersLinkedList;

	//method(s)
	void incrTotal()
	{
		if (idCount == NAN || idCount == NULL) idCount = 0;
		idCount++;
		return;
	}

	void incrId()
	{
		if (idCount == NAN || idCount == NULL) idCount = 0;
		//generate ID
		stringstream ids;
		id = "EMP";
		ids << id << setw(4) << setfill('0') << right << ++idCount;
		this->setId(ids.str());
		return;
	}

	void decrTotal()
	{
		if (idCount == NAN || idCount == NULL)
		{
			cerr << "\a[!]invalid operation for `total` i.e Total cannot be negative..\n";
			return;
		};
		idCount--;
	}

	const string toString()
	{
		stringstream os;
		os << "ID: " + this->id + ", USERNAME: " + this->name + ", PIN: " + this->pincode;
		return os.str();
	}

	const string toCsv()
	{
		stringstream os;
		os << this->id + "," + this->name + "," + this->pincode;
		return os.str();
	}

	void display()
	{
		cout << this->toString() << endl;
	}

};
int User::idCount = 0;

//reading a user

void read(vector<User>& users, string filePath = "employees.csv")
{
	fstream iufile;
	ios::openmode imode = ios::in;
	int initCount, finalCount = 0;
	//check for file
	stocktake::createFileIfNotExist(filePath);
	//open file
	iufile.open(filePath, imode);
	if (iufile.is_open())
	{
		//vars to use
		vector<string> dataList;
		string data;
		int i = 0;
		initCount = users.size();

		// get object from file { *.csv }
		for (; getline(iufile, data);)
		{
			string fulltoken{ data };

			//split on comma `,` and get value
			for (auto token = strtok(&fulltoken[0], ","); token != NULL; token = strtok(NULL, ","))
			{
				dataList.push_back(token);
			}
			//extract variables [ using postfixed iterator `i` ]
			string id = dataList.at(i++),
				name = dataList.at(i++),
				pin = dataList.at(i++);

			//temp val
			User temp(name, id, pin);
			//add new data to `self`
			users.push_back(temp);

			//clear vector for new data and reset iterator `i`
			dataList.clear();
			i = 0;
		}
		//get final count
		finalCount = users.size();
		//closing the file when done
		iufile.close();
	}
	else
	{
		cerr << "\a[!] file: '" << filePath << "' , could not be opened\n";
		return;
	}
	//show results and then leave
	cout << "[+] ListSizes => Before::" << initCount << ", After::" << finalCount << ", NEWVALUES::" << finalCount - initCount << "\n";
	return;
}

void write(vector<User>& users, string filePath = "employees.csv")
{
	fstream ofile;
	ios::openmode omode = ios::app | ios::out;
	//open file
	ofile.open(filePath, omode);
	if (ofile.is_open())
	{
		for (int i = 0; i < users.size(); i++)
		{
			ofile << users.at(i).toCsv() << endl;

		}
		ofile.close();
		cout << "[+] " << users.size() << ". entries have been added..\n";
	}
	else
	{
		cerr << "\a[!] file: '" << filePath << "' , could not be opened\n";
		return;
	}

	return;
}

void OVERWRITE(vector<User>& users, string filePath = "employees.csv")
{

	fstream ofile;
	ios::openmode omode = ios::trunc | ios::out;
	//open file
	ofile.open(filePath, omode);
	if (ofile.is_open())
	{
		stringstream overwrite;
		for (int i = 0; i < users.size(); i++)
		{
			overwrite << users.at(i).toCsv() << endl;
		}
		ofile << overwrite.str();
		ofile.close();
		cout << "[+] " << users.size() << ". entries have been added..\n";
	}
	else
	{
		cerr << "\a[!] file: '" << filePath << "' , could not be opened\n";
		return;
	}

	return;
}

bool exists(vector<User>& users, const string& username)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getName() == username)
			return true;
	}
	return false;
}

bool existsLogin(vector<User>& users, const string& userId, const string& userPin)
{
	for (int i = 0; i < users.size(); i++)
	{
		users[i].display();
		cout << " username: " << users[i].getName() << endl;
		cout << " userpincode: " << userPin << "; infile PIN: " << users[i].getPincode() << endl;
		cout << " userId: " << userId << "; infile Id: " << users[i].getId() << "\n------------------------------\n\n";
		if (users[i].getId() == userId)
		{
			if (users[i].getPincode() == userPin)
				return true;
		}

	}
	return false;
}


namespace stocktake
{
	//type definations
	typedef Linkedlist Products;
	//typedef UsersLinkedList Users;
	//string stream var
	stringstream strStream;

	//function(s)
	void createFileIfNotExist(const string s)
	{
		//open OR create
		ofstream file(s, ios::app | ios::out);
		//close file
		file.close();
	}
};

#endif
