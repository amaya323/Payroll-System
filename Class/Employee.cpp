//
// Created by balio on 3/12/2025.
//

#include "Employee.h"

Employee::Employee(string id, string name, float salary) {
    this->id = id;
    this->name = name;
    this->salary = salary;
}

string Employee::getId() const {
    return id;
}

string Employee::getName() const {
    return name;
}

float Employee::getSalary() const {
    return salary;
}

void Employee::setIdAndName(vector <Employee*> &employees) {
    bool isValid;
    do {
        isValid = true;
        getInput("Enter employee ID: ", id);
        removeWhitespace(id);
        if (isDuplicate(employees, id)) {
            cout << "Error: Employee ID already exists" << endl << endl;
            isValid = false;
        }
        if (isValid && id.empty()) {
            isValid = false;
        }else{
            for (char c : id) {
                if (!isalnum(c)) {
                    cout << "Error: Employee ID must only contain numbers and letters" << endl << endl;
                    isValid = false;
                    break;
                }
            }
        }
    }while (!isValid);

    do {
        getInput("Enter employee Name: ", name);
        name = capitalizeName(name);
    }while (!isValidName(name));
}

void Employee::setSalary(float salary) {
    this->salary = salary;
}

bool Employee::isDuplicate(vector<Employee *> &employees, string id) {
    for (const auto &employee : employees) {
        if (employee->getId() == id) {
            return true;
        }
    }
    return false;
}





