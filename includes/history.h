/**
**	\file	history.h
**	\author	Alexis Guérin
**	\date	29 janvier 2018
*/

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include "libag.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>

t_lstag	*add_history(t_lstag *history, char *line);
void	delete_history_file(char *path);
void	delete_history_list(t_lstag **history);
int		open_history(char *path);
t_lstag	*read_history(int fd);
void	write_history(int fd, t_lstag *history);

#endif
