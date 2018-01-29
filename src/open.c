/**
**	\file	open.c
**	\author	Alexis Guérin
**	\date	29 janvier 2018
**
**	\brief	Ouverture ou création du fichier d'historique
*/

#include "history.h"

static int	create_file(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDWR | O_CREAT)) == -1)
		ft_putendl_fd("open_history: file creation error", 2);
	return (fd);
}

static int	open_file(char *path, int perm)
{
	int	flag;
	int	fd;

	if (perm == 10)
		flag = O_RDONLY;
	else if (perm == 100)
		flag = O_WRONLY;
	else
		flag = O_RDWR;
	if ((fd = open(path, flag)) == -1)
		ft_putendl_fd("open_history: incorrect file", 2);
	return (fd);
}

/**
**	\brief	Ouverture du fichier d'historique
**
**	\param	path	- chemin d'accès au fichier
**
**	\return	**descripteur de fichier** en cas de succès d'ouverture ou
**			ou de création du fichier, ou **-1** sinon.
*/

int			open_history(char *path)
{
	int	fd;
	int	perm;

	fd = -1;
	if (path)
	{
		perm = 0;
		if (!access(path, F_OK))
		{
			if (!access(path, R_OK))
				perm += 10;
			if (!access(path, W_OK))
				perm += 100;
			if (perm)
				fd = open_file(path, perm);
			else
				ft_putendl_fd("open_history: unable to open the file", 2);
		}
		else
			fd = create_file(path);
	}
	else
		ft_putendl_fd("open_history: the path is empty", 2);
	return (fd);
}
