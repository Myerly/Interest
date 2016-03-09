#include <iostream>
#include <string>

using namespace std;

#include "FutureValue.h"
#include "validation.h"

//==========================================================================
//Program to calculate future value of a savings account
//==========================================================================
double FutureValue()
{
	//Algorithm: Future Value (FV) = P * (1 + r/n)^n*t
	//
	// WHERE:
	//
	// P = Principle (initial amount deposited)
	// r = Annual Interest Rate (between 0 and 1)
	// n = Number of compounding periods per year
	// t = time (in years) until money withdrawn

	double P = 0;
	double r = 0;
	int  n = 0;
	double t = 0;
	double FV = 0;

	cout << "This program will compute Future Value of an amoun invested in a checking account ";
	cout << "for a given number of years at a given fixed interest rate and a given number of ";
	cout << "compounding periods per year";

	cout << endl;
	cout << endl;


	// Get Principle
	cout << "Please enter the initial amount invested in dollars           : ";
	cin >> P;

	cout << endl;

	// Get Annual Inerest Rate
	cout << "Please enter the annual intereset rate in percentage (0-100)  : ";
	cin >> r;

	cout << endl;

	//Convert percent interest to number between 0 and 1
	r = r / 100;

	// Get Number of compounding periods per year
	cout << "Please enter the Number of compounding periods per year       : ";
	cin >> n;

	cout << endl;

	// Get Number of years before money is withdrawn
	cout << "Please enter the Number of years before money is withdrawn    : ";
	cin >> t;

	//Compute Future Value based on equation stated above in Algorithm
	FV = P * pow((1 + r / n), n*t);

	cout << endl;
	cout << endl;

	// Display Future Value to user
	cout << "Future Value is												  : " << FV;
	cout << endl;

	cout << "Thank you for using he program";

	return FV;
}

//==========================================================================
//Program to calculate future value of a savings account
//==========================================================================
double FutureValue2()
{
	//Algorithm: Future Value (FV) = P * (1 + r/n)^n*t
	//
	// WHERE:
	//
	// P = Principle (initial amount deposited)
	// r = Annual Interest Rate (between 0 and 1)
	// n = Number of compounding periods per year
	// t = time (in years) until money withdrawn

	double P = 0;
	double r = 0;
	int  n = 0;
	double t = 0;
	double FV = 0;
	string input_data;

	cout << "This program will compute Future Value of an amoun invested in a checking account ";
	cout << "for a given number of years at a given fixed interest rate and a given number of ";
	cout << "compounding periods per year";

	cout << endl;
	cout << endl;


	// Get Principle
	cout << "Please enter the initial amount invested in dollars           : ";
	getline(cin, input_data);

	P = atof(input_data.c_str());


	cout << endl;

	// Get Annual Inerest Rate
	cout << "Please enter the annual intereset rate in percentage (0-100)  : ";
	getline(cin, input_data);

	if (valid_double(input_data))
	{
		r = atof(input_data.c_str());
	}


	cout << endl;

	//Convert percent interest to number between 0 and 1
	r = r / 100;

	// Get Number of compounding periods per year
	cout << "Please enter the Number of compounding periods per year       : ";
	getline(cin, input_data);
	n = atoi(input_data.c_str());

	cout << endl;

	// Get Number of years before money is withdrawn
	cout << "Please enter the Number of years before money is withdrawn    : ";
	getline(cin, input_data);
	t = atof(input_data.c_str());

	//Compute Future Value based on equation stated above in Algorithm
	FV = P * pow((1 + r / n), n*t);

	cout << endl;
	cout << endl;

	// Display Future Value to user
	cout << "Future Value is												  : " << FV;
	cout << endl;

	cout << "Thank you for using he program";

	return FV;
}

