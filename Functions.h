//
// Created by balio on 3/10/2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <algorithm>
using namespace std;

// Prints a formatted title with borders
void printTitle(const string &title);

// Displays the main menu for the payroll system
void displayMenu();

// Removes all whitespace characters from a string
void removeWhitespace(string &output);

// Gets user input as a string
void getInput(string prompt, string &output);

// Validates if the input is a positive integer
bool validNumber(const string &input, int &output);

// Validates if the input is a positive floating-point number
bool validFloat(const string &input, float &output);

// Gets and validates a float input within a specified range
void getValidatedInput(const string &prompt, float &output, int minVal, int maxVal);

// Gets and validates an integer input within a specified range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal);

// Prints the payroll system menu
void printMenu();

// Asks the user a Yes/No question and validates the response
void askYesOrNo(string question, char &yOrN);

// Capitalizes the first letter of each word in a name
string capitalizeName(const string& name);

// Validates if the given name contains only letters, spaces, and single apostrophes
bool isValidName(const string& name);

#endif // FUNCTIONS_H
