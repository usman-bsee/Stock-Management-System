// SMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

void Menu();
void gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

class company
{
private:
	int company_option;
	string cp_sr, cp_name = " ", cp_category, cp_price, cp_tid, cp_fname, cp_sname, cp_address, cp_city, cp_cnic, cp_contact;
	string cp_id, cp_pass, cp_login_pass, cp_login_id;
protected:
	void ShortMenu()
	{
		system("cls");
		gotoxy(40, 1); cout << "-----------------------------";
		gotoxy(43, 2); cout << "STOCK MANAGEMENT SYSTEM";
		gotoxy(40, 3); cout << "-----------------------------";
	}
	void CompanyMenu()
	{
		system("cls");
		gotoxy(40, 1); cout << "-----------------------------";
		gotoxy(43, 2); cout << "STOCK MANAGEMENT SYSTEM";
		gotoxy(40, 3); cout << "-----------------------------";
		gotoxy(25, 7); cout << "COMAPNY MAIN MENU";
		gotoxy(24, 8); cout << "-------------------------------------------";
		gotoxy(25, 9); cout << "Sr.\tDescription\t\tPress Key";
		gotoxy(24, 10); cout << "-------------------------------------------";
		gotoxy(25, 11); cout << "1.\tAll Stocks\t\t\t1";
		gotoxy(25, 12); cout << "2.\tSold Stocks\t\t\t2";
		gotoxy(25, 13); cout << "3.\tAvailable Stocks\t\t3";
		gotoxy(25, 14); cout << "4.\tStocks Owner Details\t\t4";
		gotoxy(25, 15); cout << "5.\tReturn to Main Menu\t\t0";
		gotoxy(24, 16); cout << "-------------------------------------------";

		cout << "\n\n\t\t\tSelect your option: __\b\b";
		cin >> company_option;
		if (company_option == 1)
			AllStocks();
		if (company_option == 2)
			SoldStocks();
		if (company_option == 3)
		{
			AvailableStocks();
			ReturnFunc();
		}
		if (company_option == 4)
			StocksOwnerDetails();
		if (company_option == 0)
			Menu();
	}

	void CompanyFileLoginID()
	{
		ifstream fout;
		fout.open("LoginCredentails.txt");
		getline(fout, cp_id, ',');
	}
	void CompanyFileLoginPass()
	{
		ifstream fout;
		fout.open("LoginCredentails.txt");
		getline(fout, cp_pass, ',');
		getline(fout, cp_pass, '\n');
	}
	void CompanyOwner()
	{
		ShortMenu();
		CompanyFileLoginID();
		CompanyFileLoginPass();
		gotoxy(34, 8);
		cout << "----------------------------------------------\n";
		for (int i = 8; i < 16; i++)
		{
			gotoxy(34, i);
			cout << "|";
		}
		for (int i = 8; i < 16; i++)
		{
			gotoxy(80, i);
			cout << "|";
		}
		gotoxy(35, 15); cout << "---------------------------------------------\n";

		gotoxy(37, 10);  cout << "Enter your Login ID: _________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cin >> cp_login_id;
		if (cp_login_id == cp_id)
		{
			gotoxy(37, 12);  cout << "Enter your Login Password: ___________\b\b\b\b\b\b\b\b\b\b\b";
			cin >> cp_login_pass;
			if (cp_login_pass == cp_pass)
			{
				CompanyMenu();
			}
		}
	}

