/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:28:53 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/09/28 11:35:47 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub *cub)
{
	ft_putendl_fd("goodbye :)", 1);
	mlx_destroy_image(cub->mlx, cub->img->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free (cub->img);
	free (cub->data);
	exit (1);
	return (0);
}

/*
dirX et dirY représentent la direction du joueur, 
et planeX et planY le plan de la caméra du joueur. 
Assurez-vous que le plan de la caméra est perpendiculaire 
à la direction, mais vous pouvez en modifier la longueur. 
Le rapport entre la longueur de la direction et le plan de la 
caméra détermine le FOV, ici le vecteur direction est 
un peu plus long que le plan de la caméra, donc le FOV sera 
inférieur à 90° (plus précisément, 
le FOV est de 2 * atan(0,66 /1.0)=66°, ce qui est parfait 
pour un jeu de tir à la première personne). 
Plus tard, lors d'une rotation avec les touches de saisie, 
les valeurs de dir et plane seront modifiées, mais elles 
resteront toujours perpendiculaires et garderont la même longueur.*/



//INTO THE WHILE
void	raydir_calcul(t_cub *cub)
{
	int x = 0;

    while (x < WIGHT)
	{
      //calculate ray position and direction
      cub->camerax = 2 * x / WIGHT - 1; //x-coordinate in camera space
      cub->raydirx = cub->dirx + cub->planex * cub->camerax;
      cub->raydiry = cub->diry + cub->planey * cub->camerax;
	  x++;
	}
}

void	init_value(t_cub *cub, t_main *data)
{
	cub->map = data->map;
	cub->colors_ceiling = data->colors_ceiling;
	cub->colors_floor = data->colors_floor;
	cub->textures = data->textures;
	cub->posx = get_start_pos(cub, 1);
	cub->posy = get_start_pos(cub, 0);
	//vexteur de direction
	cub->dirx = -1; // (commence à -1 pour N, 1 pour S, 0 sinon)
	cub->diry = 0; 	// (commence à -1 pour W, 1 pour E, 0 sinon)
	//vecteur du plan
	cub->planex = 0; // (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	cub->planey = 0.66; // (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	
	cub->mapx = (int)cub->posx;// coordonée x du carré dans lequel est pos
	cub->mapy = (int)cub->posy;// coordonnée y du carré dans lequel est pos
	fprintf(stderr, "%d/%d\n", cub->mapx, cub->mapy);
	cub->hit = 0;
/*	cub->raydirx; //calcul de direction x du rayon	
	cub->raydiry; //calcul de direction y du rayon
double	raydir_calcul(t_cub *cub);
*/
/*	//distance
	cub->sidedistx;//distance que le rayon parcours jusqu'au 
					//premier point d'intersection vertical (=un coté x)
	cub->sidedisty;//distance que le rayon parcours jusqu'au
					// premier point d'intersection horizontal (= un coté y)
	cub->deltadistx;//distance que rayon parcours entre chaque point d'intersection vertical
	cub->deltadisty; //distance que rayon parcours entre chaque point d'intersection horizontal
	
	cub->stepx;// -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	cub->stepx; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	cub->side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	cub->dist_to_wall; // distance du joueur au mur
	cub->draw_start; //position de debut ou il faut dessiner
	cub->draw_end; //position de fin ou il faut dessiner
*/
	cub->time = 0; // time of current frame
	cub->oldtime = 0; //time of previous frame
}

/* a voir plus tard
typedef struct	s_ray
{
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		x; //permet de parcourir tous les rayons
}					t_ray;
*/

void	put_x10(t_cub *cub, int x, int y, int color)
{
	int tmpx;
	int tabsize;
	int ok;

	tabsize = 0;
	while (cub->map[tabsize])
		tabsize++;
	while (y <= tabsize * 6)
	{
		tmpx = x;
		ok = 0;
		while ((size_t)tmpx < (ft_strlen(cub->map[ok]) - 1) * 6)
		{
			put_pixel(cub, tmpx, y, color);
			tmpx++;
		}
		y++;
	}
}

void	display_minimap(t_cub *cub, char *finder, int lentab, int y_tab)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y_tab < lentab)
	{
		x = 0;
		i = 0;
		while ((size_t)i < ft_strlen(cub->map[y_tab]))
		{
			if (cub->map[y_tab][i] == '1')
				put_x10(cub, x, y, 0x000000);
			else if (ft_strchr(finder, cub->map[y_tab][i]))
				put_x10(cub, x, y, 0xFF0000);
			else if (cub->map[y_tab][i] == '0' || !cub->map[y_tab][i])
				put_x10(cub, x, y, 0x13C6A2);
			x += 6;
			i++;
		}
		y += 6;
		y_tab++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}

