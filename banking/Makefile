bank_account.o: bank_account.c bank_account.h
	gcc -g -c bank_account.c
test_bank_account.o: test_bank_account.c bank_account.h
	gcc -g -c test_bank_account.c
test_bank_account.exe: bank_account.o test_bank_account.o
	gcc -o test_bank_account.exe bank_account.o test_bank_account.o


