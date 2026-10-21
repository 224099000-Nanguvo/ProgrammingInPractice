#include <stdio.h>

int main() {
    int employees = 50;
    float salaries[50];
    float total = 0, average, highest, lowest;
    float searchSalary;
    int found = 0;

    
    printf("Enter Salaries for Employees\n", employees);
    for (int i = 0; i < employees; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < employees; i++) {
        printf("Employee %d: $%.2f\n", i + 1, salaries[i]);
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < employees; i++) {
        total += salaries[i];

        if (salaries[i] > highest) {
            highest = salaries[i];
        }

        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    average = total / employees;

    printf("\n--- Salary Statistics ---\n");
    printf("Total Salary Expenditure: $%.2f\n", total);
    printf("Average Salary: $%.2f\n", average);
    printf("Highest Salary: $%.2f\n", highest);
    printf("Lowest Salary: $%.2f\n", lowest);


    printf("\nEnter a salary amount to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < employees; i++) {
        if (salaries[i] == searchSalary) {
            printf("Found! Salary $%.2f is at Employee position %d\n", searchSalary, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Salary $%.2f not found in the records.\n", searchSalary);
    }

    for (int i = 0; i < employees - 1; i++) {
        for (int j = 0; j < employees - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                float temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\nSalaries Sorted (Lowest to Highest) \n");
    for (int i = 0; i < employees; i++) {
        printf("$%.2f\n", salaries[i]);
    }

    return 0;
}