/*
** game_ai.c for game AI matchsticks in /home/fox/epitech/B2/B2-C-Prog_Elem/CPE_2016_matchstick
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Sun Feb 26 22:42:33 2017 Fernand Matignon
** Last update Mon Apr 17 15:41:31 2017 Fernand Matignon
*/

#include <matchstick.h>

char	**ai_turn(char **tab, int max)
{
  int   i;
  int   x;
  int	res;

  i = 1;
  x = 1;
  res = 0;
  my_putstr("AI's turn...\n");
  while ((tab[x] != NULL) && (res == 0))
    {
      while (tab[x][i] != '\0') 
	{
	  if (tab[x][i] == '|')
	    res++;
	  i++;
	}
      i = 1;
      x++;
    }
  if (res <= max)
    res = res - 1;
  else if (max < res)
    res = max;
  return (tab = remove_sticks(2, tab, x - 1, res));
}
