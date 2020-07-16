//This is the class header file for the Warehouse
//Created by: Bhawana, Sharath, Sai, Rama Krishna
//Created on: 09-07-2019
//Updated Last on : 13-09-2019

#pragma once
#include <string>
#include <iostream>

using namespace std;
class Warehouse
{
public:
	int productId;
	string productName;
	int quantity;
	float unitPrice;
	float sales;
	int  numberOfItemsSold;
	float spending;
	int numberOfItemsBought;

	
	
	//Constructor for the Warehouse
	Warehouse(int _productId, string _productName, int _quantity, float _unitPrice, float _sales, int _numberOfItemsSold, float _spending, int _numberOfItemsBought );
	virtual void Display();

};

