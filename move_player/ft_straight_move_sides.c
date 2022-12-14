/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straight_move_sides.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:50:21 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 14:08:35 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isnt_a_wall_sides(t_cub3d *cub, char c, int sides_angle)
{
	if (cub->p_ort == 0)
	{
		if (ft_check_up_side_and_update(&cub[0], c))
			return (1);
	}
	else if (cub->p_ort == 100)
	{
		if (ft_check_right_side_and_update(&cub[0], c))
			return (1);
	}
	else if (cub->p_ort == 200)
	{
		if (ft_check_down_side_and_update(&cub[0], c))
			return (1);
	}
	else if (cub->p_ort == 300)
	{
		if (ft_check_left_side_and_update(&cub[0], c))
			return (1);
	}
	return (0);
}

int	ft_sides_position_calc(t_cub3d *cub, char c, int sides_angle)
{
	if (sides_angle == 0)
		return (cub->p_pos[1] - STEP);
	else if (sides_angle == 100)
		return (cub->p_pos[0] + STEP);
	else if (sides_angle == 200)
		return (cub->p_pos[1] + STEP);
	else if (sides_angle == 300)
		return (cub->p_pos[0] - STEP);
	else if (sides_angle == 400)
		return (cub->p_pos[1] - STEP);
	return (0);
}

int	ft_check_new_pos_right(t_cub3d *cub, char c)
{
	double	w_range_min;
	double	w_range_max;
	double	h_range_min;
	double	h_range_max;
	double	next_pos;

	next_pos = ft_sides_position_calc(cub, c, sides_angle);
	w_range_max = cub->cell_w_h[0] * (cub->p_j + 1);
	w_range_min = cub->cell_w_h[0] * (cub->p_j);
	h_range_max = cub->cell_w_h[1] * (cub->p_i + 1);
	h_range_min = cub->cell_w_h[1] * (cub->p_i);
	if (cub->p_ort == 100 && next_pos > w_range_min)
		return (1);
	else if (cub->p_ort == 300 && next_pos < w_range_max)
		return (1);
	else if (cub->p_ort == 0 && next_pos < h_range_max)
		return (1);
	else if (cub->p_ort == 200 && next_pos > h_range_min)
		return (1);
	else if (ft_isnt_a_wall(cub, c))
		return (1);
	return (0);
}

int	ft_check_new_pos_sides(t_cub3d *cub, char c, int sides_angle)
{
	double	w_range_min;
	double	w_range_max;
	double	h_range_min;
	double	h_range_max;
	double	next_pos;

	if (c == 'r')
		ft_check_new_pos_right(&cub[0], c, sides_angle);
	next_pos = ft_sides_position_calc(cub, c, sides_angle);
	w_range_max = cub->cell_w_h[0] * (cub->p_j + 1);
	w_range_min = cub->cell_w_h[0] * (cub->p_j);
	h_range_max = cub->cell_w_h[1] * (cub->p_i + 1);
	h_range_min = cub->cell_w_h[1] * (cub->p_i);
	if (sides_angle == 100 && next_pos > w_range_min)
		return (1);
	else if (sides_angle == 300 && next_pos < w_range_max)
		return (1);
	else if (sides_angle == 0 && next_pos < h_range_max)
		return (1);
	else if (sides_angle == 200 && next_pos > h_range_min)
		return (1);
	else if (ft_isnt_a_wall_sides(cub, c, sides_angle))
		return (1);
	return (0);
}
