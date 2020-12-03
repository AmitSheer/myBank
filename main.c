#include <stdio.h>
#include <ctype.h>
#include "myBank.h"

int getTheMoney(double *amount,int status) {
    int numLength = scanf(" %lf", amount);
    if(*amount < 0) {
        if (!status){
            return 0;
        }else{
            printf("Invalid Amount\n\n");
            return 0;
        }
    }else if(!numLength){
        printf("Failed to read the amount\n\n");
        return 0;
    }
    return 1;
}

int main() {

    double amount;
    int acc_id;
    int accountIsValid;
    while (1){
        char value;
        acc_id = 0;
        amount = 0;
        printf("Please choose a transaction type:\n"
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
            if (accountIsValid==0) {
                printf("Failed to read the account number\n\n");
            }else if(accountIsValid==-1){
                printf("Invalid account number\n\n");
                accountIsValid=0;
            }else if(!accountIsOpen(acc_id)){
                accountIsValid=0;
                printf("This account is closed\n\n");
            }
        }
        if (value == 'O') {
            printf("Please enter amount for deposit: ");
            if (getTheMoney(&amount,1)) {
                acc_id = openNewAccount(amount);
                if (acc_id == 1) {
                    printf("No space available\n");
                } else {
                    printf("New account number is: %d \n\n", acc_id);
                }
            }
        } else if (value == 'B') {
            if (accountIsValid) {
                amount = getBalance(acc_id);
                printf("The balance of account number %d is: %.2lf\n\n", acc_id, amount);
            }
        } else if (value == 'D') {
            if (accountIsValid) {
                printf("Please enter the amount to deposit: ");
                getTheMoney(&amount,0);
                if (amount>0) {
                    printf("The new balance is: %.2lf \n\n",deposit(acc_id, amount));
                }else if(amount < 0){
                    printf("Cannot deposit a negative amount\n\n");
                }
            }
        } else if (value == 'W') {
            if (accountIsValid) {
                printf("Please enter the amount to withdraw: ");
                getTheMoney(&amount,0);
                if (amount) {
                    amount = withdraw(acc_id, amount);
                    if (amount == -1) {
                        printf("Cannot withdraw more than the balance\n\n");
                    } else {
                        printf("The new balance is: %.2lf\n\n", amount);
                    }
                }
            }
        } else if (value == 'I') {
            printf("Please enter interest rate: ");
            getTheMoney(&amount,0);
            if (amount>=0) {
                increaseInterestAll(amount);
            } else if (amount<0){
                printf("Invalid interest rate");
            }else{
                printf("Failed to read the interest rate\n");
            }
            printf("\n");
        } else if (value == 'P') {
            printALlAccounts();
        } else if (value == 'C') {
            if (accountIsValid) {
                closeAccount(acc_id);
                printf("Closed account number %d\n\n",acc_id);
            }
        } else if (value == 'E') {
            break;
        } else {
            printf("Invalid transaction type\n\n");
        }
    }
}