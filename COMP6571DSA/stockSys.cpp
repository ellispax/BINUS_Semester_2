// paxma cpp.cpp : Defines the entry point for the console application.
/*
	#filename     : paxma cpp.cpp
	#author       : paxman
	#description  : cpp with the final implementation and depends  on the `linkedlist.h` library

*/


#include "linkedlist.h" // includes [iostream,  string, iomanip, sstream, vector,fstream]
#include <Windows.h>  //system output
#include <stdio.h>
//macro
#define CLS system("cls")
#define TITLE(name) system(name)

//namespace(s)
using namespace std;
using namespace stocktake; //<--- from linkedlist.h

//global variables
Products fProds, sProds; // using namespace stocktake; fProds- products from file; sProds - products from session
vector<User> fUsers, sUsers;   // rather than stocktake::Products A; type of declaration

//prototypes(s)
string mainmenu();
string login(vector<User>&);
string signup(vector<User>&, vector<User>&);
string productsmenu(stocktake::Products&, stocktake::Products&);


int main() {

	static bool logged = true, showmain = true;
	static string mainmenuResp = "", loginResp = "", signupResp = "", productsMenuResp = "";
	//main loop
	while (logged)
	{
		if (showmain)mainmenuResp = mainmenu();//main menu
		if (mainmenuResp == "L" || mainmenuResp == "l") { signupResp = ""; showmain = false; loginResp = login(fUsers); } //goto login
		if (mainmenuResp == "C" || mainmenuResp == "c") { loginResp = ""; showmain = false; signupResp = signup(fUsers, sUsers); }//goto signup

		//if user quits from [login|signup] , quit and return to main menu
		if (loginResp == "quit" || signupResp == "quit") { showmain = true; continue; }

		//if user succeeded [login|signup]
		if (loginResp != "" || signupResp != "")productsMenuResp = productsmenu(fProds, sProds);
		//check products menu
		if (productsMenuResp == "quit")showmain = true;
	}

	return 0;
}
//create timestamp
const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

//functions

