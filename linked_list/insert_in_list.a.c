int insert_in_list(list* a, int location, void* item)
{
	int result;

	if(a == NULL)
		result = 0;

	else if(location < 1 || location > size(*a) + 1)
		result = 0;

	else if(a->size == 0 || location == 1)
	{
		if(prepend(a, item))
			result = 1;
		else
			result = 0;
	}
	else if(location == size(*a) + 1)
	{
		if(append(a, item)
			result = 1;
		else
			result = 0;
	}
	else 
	{
		node* new_node = malloc(sizeof(node));
		if(new_node == NULL)
			result = 0;
		else
		{
			result = 1;
			new_node->item = item;
			int i;
			node* temp = a->front;
			for(i = 1; i < location -1; i++)
			{
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
			a->size++;
		}
	}
	return result;
}
