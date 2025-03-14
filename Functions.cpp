#include "Functions.h"
#include <regex>

// Prints a formatted title with a border
void printTitle(const string &title) {
    system("cls"); // Clear console screen (Windows-specific)
    int length = title.length();
    int padding = max(10, 30 - length);
    string border(padding, '=');
    cout << "\n" << border << " " << title << " " << border << "\n" << endl;
}

// Removes all whitespace characters from a string
void removeWhitespace(string &output) {
    output.erase(std::remove_if(output.begin(), output.end(), ::isspace), output.end());
}

void getInput(string prompt, string &output) {
    cout << prompt;
    getline(cin, output);
}

// Validates if input is a positive integer
bool validNumber(const string &input, int &output) {
    if (input.find('.') != string::npos) {
        cout << "Error: Please enter a whole number." << endl << endl;
        return false;
    }
    for (char c: input) {
        if (!isdigit(c) && (input[0] != '-')) {
            cout << "Error: Please enter a whole number." << endl << endl;
            return false;
        }
    }
    try {
        output = stoi(input);
        if (output <= 0) {
            cout << "Error: Please enter a value greater than 0." << endl << endl;
            return false;
        }
        return true;
    } catch (invalid_argument &e) {
        output = -1;
        return false;
    } catch (out_of_range &e) {
        output = -1;
        return false;
    }
}

// Validates if input is a positive float
bool validFloat(const string &input, float &output) {
    try {
        output = stof(input);
        if (output <= 0) {
            output = -1;
            return false;
        }
        return true;
    } catch (invalid_argument &e) {
        output = -1;
        return false;
    } catch (out_of_range &e) {
        output = -1;
        return false;
    }
}

// Gets validated float input within a specified range
void getValidatedInput(const string &prompt, float &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;
    do {
        cout << prompt;
        getline(cin, input);
        if (validFloat(input, output) && output >= minVal && output <= maxVal) {
            isValid = true;
        } else {
            cout << "Error: Invalid input." << endl << endl;
        }
    } while (!isValid);
}

// Gets validated integer input within a specified range
void getValidatedInput(const string &prompt, int &output, int minVal, int maxVal) {
    string input;
    bool isValid = false;
    do {
        cout << prompt;
        getline(cin, input);
        if (validNumber(input, output) && output >= minVal && output <= maxVal) {
            isValid = true;
        }
    } while (!isValid);
}

// Displays the main menu for the payroll system
void printMenu(){
    system("cls"); // Clear the console screen
    printTitle("Payroll System Menu");
    cout << "[1] Full-time Employee" << endl;
    cout << "[2] Part-time Employee" << endl;
    cout << "[3] Contractual Employee" << endl;
    cout << "[4] Display Payroll Report" << endl;
    cout << "[5] Exit" << endl;
}

// Asks the user a Yes/No question and validates input
void askYesOrNo(string question, char &yOrN) {
    cout << endl << question;
    string placeholder;
    do {
        getline(cin, placeholder);
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n'));
}

// Capitalizes the first letter of each word in a name
string capitalizeName(const string& name) {
    string formattedName;
    bool capitalizeNext = true;
    for (size_t i = 0; i < name.length(); ++i) {
        char ch = name[i];
        if (isalpha(ch)) {
            formattedName += capitalizeNext ? toupper(ch) : tolower(ch);
            capitalizeNext = false;
        } else if (ch == '\'' && !formattedName.empty() && i + 1 < name.length() && isalpha(name[i + 1])) {
            formattedName += '\'';
            capitalizeNext = false;
        } else if (isspace(ch)) {
            if (!formattedName.empty() && formattedName.back() != ' ') {
                formattedName += ' ';
            }
            capitalizeNext = true;
        }
    }
    if (!formattedName.empty() && formattedName.back() == ' ') {
        formattedName.pop_back();
    }
    return formattedName;
}

// Checks if a name is valid (letters, spaces, and apostrophes only)
bool isValidName(const string& name) {
    string pattern = "^[A-Za-z]+(?:[' ]?[A-Za-z]+)*$";
    if (name.empty()) {
        return false;
    }

    if (!regex_match(name, regex(pattern))) {
        cout << "Error: Invalid Name! Only letters, spaces, and single apostrophes are allowed." << endl << endl;
        return false;
    }
    return true;
}
