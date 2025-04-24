#include "so_long.h"

void	check_flag(int *flag_player, int *flag_coin, int *flag_exit, char c)
{
	if (c == 'P')
		(*flag_player)++;
	if (c == 'C')
		(*flag_coin)++;
	if (c == 'E')
		(*flag_exit)++;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_doubles(t_game *game)
{
	int	i;
	int	y;
	int	flag_player;
	int	flag_exit;
	int	flag_coin;

	i = 0;
	flag_coin = 0;
	flag_player = 0;
	flag_exit = 0;
	while (game->map[i])
	{
		y = 0;
		while (game->map[i][y])
		{
			check_flag(&flag_player, &flag_coin, &flag_exit, game->map[i][y]);
			y++;
		}
		i++;
	}
	if (flag_player != 1 || flag_exit != 1 || flag_coin < 1)
		return (0);
	return (1);
}

size_t	slen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] && c[i] != '\n')
		i++;
	return (i);
}

int	check_first_line(t_game *game, size_t y)
{
	size_t	i;

	i = 0;
	while (game->map[y][i] && game->map[y][i] != '\n')
	{
		if (game->map[y][i] != '1')
			return (0);
		i++;
	}
	return (69);
}
