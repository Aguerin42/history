/**
**	\file	add.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Ajout d'une ligne de commande à l'historique
*/

#include "history.h"

static int	not_empty(char *line)
{
	while (*line)
	{
		if (!ag_isspace(line[0]))
			return (1);
		line++;
	}
	return (0);
}

static int	verif(t_lstag *node, char *line)
{
	if (node && line[0] && not_empty(line))
		return (1);
	return (0);
}

/**
**	\brief	Ajout d'une ligne de commande à l'historique
**
**	La fonction ajoute la ligne de commande reçue en début d'historique.
**	Si cette ligne est vide ou identique à la précédente,
**	elle n'est pas ajoutée.
**
**	\param	history	- pointeur sur la tête de liste
**	\param	line	- ligne de commande
**
**	\return	tête de liste de **historique** modifié (ou non)
**			ou **NULL** en cas d'erreur
*/

t_lstag		*add_history_lst(t_lstag *history, char *line)
{
	t_lstag	*node;

	node = NULL;
	if (line)
	{
		if (!(node = ag_lstnew(line, ft_strlen(line) + 1)))
			ft_putendl_fd("add_history: allocation error", 2);
		if (verif(node, line))
		{
			if (history)
				ag_lstadd(&history, node);
			else
				history = node;
		}
		else if (node)
			delete_history_list(&node);
	}
	return (history);
}

/**
**	\brief	Ajout d'une commande dans le fichier et dans la liste
**
**	\param	history	- pointeur sur la tête de liste
**	\param	path	- chemin d'accès au fichier
**	\param	line	- ligne de commande
**
**	\return	tête de liste de **historique** modifié (ou non)
**			ou **NULL** en cas d'erreur
*/

t_lstag		*add_history(t_lstag *history, char *path, char *line)
{
	if (line && (!history || !ft_strequ(history->content, line)))
	{
		history = add_history_lst(history, line);
		write_history(path, history);
	}
	return (history);
}
