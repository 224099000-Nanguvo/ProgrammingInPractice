#include <stdio.h>

int main () {
double revenue;
double expenses;
double balance;

printf("MUNICIPAL BUDGET CALCULATIONS\n");
printf(".............................\n");

printf("Enter total revenue: ");
scanf("%lf", &revenue);

printf("Enter total expenses: ");
scanf("%lf", &expenses);

balance = revenue - expenses;

printf("\nRevenue: %.2f\n", revenue); 
printf("Expenses: %.2f\n", expenses);

if (balance > 0) { 
printf("Surplus: %.2f\n", balance); 
} 
else if (balance < 0) { 
printf("Deficit: %.2f\n", -balance);
}
else{ 
printf("Budget balance: %.2f\n", balance);
}
return 0;

}

