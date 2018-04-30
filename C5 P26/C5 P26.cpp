// C5 P26.cpp : Defines the entry point for the console application.
/********************************************************************************
 * By Mark Hawes																*
 * Rainfall Program reads in Rainfall.txt and outputs start month, end month,	*
 * total rainfall during the period using each months given rainfall,			*
 * and average rainfall	across the given period.								*
 * last updated 7/18/17															*
 ********************************************************************************/

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// function prototypes
void displayOutput(double average);
void closeMessage();
double calculateAverage(double total, int size);
void addToAmounts(double amount);
// declare variables
string startMonth, endMonth, fileName = "Rainfall.txt";
double total = 0.0;
vector<double> rainAmt;


/********************************************
 *				main function				*
 * main function for Rainfall program		*
 ********************************************/
int main()
{
	double tempAmt = 0.0; // local variable to store temporary data from file
	// read in file to program
	ifstream inputFile;
	inputFile.open(fileName); // initiate file
	// set fixed precision for decimals
	cout << fixed;
	cout << setprecision(2);

	//check file is valid
	if (inputFile) {
		// read in values from file 
		getline(inputFile, startMonth); // get start month
		getline(inputFile, endMonth); // get end month
		while (inputFile >> tempAmt) {
			addToAmounts(tempAmt); // add temp to needed storage - total and rainAmt
		}
		// calculate average and display outputs
		displayOutput(calculateAverage(total, rainAmt.size()));
	}
	else
		cout << "Error 404 - file not found"; // error message when file not found

	closeMessage();
    return 0;
}

/********************************************
 *				addToAmounts				*
 * takes in a value and adds it to total,	*
 * and to the vector containing rainfall	*
 ********************************************/
void addToAmounts(double amount) {
	rainAmt.push_back(amount); // get values and save to vector
	total += amount; // add value to total rainfall
}

/********************************************
 *				calculateAverage			*
 * calculates average rainfall with given 	*
 * inputs									*
 ********************************************/
double calculateAverage(double total, int size) {
	return total / size;
}

/********************************************
 *				displayOutput				*
 * display output message -- aka total		*
 * between months, and monthly average		*
 ********************************************/
void displayOutput(double average) {
	cout << "The total rainfall between " << startMonth << " and " << endMonth << " is: " << total << endl;
	cout << "Average monthly rainfall: " << average << endl;
}

/********************************************
 *				closeMessage				*
 * final statement of program that stops it *
 * from closing until user enters input		*
 ********************************************/
void closeMessage() {
	// changed end code to be less platform specific
	cout << "\nPress enter to exit program.\n";
	getchar();
}