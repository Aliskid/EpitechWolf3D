/*
** my.h for my.h in /home/celebi_a/MUL_2014_wolf3d
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Thu Dec 18 23:56:36 2014 Alison Celebi
** Last update Fri May 22 13:44:41 2015 Alison Celebi
*/

#ifndef _MY_H_
# define _MY_H_

# define WIN_X	(500.0)
# define WIN_Y	(500.0)

# define LEFT	(65361)
# define RIGHT	(65363)
# define UP	(65362)
# define DOWN	(65364)
# define ESCAPE	(65307)

typedef struct	s_pointer
{
  void		*mlx_ptr;
  void		*win_ptr;
}		t_pointer;

typedef struct	s_draw
{
  int		bpp;
  int		endian;
  int		sizeline;
  char		*mlx_img_data;
  void		*mlx_img;
}		t_draw;

typedef struct	s_player
{
  double	x;
  double	y;
  double	angle;
}		t_player;

typedef struct	s_expose
{
  t_player	*player;
  t_draw	*draw;
  t_pointer	*pointer;
}		t_expose;

int	pixel_put_to_image(t_expose *expose, int x, int y, unsigned int color);
int	gere_expose(t_expose *expose);
int	key_hook(int key, t_expose *expose);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_puterror(char *str);
int	main(int ac, char **av, char **env);
int	verif_wall(int map[10][10], int x, int y);
double	get_distance(t_expose *expose, double vx, double vy);
int	get_height(t_expose *expose, int x);
int	affichage(t_expose *expose, int x, int height);
int	wolf(t_expose *expose);

#endif /* !MY_H_ */
