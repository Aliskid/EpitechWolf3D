/*
** my_putchar.c for my_putchar in /home/celebi_a/librairie
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Tue Oct  7 16:46:32 2014 Alison Celebi
** Last update Tue May 19 16:36:12 2015 Alison Celebi
*/

#include <unistd.h>
#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	my_puterror(char *str)
{
  write(1, str, my_strlen(str));
  return (-1);
}
