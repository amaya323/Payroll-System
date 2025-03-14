//
// Created by balio on 3/12/2025.
//

#ifndef EMPLOYEETYPES_H
#define EMPLOYEETYPES_H
#include "Employee.h"
#include "../Functions.h"


class FullTimeEmployee: public Employee {
public:
    FullTimeEmployee(string id, string name, float salary);

    float computeSalary() const override;

    void print() const override;

    void getDetails(vector<Employee *> &employee) override;
};

class PartTimeEmployee: public Employee {
private:
    int hoursWorked;
public:
    PartTimeEmployee(string id, string name, float salary, int hoursWorked);

    float computeSalary() const override;

    void print() const override;

    void getDetails(vector<Employee *> &employee) override;
};

class ContractualEmployee: public Employee {
private:
    int numbersOfProject;
public:
    ContractualEmployee(string id, string name, float salary, int numbersOfProject);

    float computeSalary() const override;

    void print() const override;

    void getDetails(vector<Employee *> &employee) override;
};





#endif //EMPLOYEETYPES_H
