//
// Created by Amit-Sheer Cohen on 23/11/2020.
//

#ifndef myBank
#define myBank

#define ACCOUNT_NUM 50
#define ACCOUNT_PREFIX 900
int validateAccount(int acc_id);
int openNewAccount(double init_deposit);
double getBalance(int acc_id);
void addAmount(int acc_id, double deposit);
double withdraw(int acc_id, double withdrawalAmount);
void closeAccount(int acc_id);
void increaseInterestAll(double interest);
void printALlAccounts();

#endif //MYBANK_MYBANK_H
