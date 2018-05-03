#include "history.h"

int		cut_history(t_lstag *history, char *file)
{
	unsigned int	i;
	t_lstag			*list;

	if (!history)
		return (1);
	if (ag_lstcountelem(history) > 10000)
	{
		list = history;
		i = 0;
		while (list && ++i < 10000)
			list = list->next;
		if (list)
		{
			if (list->next)
				delete_history_list(&list->next);
			list->next = NULL;
			if (file)
			{
				delete_history_file_content(file);
				write_history(file, list);
			}
		}
	}
	return (0);
}
