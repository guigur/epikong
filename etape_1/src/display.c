/*
** display.c for epikong in /home/guigur/Bureau/RushHour/Epikong/src
** 
** Made by guillaume arthaud 
** Login   <arthau_g@epitech.net>
** 
** Started on  Sat Mar  8 23:44:17 2014 
** Last update Sun Mar  9 22:43:59 2014 guillaume
*/

#include "my.h"
#include "display.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


void		boucle()
{
  int		alive = 1;
  SDL_Event	event;
  
  while (alive)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	alive = 0;
    }
}

void		load_textures(t_texture *s_texture)
{ 
  s_texture->blocks[0] = IMG_Load("src/assets/dark_stone.png");
  s_texture->blocks[1] = IMG_Load("src/assets/stonebrick.png");
  s_texture->blocks[2] = IMG_Load("src/assets/ladder.png");
  s_texture->blocks[3] = IMG_Load("src/assets/pumpkin.png");
  s_texture->blocks[4] = IMG_Load("src/assets/goldingot.png");
  s_texture->blocks[5] = IMG_Load("src/assets/trapdoor.png");
  s_texture->blocks[6] = IMG_Load("src/assets/char.png");
}

void		draw_background(SDL_Surface *paul, t_kong *s_kong)
{
  int		x;
  int		y;
  SDL_Rect	position;
  t_texture	*s_texture;
  
  x = 0;
  y = 0;
  position.x = 0;
  position.y = 0;
  if ((s_texture = malloc(sizeof(*s_texture))) == NULL)
    exit(-1);
  load_textures(s_texture);
  while (y < s_kong->sizeBlockY)
    {
      while (x < s_kong->sizeBlockX)
	{
	  position.x = x * 32;
	  SDL_BlitSurface(s_texture->blocks[0], NULL, paul, &position);	
	  if (s_kong->map[y][x] && s_kong->map[y][x] == 'w')
	    SDL_BlitSurface(s_texture->blocks[1], NULL, paul, &position);
	  else if (s_kong->map[y][x] && s_kong->map[y][x] == 's')
	    SDL_BlitSurface(s_texture->blocks[2], NULL, paul, &position);
	  else if (s_kong->map[y][x] && s_kong->map[y][x] == 'm')
	    SDL_BlitSurface(s_texture->blocks[3], NULL, paul, &position);
	  else if (s_kong->map[y][x] && s_kong->map[y][x] == 'k')
            SDL_BlitSurface(s_texture->blocks[4], NULL, paul, &position);
	  else if (s_kong->map[y][x] && s_kong->map[y][x] == 'o')
            SDL_BlitSurface(s_texture->blocks[5], NULL, paul, &position);
	  else if (s_kong->map[y][x] && s_kong->map[y][x] == 'i')
            SDL_BlitSurface(s_texture->blocks[6], NULL, paul, &position);
	  x++;
	}
      x = 0;
      y++;
      position.x = 0;
      position.y = y * 32;
    }
}

void		init_graphic(t_kong *s_kong)
{
  SDL_Surface	*paul;

  SDL_Init(SDL_INIT_VIDEO);

  if ((paul = SDL_SetVideoMode(s_kong->sizeBlockX * 32, 
			       s_kong->sizeBlockY * 32, 
			       32, SDL_HWSURFACE)) == NULL)
    printf("Erreur lors du chargement du mode vidéo:%s\n", SDL_GetError());
  draw_background(paul, s_kong);
  SDL_Flip(paul);
  boucle();
}
