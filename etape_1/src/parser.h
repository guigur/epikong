/*
** parser.h for epikong in /home/arthau_g/rendu/T2Rush1/etape_1/src
** 
** Made by guillaume
** Login   <arthau_g@epitech.net>
** 
** Started on  Sun Mar  9 22:45:19 2014 guillaume
** Last update Sun Mar  9 22:45:21 2014 guillaume
*/

#ifndef PARSER_H_
# define PARSER_H_

int	possoble_char(char b, int x, int y);
void	check_top_and_bottom(int nb, t_kong *s_kong);
void	check_sides(int nb, t_kong *s_kong);
void	check_map(t_kong *s_kong);
void	parser(t_kong *s_kong, char *path);

#endif /* !PARSER_H_ */
