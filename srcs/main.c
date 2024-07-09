#include "../includes/draw.h"
#include "../includes/games.h"
#include "../includes/player.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	ft_printf("sample\n");
	while (map[i])
		i++;
	return (i);
}

int	count_columns(char **map)
{
	int	i;

	i = 0;
	ft_printf("sample\n");
	while (map[0][i])
	{
		printf("sample\n");
		i++;
	}
	ft_printf("columns: %d\n", i);
	return (i - 1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (perror("Error"), 1);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Error\n"), 1);
	create_map(game, argv[1]);
	set_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}
