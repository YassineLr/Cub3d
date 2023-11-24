/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:20:23 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/24 01:29:37 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <mlx.h>

# define WIN_NAME "Cub3d"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define PI 3.1415
# define TILE_SIZE 64
# define A_KEY 0
# define D_KEY 2
# define W_KEY 13
# define S_KEY 1
# define KEYDOWN 125
# define KEYUP 126
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 53
# define FOV 1.0471975512
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS WIN_WIDTH

int F_COUNTER;
int C_COUNTER;
int NO_COUNTER;
int WE_COUNTER;
int SO_COUNTER;
int EA_COUNTER;

typedef struct s_wall_cordinate
{
	float	top;
	float	bottom;
}			t_wall_cordinate;

typedef struct s_ray
{
	float				ray_angle;
	int					offset_x;
	int					offset_y;
	float				wall_hit_x;
	float				wall_hit_y;
	float				distance;
	float				y_step_h;
	float				x_step_h;
	float				y_step_v;
	float				x_step_v;
	float				distance_to_wall;
	float				y_intercept_h;
	float				x_intercept_h;
	float				y_intercept_v;
	float				x_intercept_v;
	float				distance_pojection_plane;
	float				wall_strip_height;
	bool				player_hit_horizontal_wall;
	bool				player_hit_vertical_wall;
	t_wall_cordinate	wall_cordinate;
}			t_ray;

typedef struct s_palyer
{
	float	x;
	float	y;
	float	col_x;
	float	col_y;
	float	dx;
	float	dy;
	float	ang;
	int		walkdirection;
	int		turndirection;
	int		straff_direction;
	float	rotationdirection;
	float	movespeed;
	float	rotationspeed;
	int		to_do;
	t_ray	*rays;
}			t_player;

typedef struct s_get_color
{
	size_t	start;
	char	*temp[3];
	size_t	len;
	int		ret;
}			t_get_color;

typedef struct s_color
{
	int	floor;
	int	celling;
}			t_color;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_texture
{
	int		height;
	int		width;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	t_image	image[4];
}			t_texture;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

typedef struct s_data
{
	char		*path;
	char		**map;
	int			map_h;
	int			map_w;
	t_texture	textures;
	t_color		colors;
	t_player	player;
	t_mlx		*mlx;
}			t_data;

typedef struct s_coordinate
{
	int	x;
	int	y;
}			t_cordinate;

void			init_game(t_data *data, int ac, char **av);
void			init_textures(t_data *data);
t_image			init_texture(t_data *data, int flag);
void			ft_exit(t_data *data, const char *str, int code);
void			free_ptr(char **str);
void			get_data(t_data *data);
void			free_ptr(char **str);
void			free_mat(char ***mat);
void			close_fds(int min, int max);
int				get_map(t_data *data, char *line);
void			get_format(char ***map, size_t height, size_t width);
void			get_player_info(t_data *data);
void			check_map(t_data *data);

t_mlx			*mlx_initializer(void);
int				render2dmap(t_data *data);
int				keypressed(int keycode, t_data *data);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void			playermovement(t_data *data);
void			initplayer(t_data *data);
unsigned int	my_mlx_pixel_get(t_image *img, int x, int y);
int				keyreleased(int keycode, t_data *data);
void			cast_all_rays(t_data *data);
float			angles_normalizer(float angle);
void			cast_ray(t_ray *ray, t_data *data);
double			distance_between_points(double x1, double y1, \
										double x2, double y2);
void			distance_to_wall(t_ray *ray, t_data *data);
void			rays_parameters(t_data *data);
void			calculate_horizontal_intercept(t_ray *ray, t_data *data);
void			check_horizontal_intersections(t_ray *ray, t_data *data);
void			calculate_vertical_intercept(t_ray *ray, t_data *data);
void			check_vertical_intersections(t_ray *ray, t_data *data);
int				has_wall_at(t_data *data, float x, float y);
void			distance_to_wall(t_ray *ray, t_data *data);
int				choose_texture(t_ray *ray, float ra);
int				get_texture_pixel_color(int x, int y, t_data *data, int n);
void 			check_nbr(t_get_color *c, int *i);

#endif
