/*
** main.c for jeej in /home/guigur/Bureau/RushHour/Epikong/src
** 
** Made by guillaume arthaud 
** Login   <arthau_g@epitech.net>
** 
** Started on  Sat Mar  8 17:25:52 2014 
** Last update Sun Mar  9 22:25:07 2014 
*/

#include "my.h"
#include "display.h"
#include "parser.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int		main(int argc, char **argv)
{
  t_kong	*s_kong;

  if (argc == 2)
    {
      if ((s_kong = malloc(sizeof(*s_kong))) == NULL)
	{
	  printf("Probleme d'allocation mémoire\n");
	  exit(-1);
	}
      parser(s_kong, argv[1]);
      init_graphic(s_kong);
    }
  else
    printf("Usage: ./epikong map\n");
  return (0);
}
