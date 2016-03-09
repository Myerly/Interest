//Author: Jacob Myerly
//Date: 7 March 2016
//Program: Compund interest calculator.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <cmath>

#include "Validation.h"

#define	INTEREST_RATE_FORMAT_ERROR				-1
#define	DEPOSIT_AMOUNT_RATE_FORMAT_ERROR		-2
#define	COMPOUNDING_VALUE_FORMAT_ERROR			-3
#define	YEARS_UNTIL_withdrawal_FORMAT_ERROR		-4
#define	FUTURE_VALUE_FORMAT_ERROR				-5
#define INITIAL_DEPOSIT_AMOUNT_FORMAT_ERROR		-6

#define	INVALID_INTEREST_RATE_STRING			"Invalid interest rate must be numeric between 0 and 100!"
#define INTEREST_RATE_FORMAT_ERROR_STRING		"Error in data format for Annual Interest Rate - must be numeric value!" 
#define COMPOUNDING_VALUE_FORMAT_ERROR_STRING	"Error in data format for number of comounding periods - must be numeric between 0 and 12!" << endl;
#define	YEARS_UNTIL_withdrawal_ERROR_STRING		"Error in data format for years until withdrawal - must be numeric value!";
#define INITIAL_DEPOSIT_AMOUNT_ERROR_STRING		"Error in data format for initial deposit amount - must be numeric value!"

using namespace std;

int getIntValue(string);
double getDoubleValue(string);


int main(int argc, char *argv[])
{
	double principle = 0;
	double interestRate = 0;
	double time = 0;
	int compounded = 0;
	double total = 0;
	string input_data = "|";
	
	interestRate = getDoubleValue ("Please enter Annual Interest Rate in percentage:\n ");
	

	if (valid_double(input_data))
	{
		interestRate = atof(input_data.c_str());

		if (!validate_interest_rate(interestRate))
		{
			cout << INVALID_INTEREST_RATE_STRING << endl;
		}

		//Divide percentage value by 100 to obtain value between 0 and 1
		interestRate /= 100;	
	}


	compounded = getIntValue("How many compounding periods per year:\n ");

	if (valid_integer(input_data))
	{
		compounded = atoi(input_data.c_str());
	}

	time = getIntValue("Enter number of years before withdrawal:\n ");

	if (valid_integer(input_data))
	{
		time = atoi(input_data.c_str());
	}

	principle = getDoubleValue ("Enter the initial deposit amount:\n ");

	if (valid_double(input_data))
	{
		principle = atof(input_data.c_str());
	}

	double p = principle;
	double r = interestRate;
	double t = time;
	double n = compounded;
	
	/*total = principle * pow((1 + interestRate / compounded), compounded * time);*/
	total = p * pow((1 + r / n), n * t);

	//Display information to user
	cout << total << endl;

	return 0;
}

int getIntValue(string printMessage)
{
	string input_data = "|";
	int number = 0;
	bool done = false;

	while (!done)
	{
		cout << printMessage;
		getline(cin, input_data);

		if (valid_double(input_data))
		{
			number = atoi(input_data.c_str());
			done = true;
		}
		else
		{
			cout << "Invalid entry. Please try again.\n";
		}

	}
	return number;
}

double getDoubleValue(string printMessage)
{
	string input_data = "|";
	double number = 0;
	bool done = false;

	while (!done)
	{
		cout << printMessage;
		getline(cin, input_data);

		if (valid_double(input_data))
		{
			number = atof(input_data.c_str());
			done = true;
		}
		else
		{
			cout << "Invalid entry. Please try again.\n";
		}

	}
	return number;
}