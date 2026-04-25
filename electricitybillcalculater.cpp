#include <iostream>
#include "ElectricityBill.h"
using namespace std;

int main() {

	int units1, units2, months;
	double rate2;

	cout << "Enter units for Bill 1: ";
	cin >> units1;

	cout << "Enter units for Bill 2: ";
	cin >> units2;

	cout << "Enter rate for Bill 2: ";
	cin >> rate2;

	cout << "Enter number of months to multiply Bill 1 by: ";
	cin >> months;

	ElectricityBill b1(units1);
	ElectricityBill b2(units2, rate2);

	cout << endl;
	cout << "--- Bill 1 ---" << endl;
	cout << b1 << endl;

	cout << "--- Bill 2 ---" << endl;
	cout << b2 << endl;

	ElectricityBill b3 = b1 + b2;
	cout << "--- Combined Bill ---" << endl;
	cout << b3 << endl;

	ElectricityBill b4 = b2 - b1;
	cout << "--- Subtracted Bill ---" << endl;
	cout << b4 << endl;

	ElectricityBill b5 = b1 * months;
	cout << "--- Bill 1 for " << months << " Months ---" << endl;
	cout << b5 << endl;

	if (b1 < b2)
	{
		cout << "Bill 1 is less than Bill 2" << endl;
	}
	else
	{
		cout << "Bill 1 is greater or equal to Bill 2" << endl;
	}

	if (b1 == b2)
	{
		cout << "Both bills are equal" << endl;
	}
	else
	{
		cout << "Bills are not equal" << endl;
	}

	return 0;
}