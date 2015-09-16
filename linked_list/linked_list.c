#include "linked_list.h"
#include <stdlib.h>

/* NOTE:  This implementation contains some errors.  Double check your work. */

/******************************************
return empty list
*/
list create_list()
{
  list l;
  l.front = NULL;
  l.rear = NULL;
  l.size = 0;
  return l;
}

/*******************************************
return whether list is empty
*/
int is_empty (list* l)
{
  return l -> front == NULL;
}

/*****************************************
return # of elements in list
*/
int size (list* l)
{
  return l -> size;
}

/*******************************************
postcondition: list & all nodes in list have
been deleted - if l is NULL, nothing is
done
*/
void delete (list* l)
{
  if (l != NULL)
  {
    node* temp = l -> front;
    while (temp != NULL)
    {
      node* temp1 = temp -> next;
      free (temp);
      temp = temp1;
    }
    free (l);
  }
}

/********************************************
precondition: l is not NULL
postcondition: item has been inserted at the
beginning of l
return whether insertion was performed
*/
int prepend (list* l, void* item)
{
  int result = 0;
  if (l != NULL)
  {
    node* temp = malloc (sizeof (node));
    node* pTemp = malloc (sizeof (node));
    if (temp != NULL && pTemp != NULL)
    {
      result = 1;
      temp -> item = item;
      if (l -> front == NULL)
      {
	temp -> next = NULL;
	l -> front = temp;
	l -> rear = temp;
      }
      else
      {
	temp -> next = l -> front;
	l -> front = temp;
        pTemp -> previous = l -> rear;
        l -> rear = pTemp;
      }
      l -> size++;
    }
  }
  return result;
}

/********************************************
precondition: l is not NULL
postcondition: item has been inserted at the
end of l
return whether insertion was performed
*/
int append (list* l, void* item)
{
  int result = 0;
  if (l != NULL)
  {
    node* temp = malloc (sizeof (node));
    node* pTemp = malloc (sizeof (node));
    if (temp != NULL && pTemp != NULL)
    {
      result = 1;
      temp -> item = item;
      temp -> next = NULL;
      pTemp -> previous = NULL;
      if (l -> front == NULL)
      {
	l -> front = temp;
	l -> rear = temp;
      }
      else 
      {
	l -> rear -> previous = pTemp;
	l -> rear = pTemp;
      }
      l -> size++;
    }
  }
  return result;
}

/********************************************
precondition: l is not NULL & 1 <= location <= size of list + 1
postcondition: item has been inserted at location position
end of l
return whether insertion was performed
*/
int insert_in_list (list* l, int location, void* item)
{
  int result;
  if (l == NULL)
    result = 0;
  else if (location < 1 || location > size(l) + 1)
    result = 0;
  else if (l -> size == 0)
  {
    l -> front = malloc (sizeof(node));
    if (l -> front == NULL)
      result = 0;
    else
    {
      result = 1;
      l -> front -> item = item;
      l -> rear = l -> front;
      l -> front -> next = NULL;
      l -> size++;
    }
  }
  else
  {
    node* new_node = malloc (sizeof(node));
    if (new_node == NULL)
      result = 0;
    else
    {
      result = 1;
      new_node -> item = item;
      int i;
      int j;
      node* temp = l -> front;
      node* pTemp = l -> rear;
      if(size(l)/2 > location)
      	for (i = 1; i < location - 1; i++)
		temp = temp -> next;
      else
	for (j = size(l); j > location; j--)
		pTemp = pTemp -> previous;	
      new_node -> next = temp -> next;
      new_node -> previous = pTemp -> previous;
      temp -> next = new_node;
      pTemp -> previous = new_node;
      if (location == l -> size + 1)
	l -> rear = new_node;
      l -> size++;
    }
  }
  return result;
}

/********************************************
precondition: l is not NULL & 1 <= location <= size of list
postcondition: item has been deleted from l
return whether deletion was performed
*/
int delete_from_list (list* l, int location)
{
  int result;
  if (l == NULL)
    result = 0;
  else if (location < 1 || location > size (l))
    result = 0;
  else if (location == 1)
  {
    node* temp = l -> front;
    l -> front = l -> front -> next;
    if (size (l) == 1)
      l -> rear = l -> rear -> previous;
    free (temp);
    l -> size--;
    result = 1;
  }
  else
  {
    node* temp = l -> front;
    node* temp1 = NULL;
    node* pTemp = l -> rear;
    node* pTemp1 = NULL;
    int i;
    int j;
	if((size(l)/2) >= location)
	{
    		for (i = 1; i < location; i++)
     		{
	 	temp1 = temp -> next;
		}
    	temp -> next = temp1 -> next;
    	free (temp1);
	}
	else
	{
		for (j = 1; j > location; j++)
		{
		pTemp1 = pTemp -> previous; 
		}
	
    	pTemp -> previous = pTemp1 -> previous;
    	free (pTemp1);
	}
    	
	if (location == l -> size)
      		l -> rear = temp;
    
	l -> size--;
    	result = 1;
  }
  return result;
}


/********************************************
precondition: l is not NULL & 1 <= location <= size of list
return element at position location in l - NULL is returned
if l is NULL or location is not valid
*/

// getters should return the item in the node

node* get (list* l, int location)
{
  void* item = NULL;
  if (1 <= location && location <= size(l))
  {
    
    node* temp = l->front;
    node* pTemp = l->rear;
    int i;
    int j;
	if((size(l)/2) >= location)
	{
    		for (i = 1; i < location; i++)
     		{
	 	temp = temp -> next;
		}
	temp -> item = item;
	}
	else
	{
		for (j = 1; j > location; j++)
		{
		pTemp = pTemp -> previous; 
		}
	pTemp -> item = item;
	}
	return item;	
  }
  else
	return 0;	
}

/********************************************
precondition: l is not NULL & 1 <= location <= size of list
return whether item was put in l
*/

// Setters are void functions that do not return anything

void set (list* l, int location, void* item)
{
  if (1 <= location && location <= size(l))
  {
    node* temp = l->front;
    node* pTemp = l->rear;
    int i;
    int j;
	if((size(l)/2) >= location)
	{
    		for (i = 1; i < location; i++)
     		{
	 	temp = temp -> next;
		}
	temp -> item = item;
	}
	else
	{
		for (j = 1; j > location; j++)
		{
		pTemp = pTemp -> previous; 
		}
	pTemp -> item = item;
	}	
  }
  else
  {
   exit(0);
  }
}

