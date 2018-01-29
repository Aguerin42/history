#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include "libag.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>

int		open_history(char *path);
t_lstag	*read_history(int fd);

#endif
