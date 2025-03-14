//
// Created by balio on 3/10/2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <algorithm>
using namespace std;

// Function to print a formatted title
void printTitle(const string &title);

// Function to display the main menu
void displayMenu();

void removeWhitespace(string &output);


void getInput(string prompt, string &output);

// Function to validate user input as an integer choice
bool validNumber(const string &input, int &output);

// Function to validate user input as an integer choice
bool validFloat(const string &input, float &output);

// Generic function to validate float input within a range
void getValidatedInput(const string &prompt, float &output, int minVal, int maxVal) ;

// Generic function to validate numerical input within a range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal);

void printMenu();

void askYesOrNo(string question, char &yOrN);

string capitalizeName(const string& name);

bool isValidName(const string& name);

#endif //FUNCTIONS_H
