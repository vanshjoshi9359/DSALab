#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int n;
    struct Employee emp;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    FILE *fp = fopen("employees.dat", "wb");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter employee ID, name and salary: ");
        scanf("%d %49s %f", &emp.id, emp.name, &emp.salary);
        fwrite(&emp, sizeof(struct Employee), 1, fp);
    }
    fclose(fp);
    fp = fopen("employees.dat", "rb+");
    if (fp == NULL) {
        printf("Unable to open file for updating.\n");
        return 1;
    }
    printf("\nUpdated employee salaries:\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.salary > 50000)
            emp.salary = emp.salary * 1.05f;
        else if (emp.salary > 20000 && emp.salary < 50000)
            emp.salary = emp.salary * 1.10f;
        else
            emp.salary = emp.salary * 1.03f;
        fseek(fp, -(long)sizeof(struct Employee), SEEK_CUR);
        fwrite(&emp, sizeof(struct Employee), 1, fp);
        printf("ID: %d, Name: %s, Updated Salary: %.2f\n",
               emp.id, emp.name, emp.salary);
        fseek(fp, 0, SEEK_CUR);
    }
    fclose(fp);
    printf("Employee records updated in employees.dat\n");
    return 0;
}
