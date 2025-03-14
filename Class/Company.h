//
// Created by balio on 3/12/2025.
//

#ifndef COMPANY_H
#define COMPANY_H
#include "EmployeeTypes.h"


class Company{
private:
    vector<Employee*> employees;
public:
    Company(vector<Employee*> employees);

    void printPayrollReport();
};



#endif //COMPANY_H
