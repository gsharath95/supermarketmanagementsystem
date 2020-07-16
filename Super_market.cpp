// Super_market.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Created by: Bhawana, Sharath, Sai, Rama Krishna
//Created on: 09-07-2019
//Updated Last on : 13-09-2019

//Headers
#include <string>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include "Warehouse.h"
#include "UIKit.h"

using namespace std;

//prototypes
void DisplayItems();
void SellingItem();
void BuyingItem();
void UserDisplay();
void TimeDisplay();
void ItemDisplay();
void employeePay();
int ValidationFunctionality(string msg);

//Warehouse class 
const int ARR_VALUE = 5;
Warehouse* myWarehouse[ARR_VALUE] = {};

//Declaring global variables
int idSearch, quantity;
int numOfQuantity, numberOfItemsSold = 0, productId, numberOfItemsBought = 0;
string productName;
float unitPrice, sales, sellPrice, costPrice, spending;
int pay = 0;

int main()
{
	myWarehouse[0] = new Warehouse(1, "Apples", 10, 1.02, 0.0, 5, 0.0, 0);
	myWarehouse[1] = new Warehouse(2, "Banana", 15, 1.50, 0.0, 5, 0.0, 0);
	myWarehouse[2] = new Warehouse(3, "Grapes", 20, 2.00, 0.0, 5, 0.0, 0);
	myWarehouse[3] = new Warehouse(4, "Mango", 15, 1.70, 0.0, 0, 0.0, 0);
	myWarehouse[4] = new Warehouse(5, "Jam", 20, 2.10, 0.0, 0, 0.0, 0);
	
		
	
	int choice;

	//Menu
	do
	{
		TimeDisplay();
		clock_t begin = clock();

		UIKit::color(2);

		cout << endl << "-----------MAIN MENU.---------" << endl;

		cout << " 1. Buying Items \n 2. Selling Items \n 3. User Menu \n 4. Search the Item for number of sold and bought \n 5. Employee Pay \n 6. Display All Items \n 7.Quit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1: BuyingItem();
			break;
		case 2: SellingItem();
			break;
		case 3: UserDisplay();
			break;
		case 4:
			ItemDisplay();
			break;
		case 5:
			employeePay();
			break;
		case 6:
			DisplayItems();
			break;
		case 7: exit(0);
			break;
		}
	} while (choice != 7);

}

//Displaying function
void DisplayItems() {

	UIKit::color(14);
	cout << "PRODUCT ID" << "\t\t" << "PRODUCT NAME" << "\t\t" << "QUANTITY" << "\t\t" << "UNIT PRICE" << "\t\t" << "Sales" << "\t\t" << "Items Sold" << "\t" << "Spending" << "\t" << "Items Bought" << endl;
	for (int i = 0; i < ARR_VALUE; i++)
	{
		if (myWarehouse[i] != nullptr) {
			myWarehouse[i]->Display();
		}
	}
}

//Displaying the particular item sold and bought
void ItemDisplay() {

	system("CLS");
	DisplayItems();
	cout << "Enter the item type to display the Items sold and bought. " << endl << "Enter Product Name : " << endl;
	cin >> productName;

	for (int i = 0; i < ARR_VALUE; i++)
	{
		if (myWarehouse[i] != nullptr && myWarehouse[i]->productName == productName)
		{
			cout << "Product Name: " << myWarehouse[i]->productName << endl;
			cout << "Number of Items Bought: " << myWarehouse[i]->numberOfItemsSold << endl;
			cout << "Number of Items Bought: " << myWarehouse[i]->numberOfItemsBought << endl;
		}
	}

}

//Selling Inventory function 
void SellingItem()
{
	UIKit::color(3);
	string value;
	system("CLS");
	DisplayItems();
	do
	{
		cout << endl << endl;
		cout << "Enter the Product Id to select." << endl;
		idSearch = ValidationFunctionality("Enter Id: ");
		cout << "PRODUCT ID" << "\t\t" << "PRODUCT NAME" << "\t\t" << "QUANTITY" << "\t\t" << "UNIT PRICE" << "\t\t" << "Sales" << "\t\t" << "Items Sold" << "\t" << "Spending" << "\t" << "Items Bought" << endl;
		
		 
		for (int i = 0; i < ARR_VALUE; i++)
		{
			if (myWarehouse[i] != nullptr && idSearch == myWarehouse[i]->productId)
			{
				myWarehouse[i]->Display();
				cout << myWarehouse[i]->productName << ", Select number of items you want : " << endl;
				numOfQuantity = ValidationFunctionality("");
				while (numOfQuantity > myWarehouse[i]->quantity)
				{
					cout << "Warning! Please enter the lesser quantity number" << endl;
					cout << myWarehouse[i]->productName << ", Select number of items you want : " << endl;
					numOfQuantity = ValidationFunctionality("");
				}
				quantity = myWarehouse[i]->quantity - numOfQuantity;
				numberOfItemsSold = numOfQuantity + myWarehouse[i]->numberOfItemsSold;
				sellPrice = myWarehouse[i]->unitPrice * numOfQuantity;
				unitPrice = myWarehouse[i]->unitPrice;
				productName = myWarehouse[i]->productName;
				productId = myWarehouse[i]->productId;
				sales += sellPrice;
				myWarehouse[i] = new Warehouse(productId, productName, quantity, unitPrice, sales, numberOfItemsSold, spending, numberOfItemsBought);
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				myWarehouse[i]->Display();
				cout << "The Total Price is: " << sellPrice << "$" << endl;
			}
		}
		
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		DisplayItems();
		cout << endl << endl;
		cout << "Do you want select more items? (Yes/No)" << endl;
		cin >> value;
		DisplayItems();
		cout << endl << endl;
	} while (value == "yes" || value == "YES");

	cout << "Do you want to display Total Price of all sold Items? (Yes/No) " << endl;
	cin >> value;
	
	if (value == "yes" || value == "YES")
	{
		numberOfItemsSold = 0;
		sellPrice = 0;
		for (int i = 0; i < ARR_VALUE; i++)
		{

			if (myWarehouse[i] != nullptr)
			{
				sales += sellPrice;
			}
		}
		cout << "The total amount of sales of all ietms is : " << sales  << "$" << endl;
	}
	system("pause");
}

