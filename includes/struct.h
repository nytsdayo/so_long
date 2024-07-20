#ifndef STRUCT_H
# define STRUCT_H
typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_check
{
	int			cnt_player;
	int			cnt_goal;
	int			cnt_floor;
}				t_check;

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
	t_position	point;
	int			cnt_collectibles;
	int			cnt_moves;
	void		*asset;
}				t_player;
typedef struct s_goal
{
	t_position	point;
	void		*asset;
}				t_goal;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	t_player	player;
	t_goal		goal;
}				t_game;
#endif
