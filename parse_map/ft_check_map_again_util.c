/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_again_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:10:36 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/16 22:22:37 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_range_to_check(int s1)
{
	if (s1 == 0)
		return (s1);
	return (s1 - 1);
}

int	ft_check_left_side(char **tab, int i, int s1, int s2)
{
	int	j;

//printf("walk\n");
//printf("line is (%s) %d %d %d\n", tab[i + 1], i + 1, s1, s2);
	if (s1 > s2)
	{
		j = ft_range_to_check(s2);
		while (j <= s1 && tab[i +1][j])
		{
			if (tab[i + 1][j] == '0')//if (tab[i + 1][j] != '1')
			{
				//printf("range 1\n");
				return (1);
			}
			j++;
		}
	}
	else if (s1 < s2)
	{
		j = ft_range_to_check(s1);
		while (j <= s2 && tab[i][j])
		{
			if (tab[i][j] == '0')//if (tab[i][j] != '1')
			{
				//printf("range 1\n");
				return (1);
			}
			j++;
		}
	}
	return (0);
}

int	ft_check_right_side(char **tab, int i, int s1, int s2)
{
	int	j;

//		printf("line is (%s) %d %d %d\n", tab[i + 1], i + 1, s1, s2);
	if (s1 > s2)
	{
		j = ft_range_to_check(s2);
		while (j < s1 && tab[i][j])
		{
			if (tab[i][j] == '0')//(tab[i][j] != '1')
				{
					//printf("let fix it 1\n");
					return (1);
				}
			j++;
		}
	}
	else if (s1 < s2)
	{
		j = ft_range_to_check(s1);
		while (j < s2 && tab[i + 1][j])
		{
			if (tab[i + 1][j] == '0')
				{
					//printf("let fix it 2 . tab[i][j] [%c] %d %d\n", tab[i][j], i + 1 , j);
					return (1);
				}
			j++;
		}
	}
	return (0);
}

int	ft_check_if_sides_suronded_by_one(char **tab, int i, int ver)
{
	int	strt;
	int	end;
	int	nxt_s;
	int	nxt_e;

	while (i < ver - 1)
	{
		strt = ft_skip_space(tab[i], 0);
		end = ft_strlen(tab[i]);
		nxt_s = ft_skip_space(tab[i + 1], 0);
		nxt_e = ft_strlen(tab[i + 1]);
		if (strt != nxt_s)
		{
			if (ft_check_left_side(tab, i, strt, nxt_s))
			{
				printf("\nleft side %d\n", i);
				return (1);
			}
		}
		if (end != nxt_e)
		{
			if (ft_check_right_side(tab, i, end, nxt_e))
			{
				printf("\nright side %d\n", i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
