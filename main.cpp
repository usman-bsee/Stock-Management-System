// Stock Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class company
{
protected:

public:
	void AllStocks()
	{
		cout << "All stocks!!!\n";
	}
	void AvailableStocks()
	{
		cout << "Available stocks!!!\n";
	}
	void SoldStocks()
	{
		cout << "Sold stocks!!!\n";
	}
	void StocksOwner()
	{
		cout << "StocksOwner\n";
	}
};


int main()
{
    std::cout << "Hello World!\n";
}