//Buying Inventory Function
void BuyingItem()
{
	UIKit::color(2);
	string value;
	system("CLS");
	DisplayItems();
	do
	{
		cout << "Enter the Product Id to buy." << endl;
		cin >> idSearch;
		cout << "PRODUCT ID" << "\t\t" << "PRODUCT NAME" << "\t\t" << "QUANTITY" << "\t\t" << "UNIT PRICE" << "\t\t" << "Sales" << "\t\t" << "Items Sold" << "\t" << "Spending" << "\t" << "Items Bought" << endl;

		for (int i = 0; i < ARR_VALUE; i++)
		{
			if (myWarehouse[i] != nullptr && idSearch == myWarehouse[i]->productId)
			{
				myWarehouse[i]->Display();
				cout << "You selected " << myWarehouse[i]->productName << ", Select number of items you want : " << endl;
				numOfQuantity = ValidationFunctionality("");
				quantity = myWarehouse[i]->quantity + numOfQuantity;
				numberOfItemsBought = numOfQuantity + myWarehouse[i]->numberOfItemsBought;
				costPrice = myWarehouse[i]->unitPrice * numOfQuantity;
				unitPrice = myWarehouse[i]->unitPrice;
				productName = myWarehouse[i]->productName;
				productId = myWarehouse[i]->productId;
				spending += costPrice;
				numberOfItemsSold = myWarehouse[i]->numberOfItemsSold;
				myWarehouse[i] = new Warehouse(productId, productName, quantity, unitPrice, sales, numberOfItemsSold, spending, numberOfItemsBought);
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				myWarehouse[i]->Display();
				cout << "The Total Price is: " << costPrice << "$" << endl;
			}
		}
		cout << "-------------------------------------------------------------------------------" << endl << endl;
		DisplayItems();
		cout << "Do you want select more items? (Yes/No)" << endl;
		cin >> value;
		DisplayItems();
	} while (value == "yes" || value == "YES");
	cout << "Do you want to display Total Price of all bought Items? (Yes/No) " << endl;
	cin >> value;
	if (value == "yes" || value == "YES")
	{
		costPrice = 0;
		numberOfItemsBought = 0;
		for (int i = 0; i < ARR_VALUE; i++)
		{

			if (myWarehouse[i] != nullptr)
			{
				spending += costPrice;
			}
		}
		cout << "The total spending on all items is : " << spending << "$" << endl;
	}

	system("pause");
}

//User Displaying Functionality
void UserDisplay()
{
	UIKit::color(14);
	system("CLS");

	numberOfItemsSold = numberOfItemsBought = 0;
	for (int i = 0; i < ARR_VALUE; i++)
	{
		if (myWarehouse[i] != nullptr)
		{
			numberOfItemsSold += myWarehouse[i]->numberOfItemsSold;
			numberOfItemsBought += myWarehouse[i]->numberOfItemsBought;
			spending += myWarehouse[i]->spending;
		}
	}

	TimeDisplay();
	cout << "Number of Items Bought are : " << numberOfItemsBought << endl;
	cout << "Number of Items sold are : " << numberOfItemsSold << endl;
	cout << "Cost of all items purchased : " << spending << "$" << endl;
	cout << "Amount paid to employees is : " << pay << "$" << endl;
	cout << "The total expenses is : " << spending + pay << "$" << endl;
	cout << "The total sales is : " << sales << "$" << endl;
	cout << "Total profit is : " << (spending + pay) - (sales) << "$" << endl;
}

//Displaying Time Function
void TimeDisplay()
{
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout << "\t\t\t\t\t\t\t\t\t\t" << ctime(&timenow) << endl;
}

//Validation Function
int ValidationFunctionality(string msg) {
	int value;
	cout << msg;
	cin >> value; // transfers the entered value
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Warning – numerical value!: ";
		cin >> value;
	}
	cin.ignore(512, '\n');
	return value;
}

//Employee Functionality
void employeePay()
{
	
	
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout << "\t\t\t\t\t\t\t\t\t\t" << ctime(&timenow) << endl;
	cout << ctime(&timenow) << endl;
	cout << "Pay is : " << pay << endl;
	pay = pay + (2600 / 12);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	pay = pay + (2600 / 12);
	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
