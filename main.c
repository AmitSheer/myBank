#include <stdio.h>
#include "myBank.h"

int main(){
    char value='a';
    double amount = 0;
    int acc_id = 0;
    do{
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
        switch (value) {
            case 'O':
                printf("Initial deposit?: \n");
                scanf("%lf", &amount);
                printf("account id: %d\n",openNewAccount(amount));
                break;
            case 'B':
                printf("Account number?: \n");
                scanf("%d", &acc_id);
                if(validateAccount(acc_id)){
                    printf("Account number: %d, Balance: %lf \n",acc_id, getBalance(acc_id));
                }else{
                    printf("invalid account id");
                }
                break;
            case 'D':
                printf("Account number?: \n");
                scanf("%d", &acc_id);
                if(validateAccount(acc_id)){
                    printf("Account number: %d, Balance: %lf \n",acc_id, getBalance(acc_id));
                }else{
                    printf("invalid account id");
                }
                break;
            case 'E':
                printf("E");
                break;
            default:
                while (value!='B'&&value!='O'&&value!='I'&&value!='D'&&value!='E'&&value!='W'&&value!='C'&&value!='P')
                {
                    getchar();
                    scanf(" %c",&value);
                }
                break;
        }
    }while(value!='E');
}