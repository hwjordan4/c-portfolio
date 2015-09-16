#ifndef _BANK_ACCOUNT_H
#define _BANK_ACCOUNT_H

typedef struct
{
  double balance;
  char* owner;
  char* num;
} bank_account;

/*************************************************************
 * preconditions:
 * acct_owner is not null & has at least 1 character
 * acct_num is not null * has at least 1 character * all characters are digits
 * init_balance >= 0
 *
 * NULL is returned if any precondition is not true
 * */

bank_account* create_account (char* acct_owner, double init_balance,
			      char* acct_num);

/***************************************************
 * preconditions: 
 * amount >= 0
 * acct is not NULL
 *
 * postcondition: account balance has been increased by amount
 * return 0 if precondition is not true, 1 ow
 * */

int deposit (bank_account* acct, double amount);

/********************************************************
 * preconditions: 
 * amount >= 0 & amount <= account balance
 * acct is not NULL
 *
 * postcondition: account balance has been decreased by amount
 * return 0 is precondition is not true - 1 ow
 * */
int withdraw (bank_account* acct, double amount);

/**********************************************************
 * precondition: acct is not null
 * postcondition: nothing is done is acct is null
 * */
void display_account (bank_account* acct);

/*******************************************************
 * nothing is done is acct is null
 * */
void delete_account (bank_account* acct);

#endif
