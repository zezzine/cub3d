/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:41:22 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/04 14:47:28 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

void	img_pix_put(t_cub3d *cub, int x, int y, int color)
{
	char    *pixel;

    //printf("%d %d\n",img->line_len,img->bpp);
    pixel = cub->addr + (y * cub->line_len + x * (cub->bpp / 8));
	*(unsigned int *)pixel = color;
}

// last and correct version of display

void	ft_camera(t_cub3d **cub)
{
	double	dev;
	int		dec;

	dev = (double) WIDTH / 1700;
	dec = (int) WIDTH / 1700;
	if ((double) dec < dev)
		cub[0]->cmr = dec + 1;
	else
		cub[0]->cmr = dec;
}

int	get_color(t_cub3d *cub, int x, int y, int index)
{
	if (cub->ray_height[index][3] == 3)
		return (*(int *)cub->add_n + (y * cub->line_len + cub->text_x[x] * (cub->bpp / 8)));
	else if (cub->ray_height[index][3] == 4)
		return (*(int *)cub->add_s + (y * cub->line_len + cub->text_x[x] * (cub->bpp / 8)));
	else if (cub->ray_height[index][3] == 2)
		return (*(int *)cub->add_w + (y * cub->line_len + cub->text_x[x] * (cub->bpp / 8)));
	else if (cub->ray_height[index][3] == 1)
		return (*(int *)cub->add_e + (y * cub->line_len + cub->text_x[x] * (cub->bpp / 8)));
	return (0);
}

void	ft_screan_display(t_cub3d *cub)
{
	int i;
	int	j;
	int	mid;
	int	index;
	int	color;

	ft_camera(&cub);
	index = 0;
	i = 0;
	j = 0;
	while (index < WIDTH && j < WIDTH - 1)
	{
		i = 0;
		mid = cub->ray_height[index][2] / 2;
		while (i < HEIGHT)
		{
			if (i < ((HEIGHT / 2) - mid))
				img_pix_put(&cub[0], j, i, 0);
			else if (i > ((HEIGHT / 2) + mid))
				img_pix_put(&cub[0], j, i, 16777215);
			else if ((i >= ((HEIGHT / 2) - mid)) && (i <= ((HEIGHT / 2) + mid)))
			{
				if (cub->ray_height[index][3] == 1)
					img_pix_put(&cub[0], j, i,  get_color(cub, cub[0].text_x[index], (i - ((HEIGHT / 2) - mid)) % 50, index));
				else if (cub->ray_height[index][3] == 2)
					img_pix_put(&cub[0], j, i, get_color(cub, cub[0].text_x[index], (i - ((HEIGHT / 2) - mid)) % 50, index));
				else if (cub->ray_height[index][3] == 3)
					img_pix_put(&cub[0], j, i, get_color(cub, cub[0].text_x[index], (i - ((HEIGHT / 2) - mid)) % 50, index));
				else if (cub->ray_height[index][3] == 4)
					img_pix_put(&cub[0], j, i, get_color(cub, cub[0].text_x[index], (i - ((HEIGHT / 2) - mid)) % 50, index));
			}
			i++;
		}
		//if (j % cub->cmr == 0)
			index++;
		j++;
	}
}
