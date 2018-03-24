/*
** my_strlen.c for my_strlen.c in /home/celebi_a/rendu/MUL_2014_wolf3d
** 
** Made by Alison Celebi
** Login   <celebi_a@epitech.net>
** 
** Started on  Tue May 19 15:25:28 2015 Alison Celebi
** Last update Tue May 19 15:26:09 2015 Alison Celebi
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
