/*
** main.c for main in /home/celebi_a/MUL_2014_wolf3d
**
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
**
** Started on  Tue Dec  9 17:30:59 2014 Alison Celebi
** Last update Fri May 29 16:43:31 2015 Alison Celebi
*/

#include <stdlib.h>
#include <unistd.h>
#include <X11/X.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "mlx.h"

int		main(int ac __attribute__((unused)), char **av __attribute__((unused)),
char **env)
{
  t_expose	expose;
  t_pointer	pointer;
  t_player	player;
  t_draw	draw;

  if (env == NULL || env[0] == NULL)
    return (my_puterror("[ERROR] : there is no env\n"));
  pointer.mlx_ptr = mlx_init();
  pointer.win_ptr = mlx_new_window(pointer.mlx_ptr, WIN_X, WIN_Y, "window");
  draw.mlx_img = mlx_new_image(pointer.mlx_ptr, WIN_X, WIN_Y);
  draw.mlx_img_data = mlx_get_data_addr(draw.mlx_img, &draw.bpp,
                                        &draw.sizeline, &draw.endian);
  player.x = 3;
  player.y = 3;
  player.angle = 0;
  expose.draw = &draw;
  expose.player = &player;
  expose.pointer = &pointer;
  wolf(&expose);
  mlx_hook(pointer.win_ptr, KeyPress, KeyPressMask, &key_hook, &expose);
  mlx_expose_hook(pointer.win_ptr, &gere_expose, &expose);
  mlx_loop(pointer.mlx_ptr);
  return (0);
}
