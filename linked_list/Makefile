linked_list.o: linked_list.c linked_list.h
	gcc -g -c linked_list.c

test_list.o: test_list.c linked_list.h
	gcc -g -c test_list.c

test_list: test_list.o linked_list.o
	gcc -g -o test_list test_list.c linked_list.c
