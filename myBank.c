#include "myBank.h"
#include <stdio.h>
#include <math.h>

//Max number of accounts allowed
#define ACCOUNT_NUM 50
//Accounts Prefix
#define ACCOUNT_PREFIX 900

//[open/closed][balance]
double accounts[ACCOUNT_NUM][2] = {0};

//validates account id
int validateAccount(int acc_id) {
    if (acc_id > ACCOUNT_PREFIX && acc_id <= (ACCOUNT_PREFIX + ACCOUNT_NUM)) {
        return 1;
    } else if (acc_id<0||acc_id > (ACCOUNT_PREFIX + ACCOUNT_NUM)){
        return -1;
    }else{
        return 0;
    }
}

int openNewAccount(double init_deposit) {
    for (int j = 0; j < ACCOUNT_NUM; ++j) {
        if (accounts[j][0] == 0) {
            //marks account as open
            accounts[j][0] = 1;
            //adds the current balance of account
            accounts[j][1] = floor(init_deposit * 100) / 100;
            return 900 + j + 1;
        }
    }
    return 1;
}

float getBalance(int acc_id) {
    if (accounts[acc_id - ACCOUNT_PREFIX - 1][0] == 1) {
        return accounts[acc_id - ACCOUNT_PREFIX - 1][1];
    }
    return -1;
}

double deposit(int acc_id, float deposit) {
    if (accounts[acc_id - ACCOUNT_PREFIX - 1][0] == 1 && deposit >= 0) {
        accounts[acc_id - ACCOUNT_PREFIX - 1][1] = accounts[acc_id - ACCOUNT_PREFIX - 1][1] + deposit;
        return accounts[acc_id - ACCOUNT_PREFIX - 1][1];
    }
    return 0;
}

float withdraw(int acc_id, float withdrawalAmount) {
    if (accounts[acc_id - ACCOUNT_PREFIX - 1][0] == 1 &&
        (accounts[acc_id - ACCOUNT_PREFIX - 1][1] - withdrawalAmount) >= 0) {
        accounts[acc_id - ACCOUNT_PREFIX - 1][1] = accounts[acc_id - ACCOUNT_PREFIX - 1][1] - withdrawalAmount;
        return (accounts[acc_id - ACCOUNT_PREFIX - 1][1]);
    }
    return -1;
}

void closeAccount(int acc_id) {
    if (accounts[acc_id - ACCOUNT_PREFIX - 1][0]) {
        accounts[acc_id - ACCOUNT_PREFIX - 1][0] = 0;
    }
}

void increaseInterestAll(double interest) {
    for (int i = 0; i < ACCOUNT_NUM; ++i) {
        if (accounts[i][0]) {
            accounts[i][1] = accounts[i][1] + (accounts[i][1] * interest / 100);
            //printf("increaseInterestAll %.2lf\n", accounts[i][1]);
        }
    }
}

void printALlAccounts() {
    for (int i = 0; i < ACCOUNT_NUM; ++i) {
        if (accounts[i][0]) {
            printf("The balance of account number %d is: %.2lf\n", i + ACCOUNT_PREFIX + 1, accounts[i][1]);
        }
    }
    printf("\n");
}

int accountIsOpen(int acc_id){
    return accounts[acc_id-ACCOUNT_PREFIX-1][0];
}