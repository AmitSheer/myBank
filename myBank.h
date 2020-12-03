#ifndef myBank
#define myBank
#include <stdio.h>
#include <math.h>

#define ACCOUNT_NUM 50
#define ACCOUNT_PREFIX 900
int validateAccount(int acc_id);
int openNewAccount(double init_deposit);
float getBalance(int acc_id);
void deposit(int acc_id, float deposit);
float withdraw(int acc_id, float withdrawalAmount);
void closeAccount(int acc_id);
void increaseInterestAll(double interest);
void printALlAccounts();
#endif
