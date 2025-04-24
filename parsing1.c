#include "so_long.h"

int	wall_check(t_game *game)
{
	size_t	i;

	i = 0;
	if (!check_first_line(game, 0) || !check_first_line(game, game->map_height
			- 1))
		return (0);
	while (game->map[i] && i < game->map_height - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_widght - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_check(t_game *game, size_t i)
{
	size_t	j;

	game->map_widght = slen(game->map[0]);
	while (i < game->map_height)
	{
		if (game->map_widght != slen(game->map[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_widght)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_map_info(t_game *game)
{
	game->map_height = 0;
	game->map_widght = 0;
	return ;
}

void	take_map(t_game *game, char *map)
{
	char	*line;
	int		i;
	int		fd;

	line = NULL;
	i = 0;
	game->map = malloc((game->map_height + 1) * sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	game->map[i] = 0;
}

int	parsing(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	init_map_info(game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_height++;
		free(line);
	}
	take_map(game, map);
	if (map_check(game, 1) == 0 || wall_check(game) == 0
		|| !check_doubles(game))
	{
		free_map(game->map);
		printf("map error\n");
		return (0);
	}
	return (1);
}
