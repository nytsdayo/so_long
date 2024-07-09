#include "../includes/so_long.h"

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
	game->map = (t_map *)malloc(sizeof(t_map));
	game->map->map = read_map(open(argv[1], O_RDONLY));
	if (!game->map)
		return (ft_printf("Error\n"), 1);
	game->map->width = count_columns(game->map->map);
	game->map->height = count_lines(game->map->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	draw_map(game);
	set_hooks(game);
	mlx_loop(game->mlx);
	free(game);
	return (0);
}
