// SMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class company
{
protected:
	int company_option;
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
		cout << "\n\t\t\tAll stocks" << endl;
	}
	void SoldStocks()
	{
		ShortMenu();
		cout << "\n\t\t\tSold stocks" << endl;
	}
	void AvailableStocks()
	{
		ShortMenu();
		cout << "\n\t\t\tAvailable stocks" << endl;
	}
	void StocksOwnerDetails()
	{
		ShortMenu();
		cout << "\n\t\t\tStocks Owner Details" << endl;
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
