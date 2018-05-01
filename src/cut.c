#include "history.h"

int	cut_history(t_lstag **history, char *file)
{
	unsigned int	i;
	t_lstag			*list;
	t_lstag			*head;

	if (history)
	{
		if ((i = ag_lstcountelem(*history)) > 10)
		{
			list = *history;
			head = list;
			i = 0;
			while (list && i++ < 10)
				list = list->next;
			if (list)
			{
				*history = head;
				head = list;
				head->next = NULL;
				delete_history_list(&list);
				if (file)
				{
					delete_history_file_content(file);
					write_history(file, *history);
				}
			}
		}
		return (0);
	}
	return (1);
}
