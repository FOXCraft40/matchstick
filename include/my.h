#ifndef MY_H
#define MY_H

/* Display functions */
void	my_putchar(int, char);
void	my_putstr(char *);
void	my_puttab(char **);
void	my_puterr(char *);
void	my_putnbr(int);
void	my_puthexa(int);
void	my_puthexa_caps(int);
int	my_putbases(int nb, int bases);	//Return (-1 (if bases > 36))

/* Lib C function */
int	my_getnbr(char *);
int	my_check_alphanum(char); //Return (1 == num) (2 == CAPS) (3 == min) (0 == other)
char	*my_getnextline();
char	**my_map_to_tab(char *);

/* Str function */
int	my_strlen(char *);
int	my_strlen_bis(char *str, int i); //Return (Le nb de char de str[i] until '\n') 
char	*my_strdup(char *);
char	*revstr(char *);
char	*my_strlowcase(char *);

/* My_Printf*/
int	pf_check_mod(char *, int);
int	my_printf(char *, ...);
void	d_mod(int);	//int
void	x_mod(int);	//hexa
void    X_mod(int);	//HEXA
void    r_mod(char *);	//error
void	c_mod(int);	//char
void    s_mod(char *);	//string
void	mod_mod();	//Absolument rien

#endif
