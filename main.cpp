// SMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class company
{
protected:
	int company_option;
	string cp_sr, cp_name = " ", cp_category, cp_price, cp_tid, cp_fname, cp_sname, cp_address, cp_city, cp_cnic, cp_contact;
public:
	void ShortMenu()
	{
		system("cls");
		cout << "\t\t\tSTOCK MANAGEMENT SYSTEM\n" << endl;
		cout << "\t\t\t\tCOMPANY MENU\n\n" << endl;
	}
	void menu()
	{
		system("cls");
		cout << "\t\t\tSTOCK MANAGEMENT SYSTEM\n" << endl;
		cout << "\t\t\t\tCOMPANY MENU\n\n" << endl;
		cout << "\t\t1. All Stocks" << endl;
		cout << "\t\t2. Sold Stocks" << endl;
		cout << "\t\t3. Available Stocks" << endl;
		cout << "\t\t4. Stocks Owner Details" << endl;
		cout << "\t\t5. Exit" << endl;
		cout << "\n\t\tSelect your option: ";
		cin >> company_option;
		if (company_option == 1)
		{
			AllStocks();
		}
		if (company_option == 2)
		{
			SoldStocks();
		}
		if (company_option == 3)
		{
			AvailableStocks();
		}
		if (company_option == 4)
		{
			StocksOwnerDetails();
		}
		if (company_option == 5)
		{
			//exit the menu
		}
	}
	void AllStocks()
	{
		ShortMenu();
		string check="";
		ifstream fout;
		fout.open("data.csv");
		cout << "Sr.\tFull Name\tCategory\tPrice\tTID\n\n";

		for (int i = 0; fout; i++)
		{
			getline(fout, cp_sr, ',');
			getline(fout, cp_name, ',');
			getline(fout, cp_category, ',');
			getline(fout, cp_price, ',');
			getline(fout, cp_tid, '\n');
			if (check == cp_name)
				break;
			check = cp_name;
			cout << cp_sr << "\t" << cp_name << "\t" << cp_category << "\t" << cp_price << "\t" << cp_tid << endl;
		}
	
	}
	void SoldStocks()
	{
		ShortMenu();
		string check = "";
		ifstream fout;
		fout.open("data.csv");
		cout << "Sr.\tFull Name\tCategory\tPrice\tTID\n\n";

		for (int i = 0; fout; i++)
		{
			getline(fout, cp_sr, ',');
			getline(fout, cp_name, ',');
			getline(fout, cp_category, ',');
			getline(fout, cp_price, ',');
			getline(fout, cp_tid, '\n');
			if (check == cp_name)
				break;
			check = cp_name;
			if(cp_category=="Seller   ")
				cout << cp_sr << "\t" << cp_name << "\t" << cp_category << "\t" << cp_price << "\t" << cp_tid << endl;
		}

	}
	void AvailableStocks()
	{
		ShortMenu();
		string check = "";
		ifstream fout;
		fout.open("data.csv");
		cout << "Sr.\tFull Name\tCategory\tPrice\tTID\n\n";

		for (int i = 0; fout; i++)
		{
			getline(fout, cp_sr, ',');
			getline(fout, cp_name, ',');
			getline(fout, cp_category, ',');
			getline(fout, cp_price, ',');
			getline(fout, cp_tid, '\n');
			if (check == cp_name)
				break;
			check = cp_name;
			if(cp_category=="Available")
				cout << cp_sr << "\t" << cp_name << "\t" << cp_category << "\t" << cp_price << "\t" << cp_tid << endl;
		}

	}
	void StocksOwnerDetails()
	{
		ShortMenu();
		ifstream fout;
		string check = "";
		fout.open("details.csv");
		cout << "Sr.\tFull Name\t\tCNIC\t\tAddress\t\tCity\t\tContact\t\tPrice\tTID\n\n";

		for (int i = 0; fout; i++)
		{
			getline(fout, cp_sr, ',');
			getline(fout, cp_fname, ',');
			getline(fout, cp_sname, ',');
			getline(fout, cp_cnic, ',');
			getline(fout, cp_address, ',');
			getline(fout, cp_city, ',');
			getline(fout, cp_contact, ',');
			getline(fout, cp_price, ',');
			getline(fout, cp_tid, '\n');
			if (check == cp_fname)
				break;
			check = cp_fname;
			cout << cp_sr << "\t" << cp_fname << " " << cp_sname << "\t" << cp_cnic << "\t" << cp_address
				<< "\t" << cp_city << "\t" << cp_contact << "\t" << cp_price << "\t" << cp_tid << endl;
		}


	}
};


class customer : company
{
protected:
	int customer_option;
public:
	void CustomerShortMenu()
	{
		system("cls");
		cout << "\t\t\tSTOCK MANAGEMENT SYSTEM\n" << endl;
		cout << "\t\t\t\tCUSTOMER MENU\n\n" << endl;
	}
	void Seller()
	{
		CustomerShortMenu();
	}
	void Buyer()
	{
		CustomerShortMenu();
		cout << "\n\tAVAILABLE STOCKS" << endl;
		//AvailableStocks();
	}
	void CustomerMenu()
	{
		system("cls");
		cout << "\t\t\tSTOCK MANAGEMENT SYSTEM\n" << endl;
		cout << "\t\t\t\tCUSTOMER MENU\n\n" << endl;
		cout << "\t\t1. BUYER" << endl;
		cout << "\t\t2. SELLER" << endl;
		cout << "\n\t\tSelect your option: ";
		cin >> customer_option;
		if (customer_option == 1)
		{
			Buyer();
		}
		if (customer_option == 2)
		{
			Seller();
		}
	}

};

void Menu()
{
	cout << "\t\t\tSTOCK MANAGEMENT SYSTEM\n" << endl;
	cout << "\t\t\t\tMAIN MENU\n\n" << endl;
	cout << "\t\t1. Company User" << endl;
	cout << "\t\t2. Customer" << endl;

	cout << "\nSelect your option: ";
	int option;
	cin >> option;
	company cp;
	customer ct;
	if (option == 1)
	{
		cp.menu();
	}
	if (option == 2)
	{
		ct.CustomerMenu();
	}
}


int main()
{
	Menu();


	return 0;
}
