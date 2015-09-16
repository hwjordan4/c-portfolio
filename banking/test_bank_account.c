#include "bank_account.h"
#include <stdlib.h>
#include <stdio.h>

int main ()
{
  	bank_account* acct1 = create_account ("George Harrison", 100, "0001");
  	if (acct1 == NULL)
    		printf ("invalid account");
  	else
  	{
		display_account (acct1);
		deposit(acct1, 500);
		withdraw(acct1, 66);
    		display_account (acct1);
		printf("\n");
    		delete_account (acct1);
  	}
	//bad owner name
  	bank_account* acct2 = create_account ("", 100, "0002");
	if(acct2 != NULL)
	{
		display_account(acct2);
	}
	else
	{
		printf("Invalid account\n");
		delete_account (acct2);
	}
  	//bad balance
  	bank_account* acct3 = create_account ("Roger Harrison", -100, "0003");	
	if(acct3 != NULL)
	{
		display_account(acct3);
	}
	else
	{
		printf("Invalid account\n");
		delete_account (acct3);
	}
	//bad acct num
  	bank_account* acct4 = create_account ("Mike Harrison", 1000, "");	
	if(acct3 != NULL)
	{
		display_account(acct4);
	}
	else
	{
		printf("Invalid account\n");
		delete_account (acct4);
	}
	//bad withdraw and bad deposit
	bank_account* acct5 = create_account ("John Lennon", 210, "0005");
	if(acct5 == NULL)
		printf("invalid account");
	else
	{
		display_account (acct5);
		withdraw(acct5, 212);
		deposit(acct5, -20);
		display_account (acct5);	
		printf("\n");
		delete_account (acct5);
	}
	return 0;
}

