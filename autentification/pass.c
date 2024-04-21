#include <stdio.h>
#include <string.h>
#include <math.h>

// Define structures for loan policies and banks
typedef struct {
    char name[50];
    float (*loanCalculation)(float, int); // Function pointer for loan calculation
} Bank;

// Loan calculation functions for each bank
float calculateLoanBankA(float price, int months) {
    // Example loan calculation formula for Bank A
    float interestRate = 0.05; // 5% interest rate for Bank A
    return price * (1 + interestRate) / months;
}

float calculateLoanBankB(float price, int months) {
    // Example loan calculation formula for Bank B
    float interestRate = 0.06; // 6% interest rate for Bank B
    return price * (1 + interestRate) / months;
}

float calculateLoanBankC(float price, int months) {
    // Example loan calculation formula for Bank C
    float interestRate = 0.055; // 5.5% interest rate for Bank C
    return price * (1 + interestRate) / months;
}

int main() {
    Bank banks[3] = {
        {"Bank A", calculateLoanBankA},
        {"Bank B", calculateLoanBankB},
        {"Bank C", calculateLoanBankC}
    };

    float price;
    int bankChoice, loanType, loanTermMonths;
    float totalLoan, monthlyPayment;

    printf("Enter the price of the item you want to buy: $");
    scanf("%f", &price);

    printf("Select a bank to take the loan:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, banks[i].name);
    }
    printf("Choice: ");
    scanf("%d", &bankChoice);
    bankChoice--; // Adjust for zero-based indexing

    printf("Choose the type of loan:\n");
    printf("1. Mortgage Loan\n2. Fixed-Rate Loan\nChoice: ");
    scanf("%d", &loanType);
    loanType--; // Adjust for zero-based indexing

    printf("Enter the loan term in months: ");
    scanf("%d", &loanTermMonths);

    // Calculate total loan amount based on bank's loan calculation formula
    totalLoan = banks[bankChoice].loanCalculation(price, loanTermMonths) * loanTermMonths;
    monthlyPayment=totalLoan/loanTermMonths;

    // Display loan details
    printf("\nLoan Details:\n");
    printf("Total Loan Amount: $%.2f\n", totalLoan);
    printf("Monthly payment: %.2f",monthlyPayment );

    return 0;
}
