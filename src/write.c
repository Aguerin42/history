/**
**	\file	write.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Écriture de l'historique dans le fichier
*/

#include "history.h"

/**
**	\brief	Écriture de l'historique dans le fichier
**
**	La fonction parcourt la liste contenant l'historique et écrit celui-ci
**	dans le fichier. La liste est parcourue du plus ancien maillon au plus 
**	récent (de `prev` en `prev`).
**
**	\param	fd		- descripteur de fichier du fichier où écrire
**	\param	history	- maillon à partir duquel ajouter lire l'historique
*/

void	write_history(int fd, t_lstag *history)
{
	while (history)
	{
		ft_putendl_fd(history->content, fd);
		history = history->prev;
	}
}
