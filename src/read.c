/**
**	\file	read.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
*/

#include "history.h"

/**
**	\brief	Lecture du fichier d'historique
**
**	La fonction lit le fichier d'historique grâce au descripteur de fichier
**	donné en paramètre et retourne une liste créée à partir de celui-ci.
**	Chaque maillon de la liste contient une ligne de commande.
**
**	\param	fd	- descripteur de fichier de l'historique
**
**	\return	**liste** contenant l'historique des commandes ou **NULL** en cas
**			d'erreur.
*/

t_lstag	*read_history(int fd)
{
	char	*line;
	t_lstag	*history;
	t_lstag	*node;

	history = NULL;
	node = NULL;
	line = NULL;
	if (fd >= 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl_fd(line, 2);
			if (!history)
				history = ft_lstagnew(line, ft_strlen(line) + 1);
			else
				node = ft_lstagnew(line, ft_strlen(line) + 1);
			if (node && history)
				ft_lstagadd(&history, node);
			if (line)
				ft_strdel(&line);
		}
	}
	return (history);
}
