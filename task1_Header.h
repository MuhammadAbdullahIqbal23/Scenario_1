//Muhammad_Abdullah_Abdullah_Iqbal_22i2504
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
struct EmployeeData {
    T name;
    T employeeID;
    double salary;
    double dateOfJoining;
    T designation;

    EmployeeData(const T& name, const T& employeeID, double salary, double dateOfJoining, const T& designation)
        : name(name), employeeID(employeeID), salary(salary), dateOfJoining(dateOfJoining), designation(designation)
    {
    }

    EmployeeData() = default;
};

template <typename T>
int ReadEmployeeData(const char* filename, EmployeeData<T> employees[], int maxEmployees) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int employeeCount = 0;
    double totalSalary = 0.0;
    double totalTenure = 0.0;
    double longestTenure = 0.0;
    int designationCounts[10] = { 0 };

    for (int i = 0; i < maxEmployees; ++i) {
        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].name);

        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].employeeID);

        inputFile.ignore(100, '$');
        inputFile >> employees[i].salary;
        totalSalary += employees[i].salary;

        inputFile.ignore(100, ':');
        inputFile >> employees[i].dateOfJoining;
        totalTenure += employees[i].dateOfJoining;

        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].designation);

        inputFile.ignore(2, '\n');
        
        employeeCount++;
        for (int j = 0; j < i; ++j) {
            if (employees[i].designation == employees[j].designation) {
                designationCounts[j]++;
                break;
            }
            
        }
    }
    inputFile.close();
    if (employeeCount > 0) {
        int LongestTenureIndex = 0;
        for (int i = 1; i < maxEmployees; i++) {
            if (employees[i].dateOfJoining < employees[LongestTenureIndex].dateOfJoining) {
                LongestTenureIndex = i;
            }
        }
        double averageSalary = totalSalary / employeeCount;
        double averageTenure = totalTenure / employeeCount;
        cout << "Average Salary in the company: $" << averageSalary <<"K" << endl;
        cout << "Total number of employees: " << employeeCount << endl;
        cout << "Average tenure in the company: " << 2023 - averageTenure << " years" << endl;
        cout << "Distribution of employees based on their designations:" << endl;
        for (int i = 0; i < 8; ++i) {
            if (i == 6) {
                cout << "";
            }
            else {
                cout << employees[i].designation << ": " << (designationCounts[i] + 1) << " employees" << endl;
            }
        }
        cout << "Employee with the longest tenure:" << employees[LongestTenureIndex].name << endl;
    }
    else {
        cout << "No employee data found." << endl;
    }
    return 0;
}

