/*
** main.c for epikong in /home/arthau_g/RushHour/Epikong
** 
** Made by guillaume arthaud
* Login   <arthau_g@epitech.net>
** 
** Started on  Fri Mar  7 20:53:16 2014 guillaume
** Last update Sun Mar  9 22:44:52 2014 guillaume
*/

#include "my.h"
#include "parser.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		possible_char(char b, int x, int y)
{
  if (b == '.' || b == 'w' || b == 's' || b == 'm' || b == 'o' || b == 'i' ||
      b == 'k')
    return (1);
  else
    {
      printf("\nCaractère invalide dans la map : \e[31;7m%c\e[30;0m ", b);
      printf("aux coordonées [x]%d [y]%d\n : ", x, y);
      exit(-1);
    }
  return (0);
}

void		check_top_and_bottom(int nb, t_kong *s_kong)
{
  int		i;

  i = 0;
  while (i < s_kong->sizeBlockX)
    {
      if (s_kong->map[nb][i] != 'w')
	{
	  printf("\n->%c<-\n", s_kong->map[nb][i]);
	  printf("Map invalide: Probleme avec les murs entourant la map\n");
	  exit(-1);
	}
      i++;
    }
}

void            check_sides(int nb, t_kong *s_kong)
{
  if (s_kong->map[nb][0] != 'w')
    {
      printf("\n->%c<-\n", s_kong->map[nb][0]);
      printf("Erreur: Probleme avec les murs sur le coté gauche de la map\n");
      exit(-1);
    }
  else if (s_kong->map[nb][s_kong->sizeBlockX - 1] != 'w')
    {
      printf("->%c<-\n", s_kong->map[nb][s_kong->sizeBlockX - 1]);
      printf("Erreur: Probleme avec les murs sur le coté droit de la map\n");
      exit(-1);
    }
}

void		check_map(t_kong *s_kong)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < s_kong->sizeBlockY)
    {
      while (x < s_kong->sizeBlockX)
        {
	  possible_char(s_kong->map[y][x], x, y);
	  check_sides(y, s_kong);
	  x++;
        }
      x = 0;
      y++;
    }
  check_top_and_bottom(0, s_kong);
  check_top_and_bottom(y - 1, s_kong);

}

void		parser(t_kong *s_kong, char *path)
{
  FILE		*fp;
  char		*line;
  size_t	len = 0;
  ssize_t	read;  
  int		i;
  
  i = 0;
  if ((s_kong->map = malloc(4096)) == NULL)
    {
      printf("Probleme d'allocation\n");
      exit(-1);
    }
  if ((fp = fopen(path, "r")) == NULL)
    {
      printf("Erreur lors de l'ouverture du Fichier\n");
      exit(-1);
    }
  while ((read = getline(&line, &len, fp)) != -1)
    {
      printf("%s", line);
      s_kong->map[i] = strdup(line);
      i++;
    }
  s_kong->sizeBlockX = strlen(s_kong->map[0]) - 1;
  s_kong->sizeBlockY = i;
  if (line != NULL)
    free(line);
  fclose(fp);
  check_map(s_kong);
}
