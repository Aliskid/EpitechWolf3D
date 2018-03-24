/*
** touchs.c for touches in /home/celebi_a/MUL_2014_wolf3d
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Sat Dec 20 18:14:41 2014 Alison Celebi
** Last update Thu May 21 15:07:47 2015 Alison Celebi
*/

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "my.h"

int key_hook(int key, t_expose *expose)
{
  if (key == ESCAPE)
    {
      printf("Wolf3D by Alison C");
      exit(EXIT_SUCCESS);
    }
  else if (key == LEFT)
    expose->player->angle += 0.2;
  else if (key == RIGHT)
    expose->player->angle -= 0.2;
  else if (key == UP)
    {
      expose->player->x += 0.2 * cos(expose->player->angle);
      expose->player->y += 0.2 * sin(expose->player->angle);
    }
  else if (key == DOWN)
    {
      expose->player->x -= 0.2 * cos(expose->player->angle);
      expose->player->y -= 0.2 * sin(expose->player->angle);
    }
  wolf(expose);
  gere_expose(expose);
  return (0);
}
