/**
**	\file	delete.c
**	\author	Alexis Guérin
**	\date	30 janvier 2018
**
**	\brief	Suppression du contenu de l'historique
*/

#include "history.h"

/**
**	\brief	Suppression du contenu de l'historique
**
**	La fonction supprime le contenu du fichier, mais sans supprimer celui-ci.
**
**	\param	path	- chemin d'accès au fichier
*/

void	delete_history(char *path)
{
	int	fd;

	if (path)
		if ((fd = open(path, O_TRUNC)) != -1)
			close(fd);
}
