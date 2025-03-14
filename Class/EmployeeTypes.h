//
// Created by balio on 3/12/2025.
//

#ifndef EMPLOYEETYPES_H
#define EMPLOYEETYPES_H

#include "Employee.h"
#include "../Functions.h"

// Class representing a full-time employee
class FullTimeEmployee: public Employee {
public:
    // Constructor to initialize a full-time employee with ID, name, and salary
    FullTimeEmployee(string id, string name, float salary);

    // Computes and returns the salary of the full-time employee
    float computeSalary() const override;

    // Prints the details of the full-time employee
    void print() const override;

    // Gets user input for full-time employee details and adds to the employee list
    void getDetails(vector<Employee *> &employee) override;
};

// Class representing a part-time employee
class PartTimeEmployee: public Employee {
private:
    int hoursWorked; // Number of hours worked by the employee
public:
    // Constructor to initialize a part-time employee with ID, name, salary, and hours worked
    PartTimeEmployee(string id, string name, float salary, int hoursWorked);

    // Computes and returns the salary of the part-time employee based on hours worked
    float computeSalary() const override;

    // Prints the details of the part-time employee
    void print() const override;

    // Gets user input for part-time employee details and adds to the employee list
    void getDetails(vector<Employee *> &employee) override;
};

// Class representing a contractual employee
class ContractualEmployee: public Employee {
private:
    int numbersOfProject; // Number of projects handled by the employee
public:
    // Constructor to initialize a contractual employee with ID, name, salary, and number of projects
    ContractualEmployee(string id, string name, float salary, int numbersOfProject);

    // Computes and returns the salary of the contractual employee based on projects completed
    float computeSalary() const override;

    // Prints the details of the contractual employee
    void print() const override;

    // Gets user input for contractual employee details and adds to the employee list
    void getDetails(vector<Employee *> &employee) override;
};

#endif // EMPLOYEETYPES_H
