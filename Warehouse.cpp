//This is the class header file for the Warehouse
//Created by: Bhawana, Sharath, Sai, Rama Krishna
//Created on: 09-07-2019
//Updated Last on : 13-09-2019

#include "Warehouse.h"

//Constructor calling from the warehouse header file
Warehouse::Warehouse(int _productId, string _productName, int _quantity, float _unitPrice, float _sales, int _numberOfItemsSold, float _spending, int _numberOfItemsBought)
{
	productId = _productId;
	productName = _productName;
	quantity = _quantity;
	unitPrice = _unitPrice;
	sales = _sales;
	numberOfItemsSold = _numberOfItemsSold;
	spending = _spending;
	numberOfItemsBought = _numberOfItemsBought;

}


void Warehouse::Display()
{	
	cout << productId << "\t\t\t" << productName << "\t\t\t" << quantity << "\t\t\t" << unitPrice << "\t\t\t" << sales << "\t\t" << numberOfItemsSold << "\t\t" << spending << "\t\t" << numberOfItemsBought << endl;
}
