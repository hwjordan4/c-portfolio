int insert_in_list(list* a, iint location, void* item)
{
	int result = 0;
	if(a != NULL)
	{
		if(location >= 1)
		{
			if(location < size(*a) + 2)
			{
				if(a->size == 0 || location == 1)
				{
					if(prepend(a, item))
						result = 1;
				}
				else if(location == size(*a) + 1)
				{
					if(append(a, item))
						result = 1;
				}
				else
				{
					node* new_node = malloc(sizeof(node));
					if(new_node != NULL)
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
			}
		}
	}
	return result;
}