	void AllStocks()
	{
		ShortMenu();
		string check = "";
		gotoxy(15, 6);		cout << "--------------\n";
		cout << "\t\tStock List: \n";
		gotoxy(15, 8);		cout << "--------------\n";
		gotoxy(16, 9);		cout << "-----------------------------------------------\n";
			   		 
		ifstream fout;
		fout.open("data.csv");
		int j = 0;
		for (int i = 0; fout; i++)
		{
			getline(fout, cp_name, ',');			getline(fout, cp_category, ',');
			getline(fout, cp_price, ',');			getline(fout, cp_tid, '\n');
			if (check == cp_price)
				break;
			check = cp_price;

			gotoxy(16, 10 + j);	cout << "|";			gotoxy(16, 11 + j);	cout << "|";
			gotoxy(16, 12 + j);	cout << "|";			gotoxy(16, 13 + j);	cout << "|";
			gotoxy(16, 14 + j);	cout << "|";			gotoxy(62, 10 + j); cout << "|";				
			gotoxy(62, 11 + j); cout << "|";			gotoxy(62, 12 + j); cout << "|";				
			gotoxy(62, 13 + j); cout << "|";			gotoxy(62, 14 + j); cout << "|";				
			
			gotoxy(18, j + 10);				cout << "Full Name:"; gotoxy(40, j + 10); cout << cp_name << "\n";
			gotoxy(18, j + 11);				cout << "Category:"; gotoxy(40, j + 11); cout << cp_category << "\n";
			gotoxy(18, j + 12);				cout << "Price:"; gotoxy(40, j + 12); cout << cp_price << "\n";
			gotoxy(18, j + 13);				cout << "Tracking ID:"; gotoxy(40, j + 13); cout << cp_tid << "\n";
			gotoxy(16, j + 14);				cout << "-----------------------------------------------\n";

			j = j + 5;
		}
		cout << "\t\tPress 1 to return to main menu\n";
		cout << "\t\tPress 2 to exit\n";
		int value;
		cout << "\t\t";  cin >> value;
		if (value == 1)
			CompanyMenu();
		if (value == 2)
			_getch();
	}
	void SoldStocks()
	{
		ShortMenu();
		string check = "";
		gotoxy(15, 6);		cout << "-------------------\n";
		gotoxy(16, 7);		cout << "Sold Stocks List: \n";
		gotoxy(15, 8);		cout << "-------------------\n";
		gotoxy(16, 9);		cout << "-----------------------------------------------\n";

		ifstream fout;
		fout.open("SoldStocks.csv");
		int j = 0;
		for (int i = 0; fout; i++)
		{
			getline(fout, cp_name, ',');			getline(fout, cp_category, ',');
			getline(fout, cp_price, ',');			getline(fout, cp_tid, '\n');
			if (check == cp_price)
				break;
			check = cp_price;
			if (cp_category == "Seller")
			{
				gotoxy(16, 10 + j);	cout << "|";			gotoxy(16, 11 + j);	cout << "|";
				gotoxy(16, 12 + j);	cout << "|";			gotoxy(16, 13 + j);	cout << "|";
				gotoxy(16, 14 + j);	cout << "|";			gotoxy(62, 10 + j); cout << "|";
				gotoxy(62, 11 + j); cout << "|";			gotoxy(62, 12 + j); cout << "|";
				gotoxy(62, 13 + j); cout << "|";			gotoxy(62, 14 + j); cout << "|";

				gotoxy(18, j + 10);				cout << "Full Name:"; gotoxy(40, j + 10); cout << cp_name << "\n";
				gotoxy(18, j + 11);				cout << "Category:"; gotoxy(40, j + 11); cout << cp_category << "\n";
				gotoxy(18, j + 12);				cout << "Price:"; gotoxy(40, j + 12); cout << cp_price << "\n";
				gotoxy(18, j + 13);				cout << "Tracking ID:"; gotoxy(40, j + 13); cout << cp_tid << "\n";
				gotoxy(16, j + 14);				cout << "-----------------------------------------------\n";
			}
			j = j + 5;
		}
		cout << "\t\tPress 1 to return to main menu\n";
		cout << "\t\tPress 2 to exit\n";
		int value;
		cout << "\t\t";  cin >> value;
		if (value == 1)
			CompanyMenu();
		if (value == 2)
			_getch();

	}
	void AvailableStocks()
	{
		ShortMenu();
		string check = "";
		gotoxy(15, 6);		cout << "------------------------\n";
		gotoxy(16, 7);		cout << "Available Stocks List: \n";
		gotoxy(15, 8);		cout << "------------------------\n";
		gotoxy(16, 9);		cout << "-----------------------------------------------\n";

		ifstream fout;
		fout.open("AvailableStocks.csv");
		int j = 0;
		for (int i = 0; fout; i++)
		{
			getline(fout, cp_name, ',');			getline(fout, cp_category, ',');
			getline(fout, cp_price, ',');			getline(fout, cp_tid, '\n');
			if (check == cp_price)
				break;
			check = cp_price;
			if (cp_category == "Available")
			{
				gotoxy(16, 10 + j);	cout << "|";			gotoxy(16, 11 + j);	cout << "|";
				gotoxy(16, 12 + j);	cout << "|";			gotoxy(16, 13 + j);	cout << "|";
				gotoxy(16, 14 + j);	cout << "|";			gotoxy(62, 10 + j); cout << "|";
				gotoxy(62, 11 + j); cout << "|";			gotoxy(62, 12 + j); cout << "|";
				gotoxy(62, 13 + j); cout << "|";			gotoxy(62, 14 + j); cout << "|";

				gotoxy(18, j + 10);				cout << "Full Name:"; gotoxy(40, j + 10); cout << cp_name << "\n";
				gotoxy(18, j + 11);				cout << "Category:"; gotoxy(40, j + 11); cout << cp_category << "\n";
				gotoxy(18, j + 12);				cout << "Price:"; gotoxy(40, j + 12); cout << cp_price << "\n";
				gotoxy(18, j + 13);				cout << "Tracking ID:"; gotoxy(40, j + 13); cout << cp_tid << "\n";
				gotoxy(16, j + 14);				cout << "-----------------------------------------------\n";

			}
			j += 5;
		}
	}
	void ReturnFunc()
	{
		cout << "\t\tPress 1 to return to main menu\n";
		cout << "\t\tPress 2 to exit\n";
		int value;
		cout << "\t\t";  cin >> value;
		if (value == 1)
			CompanyMenu();
		if (value == 2)
			_getch();

	}
	void StocksOwnerDetails()
	{
		ShortMenu();
		string check = "";
		gotoxy(15, 6);		cout << "------------------------\n";
		gotoxy(16, 7);		cout << "Available Stocks List: \n";
		gotoxy(15, 8);		cout << "------------------------\n";
		gotoxy(16, 9);		cout << "-----------------------------------------------\n";

		ifstream fout;
		fout.open("details.csv");
		int j = 0;
		for (int i = 0; fout; i++)
		{
			getline(fout, cp_fname, ',');			getline(fout, cp_sname, ',');
			getline(fout, cp_cnic, ',');			getline(fout, cp_address, ',');
			getline(fout, cp_city, ',');			getline(fout, cp_contact, ',');
			getline(fout, cp_price, ',');			getline(fout, cp_tid, '\n');
			if (check == cp_sname)
				break;
			check = cp_sname;

			gotoxy(16, 10 + j);	cout << "|";			gotoxy(16, 11 + j);	cout << "|";
			gotoxy(16, 12 + j);	cout << "|";			gotoxy(16, 13 + j);	cout << "|";
			gotoxy(16, 14 + j);	cout << "|";			gotoxy(16, 15 + j);	cout << "|";
			gotoxy(16, 16 + j);	cout << "|";			gotoxy(16, 17 + j);	cout << "|";
			gotoxy(16, 18 + j);	cout << "|";

			gotoxy(62, 10 + j); cout << "|";			gotoxy(62, 11 + j); cout << "|";			
			gotoxy(62, 12 + j); cout << "|";			gotoxy(62, 13 + j); cout << "|";			
			gotoxy(62, 14 + j); cout << "|";			gotoxy(62, 15 + j); cout << "|";
			gotoxy(62, 16 + j); cout << "|";			gotoxy(62, 17 + j); cout << "|";
			gotoxy(62, 18 + j); cout << "|";

			gotoxy(18, j + 10);				cout << "First Name:"; gotoxy(40, j + 10); cout << cp_fname << "\n";
			gotoxy(18, j + 11);				cout << "Second Name:"; gotoxy(40, j + 11); cout << cp_sname << "\n";
			gotoxy(18, j + 12);				cout << "CNIC:"; gotoxy(40, j + 12); cout << cp_cnic << "\n";
			gotoxy(18, j + 13);				cout << "Address:"; gotoxy(40, j + 13); cout << cp_address << "\n";
			gotoxy(18, j + 14);				cout << "City:"; gotoxy(40, j + 14); cout << cp_city << "\n";
			gotoxy(18, j + 15);				cout << "Contact:"; gotoxy(40, j + 15); cout << cp_contact << "\n";
			gotoxy(18, j + 16);				cout << "Price:"; gotoxy(40, j + 16); cout << cp_price << "\n";
			gotoxy(18, j + 17);				cout << "Tracking ID:"; gotoxy(40, j + 17); cout << cp_tid << "\n";
			gotoxy(16, j + 18);				cout << "-----------------------------------------------\n";
			j += 9;
		}
		cout << "\t\tPress 1 to return to main menu\n";
		cout << "\t\tPress 2 to exit\n";
		int value;
		cout << "\t\t";  cin >> value;
		if (value == 1)
			CompanyMenu();
		if (value == 2)
			_getch();

	}
public:
	void print()
	{
		CompanyOwner();
	}

};
