void	display_game_frame(t_cub *cub)
{
	int x = 0;

    while (x < WIGHT)
	{
		//calculate ray position and direction
		cub->camerax = 2 * x / WIGHT - 1; //x-coordinate in camera space
		cub->raydirx = cub->dirx + cub->planex * cub->camerax;
		cub->raydiry = cub->diry + cub->planey * cub->camerax;
		
		
		if (cub->raydirx != 0)
			cub->deltadistx = fabs(1 / cub->raydirx);
		else 
			cub->deltadistx = 1e30;
			
		if (cub->raydiry != 0)
			cub->deltadisty = fabs(1 / cub->raydiry);
		else
			cub->deltadisty = 1e30;
		
		
		if (cub->raydirx < 0)
		{
			cub->stepx = -1;
			cub->sidedistx = (cub->posx - cub->mapx) * cub->deltadistx;
		}
		else
		{
			cub->stepx = 1;
			cub->sidedistx = (cub->mapx + 1.0 - cub->posx) * cub->deltadistx;
		}
		if (cub->raydiry < 0)
		{
			cub->stepy = -1;
			cub->sidedisty = (cub->posy - cub->mapy) * cub->deltadisty;
		}
		else
		{
			cub->stepy = 1;
			cub->sidedisty = (cub->mapy + 1.0 - cub->posy) * cub->deltadisty;
		}
		cub->hit = 0;
		 //jump to next map square, either in x-direction, or in y-direction
		while (cub->hit == 0)
		{
			if (cub->sidedistx < cub->sidedisty)
			{
				cub->sidedistx += cub->deltadistx;
				cub->mapx += cub->stepx;
				cub->side = 0;
			}
			else
			{
				cub->sidedisty += cub->sidedisty;
				cub->mapy += cub->stepy;
				cub->side = 1;
			}
			if (cub->map[cub->mapx][cub->mapy] == '1')
			{
				cub->hit = 1;
			}
		}
		
		if (cub->side == 0)
			cub->dist_to_wall = (cub->sidedistx - cub->deltadistx);
		else
			cub->dist_to_wall = (cub->sidedisty - cub->deltadisty);
		

		// calcul de la hauteur de la ligne a display
		int lineheight = (int)(HEIGHT / cub->dist_to_wall);
		
		//
		cub->draw_start = -lineheight / 2 + HEIGHT / 2;
		if (cub->draw_start < 0)
			cub->draw_start = 0;
		cub->draw_end = lineheight / 2 + HEIGHT / 2;
		if (cub->draw_end >= HEIGHT)
			cub->draw_end = HEIGHT - 1;
		int color;
		color = 0xFFFF00;
		if (cub->side == 1)
			color = color / 2;
		fprintf(stderr, "[start : %d][end : %d] (for x = %d)\n", cub->draw_start, cub->draw_end, x);
	//	fprintf(stderr, "[rayx : %f][rayyy : %f] (for x = %d)\n", cub->raydirx, cub->raydiry, x);
		int y = cub->draw_start;
		if (y > 0 && y < HEIGHT)
		{
			while (y < cub->draw_end)
			{
				put_pixel(cub, x, y, color);
				y++;
			}
			
		}
		
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);

}

//		A MODIF PAR cub->colors_ceiling mais voir pour RGB to hex
void	display_background(t_cub *cub)
{
	int	x;
	int	y;
	double fade;

	fade = 1;
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		fade *= 1.0018;
		while (x < WIGHT)
		{
			put_pixel(cub, x, y, 0x0000FF * fade);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIGHT)
		{
			put_pixel(cub, x, y, 0x808080);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 2);
}


void    go_cub(t_main *data)
{
	t_cub cub;
	
	init_value(&cub, data);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		exit (1);
	cub.win = mlx_new_window(cub.mlx, 750, 750, "CUB3D");
	if (!cub.win)
		exit (1);
	img_init(&cub);
//	img_init(data); 
//	mlx_hook(data->win, 2, 1L << 0, &keymap, data);
//	mlx_mouse_hook(data->win, &ctrl_mouse, data);
	mlx_hook(cub.win, 17, 1L << 17, &close_window, data);
	int i =0;
	while (cub.map[i])
	{
		fprintf(stderr, "%s = %d\n", cub.map[i], i);
		i++;
	}
	fprintf(stderr, "start pos = [%f][%f]\n", cub.posx, cub.posy);
	display_background(&cub);
	display_game_frame(&cub);
	display_minimap(&cub, "NESW", what_lentab(cub.map), 0);
	mlx_loop(cub.mlx);
}
