/*
** game.c for game fot matchsticks in /home/fox/epitech/B2/B2-C-Prog_Elem/CPE_2016_matchstick
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Sun Feb 26 15:41:50 2017 Fernand Matignon
** Last update Sun Feb 26 23:13:17 2017 Fernand Matignon
*/

#include <matchstick.h>

char	**user_turn(char **tab, int nb_line, int max_m)
{
  int	ok;
  int	line;
  char	*buffer;
  int	matches;

  buffer = malloc(sizeof(char) * 10);
  ok = -1;
  my_putttab(tab);
  my_putstr("\nYour turn:");
  while (ok != 1)
    {
      my_putstr("\nLine: ");
      read(0, buffer, 9);
      ok = checkline(buffer, tab, nb_line);
      line = my_getnbr(buffer);
      buffer = my_clean_buffer(buffer);
    }
  while (ok != 2)
    {
      my_putstr("Matches: ");
      read(0, buffer, 9);
      ok = checkmatches(buffer, line, tab, max_m);
      matches = (my_getnbr(buffer));
      buffer = my_clean_buffer(buffer);
    }
  return (remove_sticks(1, tab, line, matches));
}

int	matches_count(char **tab, int line)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (tab[line][i] != '\0')
    {
      if (tab[line][i] == '|')
	res++;
      i++;
    }
  return (res);
}

int	checkmatches(char *b_matches, int line, char **tab, int max_m)
{
  int   matches;

  if ((b_matches[0] != '0') && (my_getnbr(b_matches) == 0))
    {
      my_puterr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  matches = my_getnbr(b_matches);
  if (matches > max_m)
    {
      my_puterr("Error: you cannot remove more than ");
      my_putnbr(max_m);
      my_puterr(" matches per turn\n");
      return (0);
    }
  if (matches_count(tab, line) < matches)
    {
      my_puterr("Error: not enough matches on this line\n");
      return (0);
    }
  if (matches == 0)
    {
      my_puterr("Error: you have to remove at least one match\n");
      return (0);
    }
  return 2;
}

int	checkline(char *b_line, char **tab, int nb_line)
{
  int	i;
  int	line;

  if ((b_line[0] != '0') && (my_getnbr(b_line) == 0))
    {
      my_puterr("Error: invalid input (positive number expected)");
      return (0);
    }
  line = my_getnbr(b_line);
  i = 0;
  if ((line > nb_line) || (line == 0))
    {
      my_puterr("Error: this line is out of range");
      return (0);
    }
  while (tab[line][i] != '\0')
    {
      if (tab[line][i] == '|')
	return (1);
      i++;
    }
  my_puterr("Error: Empty line !");
  return (-1);
}

int	checkwin(int k, char **tab)
{
  int	x;
  int	i;

  i = 1;
  x = 1;
  while (tab[x] != NULL)
    {
      while(tab[x][i] != '\0')
	{
	  if (tab[x][i] == '|')
	    return (-1);
	  i++;
	}
      i = 1;
      x++;
    }
  return (k);
}
