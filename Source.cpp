#include <iostream>
#include <stdio.h>

using namespace std;

struct product {
	char name[20];
	double cost = 0;
	int quantity = 0;
};

void product_getter(product position);

int main()
{
	int n = 200; //Arbitrary number for the initialization of the stock array

	product* stock;
	stock = new product[n];

	product a;
	product_getter(a);

	cout << a.name << endl << a.cost << endl << a.quantity << endl;
}

void product_getter(product position)
{
	//Get the name, tried dynamic memory but it looks really really ugly

	cout << "Input name: ";
	cin >> position.name;
	cout << endl;

	//Get cost

	cout << "Input cost: ";
	cin >> position.cost;
	cout << endl;

	//Get quantity

	cout << "Input quantity: ";
	cin >> position.quantity;
	cout << endl;
}

