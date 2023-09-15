#include <iostream>
#include "task1_Header.h"
using namespace std;
int main() {
    const char* filename = "Employeedata.txt"; // Replace with your file name
    const int maxEmployees = 10; // Adjust the maximum number of employees as needed
    EmployeeData<string> employees[maxEmployees]; // Assuming employee data is stored as strings

    int result = ReadEmployeeData(filename, employees, maxEmployees);

    return result;
}