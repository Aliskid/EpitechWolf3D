/*
** get_calculs.c for calculs in /home/celebi_a/MUL_2014_wolf3d
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Sun Dec 21 19:35:39 2014 Alison Celebi
** Last update Fri Jun  5 11:24:10 2015 Alison Celebi
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "mlx.h"

int		verif_wall(int map[10][10], int x, int y)
{
  if (y < 1 || x < 1 || y >= 7 || x >=7)
    return (1);
  if (map[y][x] == 1)
    return (1);
  return (0);
}

double		get_distance(t_expose *expose, double vx, double vy)
{
  int		map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };
  double	dist;
  double	x;
  double	y;

  dist = 0.01;
  x = expose->player->x + dist * vx;
  y = expose->player->y + dist * vy;
  while (verif_wall(map, x, y) != 1)
    {
      dist = dist + 0.01;
      x = expose->player->x + dist * vx;
      y = expose->player->y + dist * vy;
    }
  return (dist);
}

int		get_height(t_expose *expose, int x)
{
  double	angle;
  double	y1;
  double	vx;
  double	vy;
  double	dist;
  int		height;

  angle = expose->player->angle;
  y1 = (1 * ((WIN_X / 2) - x)) / WIN_X;
  vx = 0.5 * cos(angle) - y1 * sin(angle);
  vy = 0.5 * sin(angle) + y1 * cos(angle);
  dist = get_distance(expose, vx, vy);
  height = WIN_Y / (2 * dist);
  return (height);
}

int		affichage(t_expose *expose, int x, int height)
{
  int		y;

  y = 0;
  while (y < ((WIN_Y / 2) - height))
    {
      pixel_put_to_image(expose, x, y, 0x99CCFF);
      y++;
    }
  while (y < ((WIN_Y / 2) + height) && y < WIN_Y)
    {
      pixel_put_to_image(expose, x, y, 0xCC1122);
      y++;
    }
  while (y < WIN_Y)
    {
      pixel_put_to_image(expose, x, y, 0x660033);
      y++;
    }
  return (0);
}

int		wolf(t_expose *expose)
{
  int		x;
  int		height;

  x = 0;
  while (x < WIN_X)
    {
      height = get_height(expose, x);
      affichage(expose, x, height);
      x++;
    }
  return (0);
}
