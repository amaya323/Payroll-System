//
// Created by balio on 3/12/2025.
//
#include "Functions.h"
#include <regex>
void printTitle(const string &title) {
    system("cls"); // Clear the console screen (Windows-specific)
    int length = title.length();
    int padding = max(10, 30 - length); // Ensure a minimum padding of 10, max 30 - title length
    string border(padding, '=');

    // Print a formatted title with borders
    cout << "\n" << border << " " << title << " " << border << "\n" << endl;
}

void removeWhitespace(string &output) {
    output.erase(std::remove_if(output.begin(), output.end(), ::isspace), output.end());
}


void getInput(string prompt, string &output) {
    cout << prompt;
    getline(cin, output);
}

// Function to validate user input as an integer choice
bool validNumber(const string &input, int &output) {
    // Check if the input contains a decimal point (not an integer)
    if (input.find('.') != string::npos) {
        output = -1;
        return false;
    }

    // Ensure all characters are digits
    for (char c: input) {
        if (!isdigit(c)) {
            output = -1;
            return false;
        }
    }

    try {
        // Convert input string to integer
        output = stoi(input);

        // Ensure input is a positive integer
        if (output <= 0) {
            output = -1;
            return false;
        }
        return true;
    }
    // Catch exceptions for invalid input (non-numeric or out-of-range values)
    catch (invalid_argument &e) {
        output = -1;
        return false;
    }
    catch (out_of_range &e) {
        output = -1;
        return false;
    }
}

// Function to validate user input as an integer choice
bool validFloat(const string &input, float &output) {
    try {
        // Convert input string to integer
        output = stof(input);

        // Ensure input is a positive integer
        if (output <= 0) {
            output = -1;
            return false;
        }
        return true;
    }

    // Catch exceptions for invalid input (non-numeric or out-of-range values)
    catch (invalid_argument &e) {
        output = -1;
        return false;
    }
    catch (out_of_range &e) {
        output = -1;
        return false;
    }
}

// Generic function to validate float input within a range
void getValidatedInput(const string &prompt, float &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;

    do {
        cout << prompt;
        getline(cin, input);

        if (validFloat(input, output) && output >= minVal && output <= maxVal) {
            isValid = true;
        } else {
            cout << "Error: Invalid input. Please enter a valid value.\n";
        }
    } while (!isValid);
}

// Generic function to validate numerical input within a range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;

    do {
        cout << prompt;
        getline(cin, input);

        if (validNumber(input, output) && output >= minVal && output <= maxVal) {
            isValid = true;
        } else {
            cout << "Error: Invalid input. Please enter a number between " << minVal << " and " << maxVal << ".\n";
        }
    } while (!isValid);
}

void printMenu(){
    system("cls"); // Clear the console screen
    printTitle("Payroll System Menu");

    // Display Options
    cout << "[1] Full-time Employee" << endl;
    cout << "[2] Part-time Employee" << endl;
    cout << "[3] Contractual Employee" << endl;
    cout << "[4] Display Payroll Report" << endl;
    cout << "[5] Exit" << endl;
}

void askYesOrNo(string question, char &yOrN) {
    cout << endl << question;
    string placeholder;
    // Ensure input is only 'Y' or 'N' (case-insensitive)
    do {
        getline(cin, placeholder);
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n'));
}

string capitalizeName(const string& name) {
    string formattedName;
    bool capitalizeNext = true; // Flag to capitalize first letter of each word

    for (size_t i = 0; i < name.length(); ++i) {
        char ch = name[i];

        if (isalpha(ch)) {
            // If capitalizeNext is true, make uppercase, otherwise lowercase
            if (capitalizeNext) {
                formattedName += toupper(ch);
            } else {
                formattedName += tolower(ch);
            }
            capitalizeNext = false; // Next letters should be lowercase
        }
        // Preserve single apostrophes in names (O'Neil, D'Souza)
        else if (ch == '\'' && !formattedName.empty() && i + 1 < name.length() && isalpha(name[i + 1])) {
            formattedName += '\'';
            capitalizeNext = false; // Don't capitalize after an apostrophe
        }
        // Handle spaces
        else if (isspace(ch)) {
            if (!formattedName.empty() && formattedName.back() != ' ') {
                formattedName += ' '; // Keep only one space between words
            }
            capitalizeNext = true;
        }
    }

    // Remove trailing space if exists
    if (!formattedName.empty() && formattedName.back() == ' ') {
        formattedName.pop_back();
    }

    return formattedName;
}

bool isValidName(const string& name) {
    // Regular expression: Allows letters (A-Z, a-z), spaces, and single apostrophes within words
    string pattern = "^[A-Za-z]+(?:[' ]?[A-Za-z]+)*$";

    // Match the name against the pattern
    if (!regex_match(name, regex(pattern))) {
        cout << "Error: Invalid Name! Only letters, spaces, and single apostrophes are allowed." << endl;
        return false;
    }

    return true; // Name is valid
}


