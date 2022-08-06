/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:00:48 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:16:14 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_win(t_cub3d **cub)
{
	ft_free_tab(cub[0]->map, NULL, NULL);
	free(cub[0]);
	//mlx_clear_window(cub[0]->mlx, cub[0]->win); leaks
	//mlx_destroy_window(cub[0]->mlx, cub[0]->win);
	exit(0);
	return (0);
}

void	ft_cub3d(t_cub3d *cub)
{
	img.mlx_ptr = cub->mlx;
	img.mlx_win = cub->win;
	ft_handle_keys(123, &cub);
	mlx_hook(cub->win, 17, 0, ft_close_win, &cub);
	mlx_hook(cub->win, 2, 0, ft_handle_keys, &cub);
	mlx_hook(cub->win, 6, 0, ft_handle_mouse, &cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub3d	**cub;

	cub = NULL;
	if (ft_parse_map_file(ac, av))
		return (1);
	cub = (t_cub3d **) malloc(sizeof(t_cub3d *) * 2);
	cub[0] = (t_cub3d *) malloc(sizeof(t_cub3d));
	cub[1] = NULL;
	cub[0] = ft_initialize_struct(av[1], &cub[0]);
	if (cub[0] == NULL)
	{
		free(cub);
		return (1);
	}
	cub[0]->mouse = 0;
	cub[0]->shot = 0;
	ft_cub3d(cub[0]);
	return (0);
}
