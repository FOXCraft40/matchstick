/*
** other.c for other for mathstick in /home/fox/epitech/B2/B2-C-Prog_Elem/CPE_2016_matchstick
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Thu Feb 23 15:52:59 2017 Fernand Matignon
** Last update Sun Feb 26 23:19:32 2017 Fernand Matignon
*/

#include <matchstick.h>

char	**my_malloctab(int x_size, int i_size)
{
  int	x;
  char	**tab;
  
  x = 0;
  tab = malloc(sizeof(char *) * (x_size));
  while (x != x_size)
    {
      tab[x] = malloc(sizeof(char) * (i_size + 2));
      x++;
    }
  return (tab);
}

char	**remove_sticks(int k, char **tab, int line, int matches)
{
  int	i;
  int	x;

  i = 0;
  x = 1;
  while (tab[line][i] != '|')
    i++;
  while (tab[line][i] == '|')
    i++;
  while (x <= matches)
    {
      tab[line][i - x] = ' ';
      x++;
    }
  if (k == 1)
    my_putstr("Player removed ");
  else
    my_putstr("AI removed ");
  my_putnbr(matches);
  my_putstr(" match(es) from line ");
  my_putnbr(line);
  my_putchar(1, '\n');
  return (tab);
}

char	*my_clean_buffer(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      buffer[i] = '\0';
      i++;
    }
  return (buffer);
}
