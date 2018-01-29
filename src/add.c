/**
**	\file	add.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
*/

#include "history.h"

static int	not_empty(char *line)
{
	while (*line)
	{
		if (!ft_isspace(line[0]))
			return (1);
		line++;
	}
	return (0);
}

static int	verif(t_lstag *node, t_lstag *history, char *line)
{
	if (((node && !history) ||
		(node && history && !ft_strequ(node->content, history->content))) &&
		line[0] && not_empty(line))
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

t_lstag		*add_history(t_lstag *history, char *line)
{
	t_lstag	*node;

	node = NULL;
	if (line)
	{
		if (!(node = ft_lstagnew(line, ft_strlen(line) + 1)))
			ft_putendl_fd("add_history: allocation error", 2);
		if (verif(node, history, line))
		{
			if (history)
				ft_lstagadd(&history, node);
			else
				history = node;
		}
	}
	return (history);
}
