#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	if (ft_strlen(argv[1]) < 4 || ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4,
			".ber") != 0 || argv[1][0] == '.')
	{
		printf("Error: Invalid file extension\n");
		return (1);
	}
	if (parsing(argv[1], &game) == 0)
		printf("parsing Error\n");
}
