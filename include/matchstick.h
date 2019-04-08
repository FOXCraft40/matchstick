/*
** matchstick.h for header matchstick in /home/fox/epitech/B2/B2-C-Prog_Elem/CPE_2016_matchstick
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Fri Feb 24 15:09:31 2017 Fernand Matignon
** Last update Sun Feb 26 23:26:10 2017 Fernand Matignon
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

/* Include */
#include <my.h>
#include <stdlib.h>
#include <unistd.h>

/* Macros */
# define X	(carco->x)
# define I	(carco->i)
# define FU	(carco->fu)
# define TAB	(carco->tab)

/* STRUCT */
typedef struct	s_carco
{
  int		x;
  int		i;
  int		fu;
  char		**tab;
}		t_carco;

/* Proto Function */
void	my_putttab(char **);
int	my_matchstick(int, int);
int	checkmatches(char *, int, char **, int);
int	checkline(char *, char **, int);
int	checkwin(int, char **);
int	matches_count(char **, int);
char	**user_turn(char **, int, int);
char	**ai_turn(char **, int);
char	*my_clean_buffer(char *);
char	**my_malloctab(int, int);
char	**my_carcopiner(int);
char	**remove_sticks(int, char **, int, int);
t_carco *my_carco_init(int);

#endif
