#include "Imports.hpp"

int main() {
    // Vector to store pointers to Employee objects
    vector<Employee*> employees;
    int menuChoice; // Variable to store user menu choice

    do {
        char inputAgain; // Variable to handle user decision for adding more employees

        // Display the main menu and get user choice
        printMenu();
        getValidatedInput("Enter your choice: ", menuChoice, 1, 5);

        // Option to add a Full-time Employee
        if (menuChoice == 1) {
            printTitle("Full-time Employee");
            do {
                // Dynamically allocate a new FullTimeEmployee object
                auto* employee = new FullTimeEmployee("", "", 0);
                employee->getDetails(employees); // Get employee details
                employees.push_back(employee); // Store in employee list

                // Ask if the user wants to input another employee
                askYesOrNo("Input another full-time employee [y/n]: ", inputAgain);
            } while (inputAgain == 'y');

        // Option to add a Part-time Employee
        } else if (menuChoice == 2) {
            printTitle("Part-time Employee");
            do {
                // Dynamically allocate a new PartTimeEmployee object
                auto* employee = new PartTimeEmployee("", "", 0, 0);
                employee->getDetails(employees); // Get employee details
                employees.push_back(employee); // Store in employee list

                // Ask if the user wants to input another employee
                askYesOrNo("Input another part-time employee [y/n]: ", inputAgain);
            } while (inputAgain == 'y');

        // Option to add a Contractual Employee
        } else if (menuChoice == 3) {
            printTitle("Contractual Employee");
            do {
                // Dynamically allocate a new ContractualEmployee object
                auto* employee = new ContractualEmployee("", "", 0, 0);
                employee->getDetails(employees); // Get employee details
                employees.push_back(employee); // Store in employee list

                // Ask if the user wants to input another employee
                askYesOrNo("Input another contractual employee [y/n]: ", inputAgain);
            } while (inputAgain == 'y');

        // Option to display the payroll report
        } else if (menuChoice == 4) {
            printTitle("Payroll Report");
            Company myCompany(employees); // Create a Company object with employees
            myCompany.printPayrollReport(); // Display payroll report

            // Ensure the user sees the report before returning to the menu
            do {
                askYesOrNo("Return to Menu (y/n): ", inputAgain);
            } while (inputAgain == 'n');

        // Handle invalid menu input
        } else {
            cout << "Error: Please enter one of the choices" << endl;
        }

    } while (menuChoice != 5); // Exit loop when user selects option 5 (Exit)

    return 0;
}