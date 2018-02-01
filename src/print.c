/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:13:40 by aguerin           #+#    #+#             */
/*   Updated: 2018/02/01 10:22:05 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
**	\file	print.c
**	\author	Alexis Guérin
**	\date	31 janvier 2018
**
**	\brief	Affichage du contenu de l'historique
*/

#include "history.h"

static void		print(t_lstag *history, int nb, int len)
{
	int	i;

	i = len;
	while (history && i--)
	{
		ft_putxchar(' ', 5 - ft_nbrlen(len - --nb));
		ft_putnbrs(len - nb);
		ft_putendl(history->content);
		history = history->prev;
	}
}

static t_lstag	*find_node(t_lstag *history, int nb)
{
	while (--nb && history)
		history = history->next;
	return (history);
}

/**
**	\brief	Affichage du contenu de l'historique
**
**	La fonction affiche les préédentes commandes, précédées d'un numéro de
**	ligne.
**
**	\param	history	- historique
**	\param	nb		- nombre de ligne à afficher. Si `nb` est négatif, toutes
**					les lignes sont affichées.
*/

void			print_history(t_lstag *history, int nb)
{
	int				len;

	if (history)
	{
		len = ft_lstagcountelem(history);
		if (nb >= 0 && nb < len)
			history = find_node(history, nb);
		else
		{
			history = ft_lstagtail(history);
			nb = len;
		}
		print(history, nb, len);
	}
}
