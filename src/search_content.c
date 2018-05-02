/*
**	\file	search_content.c
**	\author	Alexis Guérin
**	\date	23 février 2018
*/

#include "history.h"

/*
**	\brief	Recherche dans le contenu d'une commande
**
**	Recherche un motif dans le contenu d'une commande de l'historique
**	et renvoie la commande correspondante.
**
**	\param	history	- historique
**	\param	pattern	- motif à rechercher
**
**	\return	**commande** où le motif à été trouvé ou **NULL** sinon
*/

char	*search_history_content(t_lstag *history, const char *pattern)
{
	char	*command;

	command = NULL;
	if (history && pattern)
		while (!command && history)
		{
			if ((command = ft_strstr((const char*)history->content, pattern)))
				command = ft_strdup(command);
			history = history->next;
		}
	return (command);
}