class customer : company
{
private:
	int customer_option;
	string login_id, login_pass;
	string fname, sname, cnic, address, city, contact, price;
	string file_id, file_pass;
protected:
	void CustomerShortMenu()
	{
		system("cls");
		gotoxy(40, 1); cout << "-----------------------------";
		gotoxy(43, 2); cout << "STOCK MANAGEMENT SYSTEM";
		gotoxy(40, 3); cout << "-----------------------------";
	}
	void FileLoginID()
	{
		ifstream fout;
		fout.open("LoginCredentails.txt");
		getline(fout, file_id, ',');
	}
	void FileLoginPass()
	{
		ifstream fout;
		fout.open("LoginCredentails.txt");
		getline(fout, file_pass, ',');
		getline(fout, file_pass, '\n');
	}
	void Owner()
	{
		CustomerShortMenu();
		FileLoginID();
		FileLoginPass();
		gotoxy(34, 8);
		cout << "----------------------------------------------\n";
		for (int i = 8; i < 16; i++)
		{
			gotoxy(34, i);
			cout << "|";
		}
		for (int i = 8; i < 16; i++)
		{
			gotoxy(80, i);
			cout << "|";
		}
		gotoxy(35, 15); cout << "---------------------------------------------\n";

		gotoxy(37, 10);  cout << "Enter your Login ID: _________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cin >> login_id;
		if (login_id == file_id)
		{
			gotoxy(37, 12);  cout << "Enter your Login Password: ___________\b\b\b\b\b\b\b\b\b\b\b";
			cin >> login_pass;
			if (login_pass == file_pass)
			{
				CustomerShortMenu();
				gotoxy(24, 8); cout << "-------------------------------------------";
				gotoxy(25, 9); cout << "Sr.\tDescription\t\tPress Key";
				gotoxy(24, 10); cout << "-------------------------------------------";
				gotoxy(25, 11); cout << "1.\tAvailable Stocks\t\t1";
				gotoxy(25, 12); cout << "2.\tPurchased Stocks\t\t2";
				gotoxy(24, 13); cout << "-------------------------------------------";

				cout << "\n\n\t\t\tSelect your option: __\b\b";
				cin >> customer_option;
				if (customer_option == 1)
				{
					AvailableStocks();
					cout << "Do you want to purchase new stocks(Y or N)? ";
					char select;
					cin >> select;
					if (select == 'Y' || select == 'y')
						Buyer();
					if (select == 'N' || select == 'n')
						_getch();
				}
			}
		}
	}
	void Buyer()
	{
		CustomerShortMenu();
		AvailableStocks();
		cout << "\n\n\t\t\tDo you want to purchase new stocks(Y or N)? __\b\b";
		char select;
		cin >> select;
		if (select == 'Y')
			Details();
		if (select == 'N')
			_getch();

	}
	string GenerateTID()
	{
		string id = "SMS20220";
		int x = rand();
		string y = to_string(x);
		id = id + y;
		return id;
	}
	void Details()
	{
		cout << "Enter TID of the stock: ";
		string c_tid;
		cin >> c_tid;
		CustomerShortMenu();
		cout << "PERSONAL INFORMATION\n\n";
		cout << "Enter your First Name: ";
		cin >> fname;
		cout << "Enter your Second Name: ";
		cin >> sname;
		cout << "Enter your CNIC number(00000-0000000-0): ";
		cin >> cnic;
		cin.clear();
		cin.ignore();
		cout << "Enter your Address: ";
		getline(cin, address);
		cout << "Enter your Contact Number(0000-0000000): ";
		cin >> contact;

		ifstream fout;
		fout.open("AvailableStocks.csv");
		string temp = "";
		string fd1, fd2, fd3, fd4, fd5, fd6, fd7;
		for (int i = 0; fout; i++)
		{
			getline(fout, fd1, ',');			getline(fout, fd2, ',');
			getline(fout, fd3, ',');			getline(fout, fd4, ',');
			getline(fout, fd5, ',');			getline(fout, fd6, ',');
			getline(fout, fd7, ',');
			if (c_tid == fd6)
			{
				price = fd6;
				break;
			}
		}
		fout.close();
		FileWrite();
	}
	void FileWrite()
	{

		ofstream fin;
		fin.open("details.csv");
		string gid = GenerateTID();
		fin << fname << "," << sname << "," << cnic << "," << address << "," << contact << "," << price << "," << gid << endl;
	}
	void CustomerMenu()
	{
		system("cls");
		cout << "\t\t\tSTOCK MANAGEMENT SYSTEM\n" << endl;
		cout << "\t\t\t\tCUSTOMER MENU\n\n" << endl;
		cout << "\t\t1. BUYER" << endl;
		cout << "\t\t2. OWNER" << endl;
		cout << "\n\t\tSelect your option: ";
		cin >> customer_option;
		if (customer_option == 1)
		{
			Buyer();
		}
		if (customer_option == 2)
		{
			Owner();
		}
	}
public:
	void customer_print()
	{
		CustomerMenu();
	}
};





