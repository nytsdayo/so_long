#ifndef STRUCT_H
# define STRUCT_H
typedef struct s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct s_assets
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*goal;
	void		*collectible;
}				t_assets;
typedef struct s_map
{
	char		**body;
	int			width;
	int			height;
	t_assets	assets;
}				t_map;
typedef struct s_player
{
	t_point		point;
	int			cnt_collectibles;
	int			cnt_moves;
	void		*asset;
}				t_player;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	t_player	player;
}				t_game;
#endif
