//
// Created by balio on 3/12/2025.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
#include "../Functions.h"
using namespace std;

class Employee {
private:
    string id;
    string name;
    float salary;
public:
    virtual ~Employee() = default;

    Employee(string id, string name, float salary);

    virtual float computeSalary() const = 0;

    string getId() const;

    string getName() const;

    float getSalary() const;

    void setIdAndName(vector<Employee *> &employees);

    void setSalary(float salary);

    virtual void print() const = 0;

    virtual void getDetails(vector<Employee *> &employee) = 0;

    static bool isDuplicate(vector<Employee *> &employee, string id);


};



#endif //EMPLOYEE_H
