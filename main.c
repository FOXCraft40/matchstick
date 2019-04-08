/*
** main.c for main matchstick in /home/fox/epitech/B2/B2-C-Prog_Elem/CPE_2016_matchstick
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Wed Feb 22 22:34:14 2017 Fernand Matignon
** Last update Mon Apr 17 15:39:08 2017 Fernand Matignon
*/

#include <matchstick.h>

char		**my_carcopiner(int size)
{
  t_carco	*carco;

  carco = my_carco_init(size);
  TAB[X + 1] = NULL;
  while (X >= 0)
  {
    I = 0;
    while (I < FU)
      {
	if ((X == 0) || (X == size + 1))
	  TAB[X][I] = '*';
	else 
	  {
	    if ((I == 0) || (I == FU - 1))
	      TAB[X][I] = '*';
	    else if ((I <= (size - X)) || (I >= (size + X)))
	      TAB[X][I] = ' ';
	    else
	      TAB[X][I] = '|';
	  }
	I++;
	TAB[X][I] = '\0';
      }
    X--;
  }
  return (TAB);
}

t_carco		*my_carco_init(int size)
{
  t_carco	*carco;

  carco = malloc(sizeof(t_carco));
  I = 0;
  X = size + 1;
  FU = size + size + 1;
  TAB = my_malloctab(size + 3, size + 1);
  return (carco);
}

void		my_putttab(char **tab)
{
  int		x;

  x = 0;
  while (tab[x] != NULL)
    {
      my_putstr(tab[x]);
      my_putchar(1, '\n');
      x++;
    }
}

int		my_matchstick(int t_size, int max)
{
  char		**tab;
  int		win;

  win = -1;
  tab = my_carcopiner(t_size);
  while (win == -1)
    {
      tab = user_turn(tab, t_size, max);
      win = checkwin(2, tab);
      if (win == -1)
	{
	  tab = ai_turn(tab, max);
	  win = checkwin(1, tab);
	}
    }
  my_putttab(tab);
  if (win == 1)
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  else if (win == 2)
    my_putstr("You lost, too bad...\n");
  return(win);
}

int		main(int ac, char **av)
{
  int		win;

  if (ac != 3)
    {
      my_puterr("matchstick need 2 arguments !\n");
      return (84);
    }
  if ((my_getnbr(av[1]) <= 0) || (my_getnbr(av[2]) <= 0) ||
      (my_getnbr(av[1]) >= 16))
    {
      my_puterr("Invalid arguments !\n");
      return (84);
    }
  win = my_matchstick(my_getnbr(av[1]), my_getnbr(av[2]));
  return (win);
}
