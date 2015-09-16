#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct list_node
{
  void* item;
  struct list_node* next;
  struct list_node* previous;
} node;

typedef struct list_struct
{
  node* front;
  node* rear;
  int size;
} list;

/******************************************
return empty list
*/
list create_list();

/*******************************************
return whether list is empty
*/
int is_empty (list* l);

/*****************************************
return # of elements in list
*/
int size (list* l);

/*******************************************
postcondition: list & all nodes in list have
been deleted - if l is NULL, nothing is
done
*/
void delete (list* l);

/********************************************
precondition: l is not NULL
postcondition: item has been inserted at the
beginning of l
return whether insertion was performed
*/
int prepend (list* l, void* item);

/********************************************
precondition: l is not NULL
postcondition: item has been inserted at the
end of l
return whether insertion was performed
*/
int append (list* l, void* item);

/********************************************
precondition: l is not NULL & 1 <= location <= size of list + 1
postcondition: item has been inserted at location position
end of l
return whether insertion was performed
*/
int insert_in_list (list* l, int location, void* item);

/********************************************
precondition: l is not NULL & 1 <= location <= size of list
postcondition: item has been deleted from l
return whether deletion was performed
*/
int delete_from_list (list* l, int location);

/********************************************
precondition: l is not NULL & 1 <= location <= size of list
return element at position location in l - NULL is returned
if l is NULL or location is not valid
*/
node* get (list* l, int location);

/********************************************
precondition: l is not NULL & 1 <= location <= size of list
return whether item was put in l
*/
void set (list* l, int location, void* item);

#endif