string mainmenu()
{
	bool correctIn = false;
	string userin = "";
	CLS;

	cout << "\n\n"
		"     MainMenu\n"
		"---------------------------------\n"
		"-> Select Option to continue\n"
		"---------------------------------\n"
		"    [L] Login \n"
		"    [C] Create Account \n"
		"---------------------------------\n"
		"    [Q] Quit \n"
		"\n\n >: ";

	while (!correctIn)
	{
		getline(cin, userin);

		//check option and exit with value
		if (userin == "L" || userin == "l")break;
		if (userin == "C" || userin == "c")break;
		if (userin == "Q" || userin == "q")exit(0);//exit program	
		cout << "\a\n[!] >: ";
		//clear
		cin.clear(); cin.sync();
		userin = "";
	}

	return userin;

}
string login(vector<User>& loginList)
{
	//read to list
	read(loginList);
	CLS;

	bool correctIn = false;
	string uid = "", pin = "";

	while (!correctIn)
	{
		cout << "\n\n"
			"     #Login-Menu\n"
			"---------------------------------\n"
			"-> Enter your details to continue\n"
			"---------------------------------\n"
			" < ENTER userId=`U00` to quit > \n"
			"[#] userId   >: ";
		getline(cin, uid);
		if (uid == "U00" || uid == "u00") return "quit";
		cout << "\n"
			"[#] pincode  >: ";
		getline(cin, pin);
		cout << "\n";
		//check if user exists
		if (existsLogin(loginList, uid, pin))break; //continue if user exists
		//clear
		cin.clear(); cin.sync();
		uid = "", pin = "";
		CLS;
		cout << "\n\a[!] login failed, try again!..[use CAPSLOCK on ID ]";
	}

	return uid;
};
string signup(vector<User>& loginList, vector<User>& sessionList)
{
	//read to list
	read(loginList);
	CLS;

	bool correctIn = false;
	string uid = "", name = "", pin = "", code = "", approval = "admin";

	cout << "\n\n";

	while (!correctIn)
	{

		cout << "     #Create Account - Menu\n"
			"---------------------------------\n"
			"-> Enter your details to continue\n"
			"---------------------------------\n"
			" < ENTER name=`U0000` to Quit! > \n"
			"[+] Name   >: ";
		getline(cin, name);
		if (name == "U0000" || name == "u0000") return "quit";
		cout << "\n"
			"[+] Pincode  >: ";
		getline(cin, pin);
		cout << "\n"
			"[+] Approval Code >: ";
		getline(cin, code);

		// check if approval code is correct
		if (code != approval) 
		{
			cout << "[!]\a - - Approval Code Incorrect. Contact System Admin to create an Account!\n";
			//clear
			cin.clear(); cin.sync();
			uid = "", pin = "";
			continue;
		}

		//check if user exists
		if (exists(loginList, name))
		{
			cout << "[!]\a - - USER ALREADY EXISTS!..\n";
			//clear
			cin.clear(); cin.sync();
			uid = "", pin = "";
			continue;
		};
		//adduser
		User new_Usr(name, pin);
		uid = new_Usr.getId();
		sessionList.push_back(new_Usr);


		CLS;
		//approve account
		cout << "\n     #User has been added successfuly!..\n"
			"---------------------------------\n"
			" Your new login details are -:\n"
			"########################################\n"
			" -[#]NAME (username) :`" << name << "`\n"
			" -[#]UID  (user-id)  :`" << uid << "`\n"
			" -[#]PIN  (pincode)  :`" << pin << "`\n"
			"########################################\n"
			"---------------------------------\n";
		cout << endl;
		write(sessionList);

		cout << "\n[=]Press [ENTER] to continue..\n";
		cin.get();
		cin.clear(); cin.sync();
		break;

	}

	return uid;
};
string productsmenu(stocktake::Products& filelist, stocktake::Products& sesslist)
{

	bool correctIn = false;
	string userin = "";
	//open products list
	filelist.read();
	CLS;


	while (!correctIn)
	{
		//CLS;
		cout << "\n\n"
			"     [@]Products - Menu\n"
			"---------------------------------\n"
			"-> Select Option to continue\n"
			"---------------------------------\n"
			"    [A] Add product(s) \n"
			"    [D] Display Products \n"
			"    [S] Search product(s) \n"
			"    [R] Remove product(s)\n"
			"    [M] Move to Shop\n"
			"---------------------------------\n"
			"    [P] Previous Menu \n"
			"    [E] Exit \n"
			"\n\n >: ";
		getline(cin, userin);

		//check option and exit with value
		if (userin == "A" || userin == "a")
		{
			//variables
			string PName,
				pPrice,
				PBarcode,
				pQty,
				pbatch,
				date;

			int PQty = 0;
			double PPrice = 0.0;

			for (; ; )//equivalent to an infinity while-loop e.g while(true){ stmnt(s); }
			{
				cout << "\n\n---------------------------------\n"
					"-> Add details to continue..\n"
					"---------------------------------\n";
				//product name
				cout << "----[ENTER] `U00`  to Stop entry------------\n\n"
					"-[@] Product Name >: ";
				getline(cin, PName);
				if (PName == "U00" || PName == "u00")break;
				cout << endl;
				//product barcode
				cout << "[x]`U00`"
					"-[@] `" << PName << "` Barcode >: ";
				getline(cin, PBarcode);
				if (PBarcode == "U00" || PBarcode == "u00")break;
				cout << endl;
				//product Price
				cout << "[x]`U00`"
					"-[@] `" << PName << "` Price >: $";
				getline(cin, pPrice);
				if (pPrice == "U00" || pPrice == "u00")break;
				cout << endl;
				//product Quantity
				cout << "[x]`U00`"
					"-[@] `" << PName << "` Quantity >: ";
				getline(cin, pQty);
				if (pQty == "U00" || pQty == "u00")break;
				cout << endl;

				//product batch
				cout << "[x]`U00`"
					"-[@] `" << PName << "` Batch No >: ";
				getline(cin, pbatch);
				
				//generating timestamp
				date = currentDateTime();

				//---------------- generating values
				PPrice = stod(pPrice);
				PQty = stoi(pQty);
				//adding to list
				Stock temp(PName, PBarcode, PQty, PPrice,pbatch,date);
				sesslist.pushBack(temp);
				cout << "\a[@][+] Added Successfuly-----------------";
			}

		}
		if (userin == "D" || userin == "d")
		{
			CLS;
			cout << "\n================ -- Previous Products -- ================== \n";
			cout << "\n \tBarcode\t\t\t\t Name\t\t\t\tQuantity\t Price($)\t Batch No\t Date Recieved\n";

			filelist.display();
			cout << "\n================ -- Current Products -- ===================\n";
			sesslist.display();
			cout << endl;
			cout << "\n[=]Press [ENTER] to continue..\n";
			cin.get();
			cin.clear(); cin.sync();
		}
		if (userin == "S" || userin == "s")
		{
			string searchStr;
			cout << "\n input Barcode ..";
			cout << "\n[?] >: ";
			getline(cin, searchStr);

			cout << "\n*********** -- Search Results [Existing Products] -- *************** \n";
			cout << filelist.atBarcode(searchStr) << endl;
			cout << "\n************ -- [New Products] -- *************\n";
			cout << sesslist.atBarcode(searchStr) << endl;
			cout << "\n[=]Press [ENTER] to continue..\n";
			cin.get();
			cin.clear(); cin.sync();

		}
		if (userin == "P" || userin == "p")//quit menu	
		{
			cout << "\n[*]Saving changes..\n";
			sesslist.write();
			sesslist.dumb();
			filelist.dumb();
			cout << "[*] Save complete..\n[=]Press [ENTER] to continue..\n";
			cin.get();
			cin.clear(); cin.sync();
			return "quit";
		}
		if (userin == "E" || userin == "e")//exit program	
		{
			cout << "\n[*]Saving changes..\n";
			sesslist.write();
			cout << "[*] Save complete..\n[=]Press [ENTER] to continue..\n";
			cin.get();
			cin.clear(); cin.sync();
			exit(0);
		}
		if (userin == "R" || userin == "r")//remove item
		{
			while (true)
			{
				string searchStr;
				int count;
				cout << "\n input Barcode ..";
				cout << "\n[?] `U00` to quit >: ";
				getline(cin, searchStr);
				if (searchStr == "U00" || searchStr == "u00")break;

				else if((filelist.exists(searchStr) || sesslist.exists(searchStr)) == true)
				{	
					if (filelist.exists(searchStr) == true) 
					{
						cout << "\n*********** -- Removal on [ Existing Products ] -- *************** \n";
						filelist.remove(searchStr);
						filelist.OVERWRITE();
						cout << "\n*********** -- Removal on [ New Products ] -- *************\n";
						cout << " Nothing To remove from this List!";
					}
					else 
					{
						cout << "\n*********** -- Removal on [ Existing Products ] -- *************** \n";
						cout << "Nothing to remove from this List1\n";
						cout << "\n*********** -- Removal on [ New Products ] -- *************\n";
						sesslist.remove(searchStr);
					}
					
					

					cout << "\n[=]Press [ENTER] to continue..\n";
					cin.get();
					cin.clear(); cin.sync();
				}
				else
				{
					cout << "Invalid Barcode";
					break;
				}

				
			}
		}
		if (userin == "M" || userin == "m")//move to shop
		{
			string searchStr,batch;
			int count;
			cout << "\n input Barcode ..";
			cout << "\n[?] >: ";
			getline(cin, searchStr);
			cout << "\n input batch number ..";
			cout << "\[?] >: ";
			getline(cin, batch);
			cout << "\n input Quantity of product to move ..";
			cout << "\n[?] >: ";
			cin >> count;

			if (searchStr == "U00" || searchStr == "u00")break;
			cout << "\n*********** -- Moving [ Existing Products ] -- *************** \n";
			filelist.toShop(searchStr, batch,count);
			cout << "\n*********** -- Moving [ New Products ] -- *************\n";
			sesslist.toShop(searchStr,batch, count);

			cout << "\n[=]Press [ENTER] to continue..\n";
			cin.get();
			cin.clear(); cin.sync();

		}

		cout << "\a\n[!] >: ";
		//clear CIN
		cin.clear(); cin.sync();
		userin = "";
		CLS;
	}

	return "";// it will not reach here
};

