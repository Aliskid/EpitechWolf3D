/*
** my_putstr.c for my_putstr.c in /home/celebi_a/librairie
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Tue Oct  7 16:45:14 2014 Alison Celebi
** Last update Tue May 19 15:36:14 2015 Alison Celebi
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      {
	my_putchar(str[i]);
	i = i + 1;
      }
  return (0);
}
