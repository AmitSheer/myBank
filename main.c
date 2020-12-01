#include <stdio.h>
#include <ctype.h>
#include "myBank.h"

int getTheMoney(double *amount) {
    int numLength = scanf("%lf", amount);
    return *amount > 0 || numLength;
}

int main() {
    char value;
    double amount;
    int acc_id;
    int accountIsValid;
    while (1){
        value = ' ';
        acc_id = 0;
        amount = 0;
        printf("Please choose a transaction type: \n"
               " O-Open Account\n"
               " B-Balance Inquiry\n"
               " D-Deposit\n"
               " W-Withdrawal\n"
               " C-Close Account\n"
               " I-Interest\n"
               " P-Print\n"
               " E-Exit\n"
        );
        scanf(" %c", &value);
        if (value == 'B' || value == 'D' || value == 'W' || value == 'C') {
            printf("Please enter account number: ");
            scanf(" %d", &acc_id);
            accountIsValid = validateAccount(acc_id);
            if (!accountIsValid) {
                printf("Failed to read the account number\n\n");
            }
        }
        if (value == 'O') {
            printf("Please enter amount for deposit: ");
            if (getTheMoney(&amount)) {
                acc_id = openNewAccount(amount);
                if (acc_id == 1) {
                    printf("No space available\n");
                } else {
                    printf("New account number is: %d\n\n", acc_id);
                }
            }
        } else if (value == 'B') {
            if (accountIsValid) {
                amount = getBalance(acc_id);
                if (amount == -1) {
                    printf("This account is closed\n\n");
                } else {
                    printf("The balance of account number %d is: %.2lf\n\n", acc_id, amount);
                }
            }
        } else if (value == 'D') {
            if (accountIsValid) {
                printf("Please enter amount for deposit:  \n");
                if (getTheMoney(&amount)) {
                    deposit(acc_id, amount);
                } else {
                    printf("Failed to read the amount\n");
                }
            }
        } else if (value == 'W') {
            if (accountIsValid) {
                printf("Please enter the amount to withdraw: ");
                if (getTheMoney(&amount)) {
                    amount = withdraw(acc_id, amount);
                    if (amount == -1) {
                        printf("Cannot withdraw more than the balance\n\n");
                    } else {
                        printf("The new balance is: %.2lf \n\n", amount);
                    }
                } else {
                    printf("Failed to read the amount\n");
                }
            }
        } else if (value == 'I') {
            printf("Please enter interest rate: ");
            if (getTheMoney(&amount)) {
                increaseInterestAll(amount);
            } else {
                printf("Failed to read the interest rate\n");
            }
            printf("\n");
        } else if (value == 'P') {
            printALlAccounts();
        } else if (value == 'C' && accountIsValid) {
            if (accountIsValid) {
                closeAccount(acc_id);
            }
        } else if (value == 'E') {
            break;
        } else {
            printf("Invalid transaction type\n\n");
        }
    }
}