/*
** display.h for epikong in /home/guigur/Bureau/RushHour/Epikong/src
** 
** Made by guillaume arthaud
** Login   arthau_g@epitech.net>
** 
** Started on  Sun Mar  9 02:17:04 2014 
** Last update Sun Mar  9 22:23:15 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#ifndef DISPLAY_H_
# define DISPLAY_H_

typedef struct s_texture
{
  SDL_Surface   *blocks[7];
} t_texture;

void	boucle();
void	load_texture(t_texture *s_texture);
void	draw_background(SDL_Surface *paul, t_kong *s_kong);
void	init_graphic(t_kong *s_kong);

#endif /* !DISPLAY_H_ */
