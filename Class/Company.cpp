//
// Created by balio on 3/12/2025.
//

#include "Company.h"
Company::Company(vector<Employee *> employees) {
    this->employees = employees;
}


void Company::printPayrollReport() {
    for (auto employee : employees) {
        employee->print();
        cout << endl;
    }
}
