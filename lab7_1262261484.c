#include <stdio.h>

#define MAX_NAME_LEN 100
#define MAX_DEPT_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char department[MAX_DEPT_LEN];
    double basic_salary;
    double hra;
    double tra;
    double gross_salary;
} Employee;

int main(void) {
    Employee emp;
    double hra_rate, tra_rate;

    printf("=== Employee Salary Calculator ===\n");

    printf("Enter Employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        fprintf(stderr, "Invalid Employee ID.\n");
        return 1;
    }

    printf("Enter Employee Name: ");
    if (scanf(" %99[^\n]", emp.name) != 1) {
        fprintf(stderr, "Invalid Employee Name.\n");
        return 1;
    }

    printf("Enter Department: ");
    if (scanf(" %49[^\n]", emp.department) != 1) {
        fprintf(stderr, "Invalid Department.\n");
        return 1;
    }

    printf("Enter Basic Salary: ");
    if (scanf("%lf", &emp.basic_salary) != 1 || emp.basic_salary < 0) {
        fprintf(stderr, "Invalid Basic Salary.\n");
        return 1;
    }

    // Example slab-based rates:
    // Basic >= 50,000 -> HRA = 20%, TRA = 10%
    // Basic <  50,000 -> HRA = 15%, TRA = 8%
    if (emp.basic_salary >= 50000.0) {
        hra_rate = 0.20;
        tra_rate = 0.10;
    } else {
        hra_rate = 0.15;
        tra_rate = 0.08;
    }

    emp.hra = emp.basic_salary * hra_rate;
    emp.tra = emp.basic_salary * tra_rate;
    emp.gross_salary = emp.basic_salary + emp.hra + emp.tra;

    printf("\n=== Salary Slip ===\n");
    printf("Employee ID   : %d\n", emp.id);
    printf("Name          : %s\n", emp.name);
    printf("Department    : %s\n", emp.department);
    printf("-----------------------------\n");
    printf("Basic Salary  : %.2f\n", emp.basic_salary);
    printf("HRA (%.0f%%)    : %.2f\n", hra_rate * 100.0, emp.hra);
    printf("TRA (%.0f%%)    : %.2f\n", tra_rate * 100.0, emp.tra);
    printf("-----------------------------\n");
    printf("Gross Salary  : %.2f\n", emp.gross_salary);

    return 0;
}
