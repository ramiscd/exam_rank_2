t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *head;
	int tmp;

	if (!lst)
		return (NULL);

	head = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}