void Start()
{
	gotoxy(46, 5);
	cout << "------------------\n";
	for (int i = 6; i < 14; i++)
	{
		gotoxy(46, i);
		cout << "|";
	}
	for (int i = 6; i < 14; i++)
	{
		gotoxy(63, i);
		cout << "|";
	}
	gotoxy(46, 14); cout << "------------------\n";
	gotoxy(52, 7);	cout << "STOCK\n";
	gotoxy(50, 9);	cout << "MANAGEMENT\n";
	gotoxy(52, 11);	cout << "SYSTEM\n\n\n";
	gotoxy(18, 18); cout << "------------------------------";
	gotoxy(20, 19);	cout << "PROJECT BY:";
	gotoxy(34, 19);	cout << "MUGHEES\n";
	gotoxy(44, 19);	cout << "066\n";
	gotoxy(34, 21);	cout << "M. OWAIM\n";
	gotoxy(44, 21);	cout << "067\n";
	gotoxy(18, 23); cout << "------------------------------";
	gotoxy(17, 18); cout << "|";
	gotoxy(17, 19); cout << "|";
	gotoxy(17, 20); cout << "|";
	gotoxy(17, 21); cout << "|";
	gotoxy(17, 22); cout << "|";
	gotoxy(17, 23); cout << "|";
	gotoxy(48, 18); cout << "|";
	gotoxy(48, 19); cout << "|";
	gotoxy(48, 20); cout << "|";
	gotoxy(48, 21); cout << "|";
	gotoxy(48, 22); cout << "|";
	gotoxy(48, 23); cout << "|";
	gotoxy(65, 24);	cout << "SUBMITTED TO:";
	gotoxy(79, 24);	cout << "Sir ASAD KAMAL\n";
	gotoxy(65, 25);	cout << "-----------------------------\n\n\n";
	gotoxy(94, 25);	_getch();
}

void Menu()
{
	//Start();
	system("cls");
	gotoxy(40, 1); cout << "-----------------------------";
	gotoxy(43, 2); cout << "STOCK MANAGEMENT SYSTEM";
	gotoxy(40, 3); cout << "-----------------------------";
	gotoxy(25, 7); cout << "MAIN MENU";
	gotoxy(24, 8); cout << "-------------------------------------------";
	gotoxy(25, 9); cout << "Sr.\tDescription\t\tPress Key";
	gotoxy(24, 10); cout << "-------------------------------------------";
	gotoxy(25, 11); cout << "1.\tCompany User\t\t1";
	gotoxy(25, 12); cout << "2.\tCustomer User\t\t2";
	gotoxy(24, 13); cout << "-------------------------------------------";

	cout << "\n\n\t\t\tSelect your option: __\b\b";
	int select;
	cin >> select;
	if (select == 1)
	{
		company cp;
		cp.print();
	}
	if (select == 2)
	{
		customer ct;
		ct.customer_print();
	}

}




int main()
{

	Start();
	Menu();

	return 0;
}
