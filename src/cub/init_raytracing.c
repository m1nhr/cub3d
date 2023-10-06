/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raytracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:35:31 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/10/06 02:50:38 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

double	start_pos(char **tab, int ok)
{
	double	y;
	double	x;
	char	*finder;

	x = 0;
	finder = "NESW";
	while (tab[(int)x])
	{	
		y = 0;
		while (tab[(int)x][(int)y])
		{
			if (ft_strchr(finder, tab[(int)x][(int)y]))
			{
				if (ok)
					return (y);
				return (x);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	init_value(t_cub *cub, t_main *data)
{
	cub->data = data;
	cub->map = data->map;
	cub->colors_ceiling = data->colors_ceiling;
	cub->colors_floor = data->colors_floor;
	cub->textures = data->textures;
	cub->posx = start_pos(cub->map, 0);
	cub->posy = start_pos(cub->map, 1);
	fprintf(stderr, "pos just init %f/%f\n", cub->posx, cub->posy);
	if (cub->map[(int)cub->posx][(int)cub->posy] == 'N')
	{
		cub->dirx = -1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = 0.66;
	}
	else if (cub->map[(int)cub->posx][(int)cub->posy] == 'S')
	{
		cub->dirx = 1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = -0.66;
	}
	else if (cub->map[(int)cub->posx][(int)cub->posy] == 'W')
	{
		cub->dirx = 0;
		cub->diry = -1;
		cub->planex = -0.66;
		cub->planey = 0;
	}
	else if (cub->map[(int)cub->posx][(int)cub->posy] == 'E')
	{
		cub->dirx = 0; // (commence à -1 pour N, 1 pour S, 0 sinon)
		cub->diry = 1;	// (commence à -1 pour W, 1 pour E, 0 sinon)
		cub->planex = 0.66;// (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
		cub->planey = 0;// (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	}
	cub->side = 0;

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