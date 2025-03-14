//
// Created by balio on 3/12/2025.
//

#ifndef COMPANY_H
#define COMPANY_H

#include "EmployeeTypes.h"

// Represents a company that manages employees
class Company {
private:
    vector<Employee*> employees; // List of employees in the company

public:
    // Constructor to initialize the company with a list of employees
    Company(vector<Employee*> employees);

    // Prints a payroll report for all employees
    void printPayrollReport();
};

#endif // COMPANY_H
