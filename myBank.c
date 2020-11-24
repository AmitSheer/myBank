#include <stdio.h>
#include <math.h>

#include "myBank.h"

#define ACCOUNT_NUM 50
#define ACCOUNT_PREFIX 900

//[open/closed][deposit]
double accounts [ACCOUNT_NUM][2]= {0};

int validateAccount(int acc_id){
    if(acc_id>ACCOUNT_PREFIX&&acc_id<=(ACCOUNT_PREFIX+ACCOUNT_NUM)){
        return 1;
    }else{
        return 0;
    }
}

int openNewAccount(double init_deposit){
    for (int j = 0; j < ACCOUNT_NUM; ++j) {
        if (accounts[j][0]==0){
            accounts[j][0]=1;
            init_deposit = init_deposit*100;
            init_deposit = floor(init_deposit);
            accounts[j][1]=init_deposit/100;
            return 900+j+1;

        }
    }
    return -1;
}

double getBalance(int acc_id){
    if(accounts[acc_id-900-1][0]==1) {
        return accounts[acc_id-900-1][1];
    }
    return -1;
}
void addAmount(int acc_id, double deposit){
    printf("addAmount %d, %.4lf\n", acc_id, deposit);

}
double withdraw(int acc_id, double withdrawalAmount){
    printf("getAmount %d, %.4lf\n", acc_id, withdrawalAmount);

    return 0.0;
}
void closeAccount(int acc_id){
    printf("close %d\n", acc_id);

}
void increaseInterestAll(double interest){
    printf("increaseInterestAll %.4lf\n", interest);

}
void printALlAccounts(){
    printf("printALlAccounts\n");

}