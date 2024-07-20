#include "../includes/draw.h"
#include "../includes/games.h"
#include "../includes/player.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = NULL;
	game->map.body = NULL;
	game->map.assets.wall = NULL;
	game->map.assets.floor = NULL;
	game->map.assets.player = NULL;
	game->map.assets.goal = NULL;
	game->map.assets.collectible = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error!\nCollect:./so_long <mappath>"), 1);
	init_game(&game);
	game.map.body = read_map(argv[1]);
	if (!game.map.body)
		exit_error_game(&game);
	if (is_invalid_map(game.map.body))
		exit_error_game(&game);
	create_map(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
