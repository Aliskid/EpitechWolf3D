/*
** expose.c for expose in /home/celebi_a/MUL_2014_wolf3d
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Sat Dec 20 16:19:12 2014 Alison Celebi
** Last update Tue May 19 15:20:20 2015 Alison Celebi
*/

#include "mlx.h"
#include "my.h"

int	gere_expose(t_expose *expose)
{
  mlx_put_image_to_window(expose->pointer->mlx_ptr, expose->pointer->win_ptr,
			  expose->draw->mlx_img, 0, 0);
  return (0);
}
