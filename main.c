#include <stdio.h>
#include "myBank.h"

void cleanBuffer(char value){
    while (getchar()!='\n'&&value!=EOF){}
}

int getTheMoney(double *amount){
    scanf(" %lf", amount);
    cleanBuffer(*amount);
    if(amount<0){
        printf(" input is amount, must be above 0\n");
        return 0;
    }
    return 1;
}

int main(){
    char value;
    double amount;
    int acc_id;
    do{
        amount = 0;
        acc_id = 0;
        value = 'c';
        printf("Transaction types: \n"
               "To open a new account: 'O'\n"
               "To see Balance: 'B'\n"
               "To deposit: 'D'\n"
               "To withdraw: 'W'\n"
               "To close an account: 'C'\n"
               "To interest: 'I'\n"
               "To print all open accounts and their balance: 'P'\n"
               "To close all accounts and program: 'E'\n"
               "Transaction type?: \n"
        );
        scanf(" %c",&value);
        cleanBuffer(value);
        if(value=='B'||value=='D'||value=='W'||value=='C'){
            printf("Account number?: \n");
            scanf(" %d", &acc_id);
            cleanBuffer(value);
            if(!validateAccount(acc_id)){
                printf("invalid account id\n");
                value = 'U';
            }
        }
        switch (value) {
            case 'O':
                printf("Initial deposit?: \n");
                if(getTheMoney(&amount)){
                    if(openNewAccount(amount)){
                        printf("No space available\n");
                    }
                }
                break;
            case 'B':
                amount = getBalance(acc_id);
                if(amount==-1){
                    printf("account is currently closed\n");
                }else{
                    printf("Account number: %d, Balance: %.2lf \n",acc_id, amount);
                }
                break;
            case 'D':
                printf("Amount?: \n");
                if(getTheMoney(&amount)){
                    deposit(acc_id, amount);
                }
                break;
            case 'W':
                printf("Amount?: \n");
                if(getTheMoney(&amount)){
                    amount =  withdraw(acc_id,amount);
                    if (amount == -1){
                        printf("Withdraw amount over reached, no withdrawal was preformed\n");
                    }else{
                        printf("Account number: %d, Balance: %lf \n",acc_id, withdraw(acc_id,amount));
                    }
                }
                break;
            case 'C':
                closeAccount(acc_id);
                break;
            case 'I':
                if(getTheMoney(&amount)){
                    increaseInterestAll(amount);
                }
                break;
            case 'P':
                printALlAccounts();
                break;
            default:
                break;
        }
    }while(value!='E');
}