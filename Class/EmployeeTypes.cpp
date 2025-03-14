//
// Created by balio on 3/12/2025.
//

#include "EmployeeTypes.h"


FullTimeEmployee::FullTimeEmployee(string id, string name, float salary): Employee(id, name, salary) {}

float FullTimeEmployee::computeSalary() const {
    return getSalary();
}

void FullTimeEmployee::print() const {
    printf("Employee: %s (ID: %s)\n", getName().c_str() ,getId().c_str());
    printf("Fixed monthly salary: $%.2f\n", computeSalary());
}

void FullTimeEmployee::getDetails(vector <Employee*> &employees) {
    float salary;

    setIdAndName(employees);

    getValidatedInput("Enter Fixed Monthly Salary: ", salary, 1, 50000000);

    setSalary(salary);
}

PartTimeEmployee::PartTimeEmployee(string id, string name, float salary, int hoursWorked): Employee(id, name, salary) {
    this->hoursWorked = hoursWorked;
}

float PartTimeEmployee::computeSalary() const {
    return getSalary() * hoursWorked;
}

void PartTimeEmployee::print() const {
    printf("Employee: %s (ID: %s)\n", getName().c_str() ,getId().c_str());
    printf("Hourly Wage: $%.2f\n", getSalary());
    printf("Hours Worked: %d\n", hoursWorked);
    printf("Total Salary: $%.2f\n", computeSalary());
}

void PartTimeEmployee::getDetails(vector<Employee *> &employees) {
    float salary;

    setIdAndName(employees);

    getValidatedInput("Enter Hourly Wage: ", salary, 1, 50000000);

    getValidatedInput("Enter Hours Worked: ", hoursWorked, 1, 50000000);

    setSalary(salary);
}

ContractualEmployee::ContractualEmployee(string id, string name, float salary, int numbersOfProject): Employee(id, name, salary) {
    this->numbersOfProject = numbersOfProject;
}

float ContractualEmployee::computeSalary() const {
    return getSalary() * numbersOfProject;
}

void ContractualEmployee::print() const {
    printf("Employee: %s (ID: %s)\n", getName().c_str() ,getId().c_str());
    printf("Contract Payment per Project: $%.2f\n", getSalary());
    printf("Projects Completed: %d\n", numbersOfProject);
    printf("Total Salary: $%.2f\n", computeSalary());
}

void ContractualEmployee::getDetails(vector<Employee *> &employees) {
    float salary;

    setIdAndName(employees);

    getValidatedInput("Enter payment per project: ", salary, 1, 50000000);
    getValidatedInput("Enter number of project completed: ", numbersOfProject, 1, 50000000);
    setSalary(salary);
}










