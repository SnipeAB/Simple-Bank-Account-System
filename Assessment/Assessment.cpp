// Online Shop Deal - Buy 5 items, get the cheapest one free
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_ITEMS = 5; // number of items in the deal

// Function: asks for a price for one item and returns it (rejects invalid input)
double readInput(int itemNum)
{
	double input;
	cout << "Enter the price for item " << itemNum << ": "; // prices entered in pounds
	while (!(cin >> input) || input < 0)
	{
		cin.clear();            // reset error state
		cin.ignore(1000, '\n'); // discard bad input
		cout << "Invalid price. Please enter a positive number: ";
	}
	cin.ignore(1000, '\n'); // clear rest of line before next getline
	return input;
}

// Function: asks for the name of one item and returns it
string readName(int itemNum)
{
	string name;
	cout << "Enter the name of item " << itemNum << ": ";
	getline(cin, name);
	return name;
}

// Procedure: fills the arrays with the names and prices of all items
void getItems(string names[], double prices[])
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		names[i] = readName(i + 1);
		prices[i] = readInput(i + 1);
	}
}

// Procedure: sorts items by price, highest to lowest (bubble sort)
void sortItems(string names[], double prices[])
{
	for (int pass = 0; pass < NUM_ITEMS - 1; pass++)
	{
		for (int i = 0; i < NUM_ITEMS - 1 - pass; i++)
		{
			if (prices[i] < prices[i + 1]) // swap if next item is dearer
			{
				swap(prices[i], prices[i + 1]);
				swap(names[i], names[i + 1]); // keep names matched to prices
			}
		}
	}
}

// Procedure: displays the items in their current (sorted) order
void displayItems(const string names[], const double prices[])
{
	cout << "\nItems sorted by price (highest to lowest):\n";
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		cout << i + 1 << ". " << left << setw(20) << names[i]
			 << right << fixed << setprecision(2) << prices[i] << endl;
	}
}

// Function: adds all prices together and returns the total
double calculateSubtotal(const double prices[])
{
	double total = 0;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		total += prices[i];
	}
	return total;
}

// Function: returns total owed after removing the cheapest item
// (the array is sorted, so the cheapest item is the last one)
double calculateTotal(const double prices[])
{
	return calculateSubtotal(prices) - prices[NUM_ITEMS - 1];
}

// Procedure: displays the subtotal, discount and final amount owed
void displayTotal(const string names[], const double prices[])
{
	cout << fixed << setprecision(2);
	cout << "\nSubtotal:        " << calculateSubtotal(prices) << endl;
	cout << "Free item:       " << names[NUM_ITEMS - 1]
		 << " (-" << prices[NUM_ITEMS - 1] << ")" << endl;
	cout << "Total owed:      " << calculateTotal(prices) << endl;
}

int main()
{
	string names[NUM_ITEMS];  // item names
	double prices[NUM_ITEMS]; // item prices

	cout << "=== Buy 5, Get the Cheapest Free ===\n\n";

	getItems(names, prices);      // input
	sortItems(names, prices);     // process: sort high to low
	displayItems(names, prices);  // output: sorted list
	displayTotal(names, prices);  // output: total owed

	return 0;
}
