#include <stdio.h>
#include <iostream>
#include <iomanip>

#define NAME_LENGTH 30
#define SETW_PARAM 6
#define STOCK_LEN 30

using namespace std;

struct Product
{
public:
	char name[NAME_LENGTH];
	int ln = NAME_LENGTH;
	double price = -1;
	int quantity = -1;
};

Product Product_input();
void Product_print(const Product& myProduct);
int user_interface();

int main()
{
	int first_boot_flag = 1;

	if (first_boot_flag == 1)
	{
		struct Product* stock = new Product[STOCK_LEN];
		int first_empty_position_stock = 0;

		int user_intention = user_interface();

		if (user_intention == 1) //Append a product to the stock
		{
			stock[first_empty_position_stock] = Product_input();
			first_empty_position_stock++;
		}
		else if (user_intention == 2) //Product's data
		{
			//Search and compare                                 //Show of way?
			//Product_print();
		}
		else if (user_intention == 3) //Add a product to the bucket
		{

		}
		else if (user_intention == 4) //Delete a product from the bucket
		{

		}
		else if (user_intention == 5) //Delete a product from the stock
		{

		}
		else if (user_intention == 6) //Checkout
		{

		}
		else if (user_intention == 7) //Exit
		{

		}
	}
}

int str_compare(const char*& op1, const char*& op2)
{//                                                     Should implement try catch
	int res = -2;

	for (int i = 0;; i++)
	{
		if (op1[i] == '\0' and op2[i] != '\0')
		{
			res = 0;
			break;
		}
		else if (op1[i] != '\0' and op2[i] == '\0')
		{
			res = 1;
			break;
		}
		else if (op1[i] == '\0' and op2[i] == '\0')
		{
			res = -1;
			break;
		}
	}

	return res;
}

int user_interface()
{
	cout << "--------------INTERFACE---------------" << endl;
	cout << " Options: " << endl;
	cout << "1. Append a product to the stock" << endl;
	cout << "2. Product's data" << endl;
	cout << "3. Add a product to the bucket" << endl;
	cout << "4. Delete a product from the bucket" << endl;
	cout << "5. Delete a product from the stock" << endl;
	cout << "6. Checkout" << endl;
	cout << "7. Exit" << endl;

	int res;
	cin >> res;

	return res;
}

Product Product_input()
{
	Product myProduct;

	//Inputting name

	char* service_name_array = new char[myProduct.ln];

	cout << "Input name: ";
	cin.get(service_name_array, myProduct.ln);

	int i = 0;
	while (service_name_array[i - 1] != '\0') //Really it's valid data
	{
		myProduct.name[i] = service_name_array[i];
		i++;
	}

	delete[] service_name_array;

	//Inputting price and quantity

	cout << "Input price: ";
	cin >> myProduct.price;
	cout << "Input quantity: ";
	cin >> myProduct.quantity;
	cout << endl;

	return myProduct;
}

void Product_print(const Product& myProduct)
{
	int i = 0;
	while (myProduct.name[i] != '\0')
	{
		cout << myProduct.name[i];
		i++;
	}

	cout << setw(SETW_PARAM) << myProduct.price << setw(SETW_PARAM) << myProduct.quantity << endl;
}