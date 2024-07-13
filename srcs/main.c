#include "../includes/draw.h"
#include "../includes/games.h"
#include "../includes/player.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (perror("Error"), 1);
	create_map(&game, argv[1]);
	set_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
