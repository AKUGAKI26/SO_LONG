#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_game
{
	char	**map;
	size_t	map_height;
	size_t	map_widght;
}			t_game;

int			checknewline(char *str);
char		*get_next_line(int fd);
int			wall_check(t_game *game);
int			map_check(t_game *game, size_t i);
void		init_map_info(t_game *game);
void		take_map(t_game *game, char *map);
int			parsing(char *map, t_game *game);

void		check_flag(int *flag_player, int *flag_coin, int *flag_exit,
				char c);
void		free_map(char **map);
int			check_doubles(t_game *game);
size_t		slen(const char *c);
int			check_first_line(t_game *game, size_t y);
#endif