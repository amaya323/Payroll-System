#include "Imports.hpp"


int main() {
    vector <Employee*> employees;
    int menuChoice;

    do {
        char inputAgain;
        printMenu();
        getValidatedInput("Enter your choice: ", menuChoice, 1, 5);
        if (menuChoice == 1) {
            printTitle("Full-time Employee");
            do {
                auto* employee = new FullTimeEmployee("", "", 0);
                employee->getDetails(employees);
                employees.push_back(employee);

                askYesOrNo("Input another full-time employee [y/n]: ", inputAgain);
            }while (inputAgain == 'y');

        }else if (menuChoice == 2) {
            printTitle("Part-time Employee");
            do {
                auto* employee = new PartTimeEmployee("", "", 0, 0);
                employee->getDetails(employees);
                employees.push_back(employee);

                askYesOrNo("Input another part-time employee [y/n]: ", inputAgain);
            }while (inputAgain == 'y');
        }else if (menuChoice == 3) {
            printTitle("Contractual Employee");
            do {
                auto* employee = new ContractualEmployee("", "", 0, 0);
                employee->getDetails(employees);
                employees.push_back(employee);

                askYesOrNo("Input another contractual employee [y/n]: ", inputAgain);
            }while (inputAgain == 'y');
        }else if (menuChoice == 4) {
            printTitle("Payroll Report");
            Company myCompany(employees);
            myCompany.printPayrollReport();

            do {
                askYesOrNo("Return to Menu (y/n): ", inputAgain);
            }while (inputAgain == 'n');

        }else {
            cout << "Error: Please enter one of the choices" << endl;
        }
    }while (menuChoice != 5);
    return 0;
}