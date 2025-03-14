//
// Created by balio on 3/12/2025.
//

#include "EmployeeTypes.h"

// ================= FullTimeEmployee Implementation =================

// Constructor: Initializes a full-time employee with ID, name, and fixed monthly salary
FullTimeEmployee::FullTimeEmployee(string id, string name, float salary)
    : Employee(id, name, salary) {}

// Computes and returns the fixed monthly salary for a full-time employee
float FullTimeEmployee::computeSalary() const {
    return getSalary();
}

// Prints the details of the full-time employee
void FullTimeEmployee::print() const {
    printf("Employee: %s (ID: %s)\n", getName().c_str(), getId().c_str());
    printf("Fixed Monthly Salary: $%.2f\n", computeSalary());
}

// Gets user input for full-time employee details and adds it to the employee list
void FullTimeEmployee::getDetails(vector<Employee*> &employees) {
    float salary;

    setIdAndName(employees); // Set employee ID and name

    // Get valid salary input
    getValidatedInput("Enter Fixed Monthly Salary: ", salary, 1, 50000000);

    setSalary(salary);
}

// ================= PartTimeEmployee Implementation =================

// Constructor: Initializes a part-time employee with ID, name, hourly wage, and hours worked
PartTimeEmployee::PartTimeEmployee(string id, string name, float salary, int hoursWorked)
    : Employee(id, name, salary), hoursWorked(hoursWorked) {}

// Computes and returns the salary based on hourly wage and hours worked
float PartTimeEmployee::computeSalary() const {
    return getSalary() * hoursWorked;
}

// Prints the details of the part-time employee
void PartTimeEmployee::print() const {
    printf("Employee: %s (ID: %s)\n", getName().c_str(), getId().c_str());
    printf("Hourly Wage: $%.2f\n", getSalary());
    printf("Hours Worked: %d\n", hoursWorked);
    printf("Total Salary: $%.2f\n", computeSalary());
}

// Gets user input for part-time employee details and adds it to the employee list
void PartTimeEmployee::getDetails(vector<Employee*> &employees) {
    float salary;

    setIdAndName(employees); // Set employee ID and name

    // Get valid hourly wage input
    getValidatedInput("Enter Hourly Wage: ", salary, 1, 50000000);

    // Get valid hours worked input
    getValidatedInput("Enter Hours Worked: ", hoursWorked, 1, 50000000);

    setSalary(salary);
}

// ================= ContractualEmployee Implementation =================

// Constructor: Initializes a contractual employee with ID, name, salary per project, and number of projects
ContractualEmployee::ContractualEmployee(string id, string name, float salary, int numbersOfProject)
    : Employee(id, name, salary), numbersOfProject(numbersOfProject) {}

// Computes and returns the salary based on projects completed and payment per project
float ContractualEmployee::computeSalary() const {
    return getSalary() * numbersOfProject;
}

// Prints the details of the contractual employee
void ContractualEmployee::print() const {
    printf("Employee: %s (ID: %s)\n", getName().c_str(), getId().c_str());
    printf("Contract Payment per Project: $%.2f\n", getSalary());
    printf("Projects Completed: %d\n", numbersOfProject);
    printf("Total Salary: $%.2f\n", computeSalary());
}

// Gets user input for contractual employee details and adds it to the employee list
void ContractualEmployee::getDetails(vector<Employee*> &employees) {
    float salary;

    setIdAndName(employees); // Set employee ID and name

    // Get valid payment per project input
    getValidatedInput("Enter payment per project: ", salary, 1, 50000000);

    // Get valid number of projects completed input
    getValidatedInput("Enter number of projects completed: ", numbersOfProject, 1, 50000000);

    setSalary(salary);
}
