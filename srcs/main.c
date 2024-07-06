#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53) // ESCキーのkeycode
		exit(0);
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game *game;
	char **temp;

	temp = (char **)malloc(sizeof(char *) * argc);
	temp = argv;

	game = (t_game *)malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
	// win = mlx_new_window(mlx, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE,
	// 		"My Game");
	game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
	set_hooks(game);
	mlx_loop(game->mlx);
	free(game);

	// draw_map(mlx, win);

	return (0);
}