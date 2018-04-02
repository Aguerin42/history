/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:33:00 by aguerin           #+#    #+#             */
/*   Updated: 2018/04/02 10:33:20 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	delete.c
**	\author	Alexis Guérin
**	\date	30 janvier 2018
**
**	\brief	Suppression d'historique
*/

#include "history.h"

/*
**	\brief	Suppression de l'historique dans le fichier
**
**	La fonction supprime le contenu du fichier, mais sans supprimer celui-ci.
**
**	\param	path	- chemin d'accès au fichier
*/

void		delete_history_file(char *path)
{
	int	fd;

	if (path)
		if ((fd = open(path, O_TRUNC)) != -1)
			close(fd);
}

static void	del(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
		ft_memdel(&content);
}

/*
**	\brief	Suppression de l'historique dans la liste
**
**	La fonction supprime la liste et en libère la mémoire.
**
**	\param	history	- pointeur sur la tête de liste à supprimer
*/

void		delete_history_list(t_lstag **history)
{
	if (history)
		ag_lstdel(history, del);
}
