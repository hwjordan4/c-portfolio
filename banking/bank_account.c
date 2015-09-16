#include "bank_account.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int is_all_digits (char* s)
{
  int result = 0;
  if (s != NULL)
  {
    int i = 0;
    while (i < strlen(s) && isdigit(s[i]))
	{
      		i++;
	}
    result = i == strlen(s);
  }
  return result;
}

char* create_copy (char* s)
{
  char* cpy = NULL;
  if (s != NULL)
  {
    cpy = malloc ((strlen(s) + 1) * sizeof (char));
    strcpy (cpy, s);
    cpy[strlen(s)] = 0;
  }
  return cpy;
}

bank_account* create_account (char* acct_owner, double init_balance, char* acct_num)
{
  	bank_account* acct = NULL;
		if(acct_owner != NULL && strlen(acct_owner) > 0)
			if(acct_num != NULL && strlen(acct_num) > 0 && is_all_digits(acct_num))
				if(init_balance >= 0)
				{
					acct = malloc (sizeof (bank_account));
					acct -> owner = create_copy (acct_owner);
					acct -> num = create_copy (acct_num);
					acct -> balance = init_balance; 
				}
	return acct;

}

int deposit (bank_account* acct, double amount)
{
	if(acct != NULL)
	{
		if(amount >= 0)
		{
			acct -> balance += amount;	
			printf("\n%s deposited $%.2f dollars\n",acct->owner, amount);
		}
		else
		{
			printf("Can't deposit that amount\n");
		}
	}
	else
	{
		return 0;
	}
}

int withdraw (bank_account* acct, double amount)
{
	if(acct != NULL)
		if(amount >=0 && amount <= (acct -> balance))
			{
				acct -> balance -= amount;
				printf("%s withdrew  $%.2f dollars.\n",acct->owner, amount);
			}
		else
		{
			printf("\nCannot withdraw %.2f. Not enough funds.\n", amount);
		}
	else
	{
		return 0;
	}
}

void display_account (bank_account* acct)
{
	printf("\nAccount Owner: \t%s\n", acct->owner);
	printf("Account Num: \t%s\n", acct->num);
	printf("Balance: \t$%.2f\n", acct->balance);
}

void delete_account (bank_account* acct)
{
	if(acct != NULL)
	{	
		acct -> balance = 0;
		free (acct -> owner);
		free (acct -> num);
		free (acct);
	}
}
