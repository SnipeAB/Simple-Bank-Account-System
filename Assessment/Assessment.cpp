// Online Shop Deal - buy 5 items, get the cheapest one free
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function: asks for the name of one item and returns it
string readName(int itemNum)
{
	string name;
	cout << "Enter the name of item " << itemNum << ": ";
	cin >> name;
	return name;
}

// Function: asks for the price of one item and returns it
double readInput(int itemNum)
{
	double input;
	cout << "Enter the price for item " << itemNum << ": ";
	cin >> input;
	return input;
}

// Procedure: gets the name and price of all 5 items
void getItems(string names[], double prices[])
{
	for (int i = 0; i < 5; i++)
	{
		names[i] = readName(i + 1);
		prices[i] = readInput(i + 1);
	}
}

// Procedure: sorts the items by price, highest to lowest (bubble sort)
void sortItems(string names[], double prices[])
{
	for (int pass = 0; pass < 4; pass++)
	{
		for (int i = 0; i < 4; i++)
		{
			// if the next item costs more, swap them round
			if (prices[i] < prices[i + 1])
			{
				swap(prices[i], prices[i + 1]);
				swap(names[i], names[i + 1]); // keep names with their prices
			}
		}
	}
}

// Procedure: displays the items in order
void displayItems(string names[], double prices[])
{
	cout << "\nItems from highest to lowest price:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << names[i] << " - " << prices[i] << endl;
	}
}

// Function: adds up all prices except the cheapest (the last one after sorting)
double calculateTotal(double prices[])
{
	double total = 0;
	for (int i = 0; i < 4; i++)
	{
		total = total + prices[i];
	}
	return total;
}

// Procedure: displays the total owed
void displayTotal(double total)
{
	cout << "\nTotal owed: " << total << endl;
}

int main()
{
	string names[5];  // item names
	double prices[5]; // item prices
	double total;     // total owed

	cout << fixed << setprecision(2); // show prices to 2 decimal places

	getItems(names, prices);
	sortItems(names, prices);
	displayItems(names, prices);
	total = calculateTotal(prices);
	displayTotal(total);

	return 0;
}
