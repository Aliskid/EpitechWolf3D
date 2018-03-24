/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/celebi_a/MUL_2014_wolf3d
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Thu Dec 18 23:06:32 2014 Alison Celebi
** Last update Sun May 31 23:41:23 2015 Alison Celebi
*/

#include <math.h>
#include "my.h"
#include "mlx.h"

int		pixel_put_to_image(t_expose *expose, int x, int y, unsigned int color)
{
  unsigned int	col;

  if (x < 0 || x >= WIN_X ||
      y < 0 || y >= WIN_Y)
    return (-1);
  x = x * (expose->draw->bpp / 8);
  y = (y * expose->draw->sizeline);
  col = mlx_get_color_value(expose->pointer->mlx_ptr, color);
  expose->draw->mlx_img_data[y + x] = col >> 0;
  expose->draw->mlx_img_data[y + x + 1] = col >> 8;
  expose->draw->mlx_img_data[y + x + 2] = col >> 16;
  return (0);
}
