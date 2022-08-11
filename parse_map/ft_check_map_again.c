/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_again.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:13:27 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/16 22:22:55 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_above1(char **tab, int i, int j)
{
	int	len;

	len = ft_strlen(tab[i - 1]);
	if (len >= j && tab[i - 1][j] != '1' && tab[i - 1][j] != ' ')
		return (1);
	if (j != 0 &&  tab[i][j - 1] != ' ' && tab[i][j - 1] != '1')
		return (1);
	if (j != len -1 && tab[i][j + 1] != ' ' && tab[i][j + 1] != '1')
		return (1);
	if (tab[i + 1][j] != ' ' && tab[i + 1][j] != '1')
		return (1);
	return (0);
}

int	ft_check_above(char **tab, int i, int j)
{
	int	len;
	int p_len;

	len = ft_strlen(tab[i]);
	p_len = ft_strlen(tab[i - 1]);
	if (len > j)
	{
		if (p_len >= j && tab[i - 1][j - 1] != ' ' && tab[i - 1][j - 1] != '1')
			return (1);
		if (p_len > j && tab[i - 1][j] != ' ' && tab[i - 1][j] != '1')
			return (1);
		if (p_len > j + 1 && tab[i - 1][j + 1] != ' ' && tab[i - 1][j + 1] != '1')
			return (1);
	}
	else if (len == j)
	{
		if (p_len >= j && tab[i - 1][j - 1] != ' ' && tab[i - 1][j - 1] != '1')
			return (1);
		if (p_len > j && tab[i - 1][j] != ' ' && tab[i - 1][j] != '1')
			return (1);
	}
	else if (len == j - 1)
	{
		if (p_len >= j && tab[i - 1][j - 1] != ' ' && tab[i - 1][j - 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_check_under(char **tab, int i, int j)
{
	int	len;

	len = ft_strlen(tab[i]);
	if (len > j)
	{
		if (tab[i + 1][j - 1] != ' ' && tab[i + 1][j - 1] != '1')
			return (1);
		if (tab[i + 1][j] != ' ' && tab[i + 1][j] != '1')
			return (1);
		if (tab[i + 1][j + 1] != ' ' && tab[i + 1][j + 1] != '1')
			return (1);
	}
	if (len == j)
	{
		if (tab[i + 1][j - 1] != ' ' && tab[i + 1][j - 1] != '1')
			return (1);
		if (tab[i + 1][j] != ' ' && tab[i + 1][j] != '1')
			return (1);
	}
	if (len == j - 1)
	{
		if (tab[i + 1][j - 1] != ' ' && tab[i + 1][j - 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_go_check_if_one_surronded_space(char **tab, int i, int j, int ver)
{
	int	k;

	k = j;
	while (k > 0 && tab[i][k] == ' ')
		k--;
	if (tab[i][k] != '1')
		return (1);
	k = j;
	while (tab[i][j] && tab[i][k] == ' ')
		k++;
	if (tab[i][k] != '1')
		return (1);
	k = 0;
	if (i == 0)
		k = ft_check_under(tab, i, j);
	else if (i == ver - 1)
		k = ft_check_above(tab, i, j);
	else
	{
		k = ft_check_under(tab, i, j);
		k += ft_check_above(tab, i, j);
	}
	if (k)
		return (1);
	return (0);
}

void	ft_remove_newline(char **tab, int number_of_line)
{
	int	i;
	int len;

	i = 0;
	while (i < number_of_line)
	{
		len = 0;
		len = ft_strlen(tab[i]);
		if (tab[i][len - 1] == '\n')
		{
			tab[i][len - 1] = 0;
		}
		i++;
	}
}

int	ft_last_space_in_line(char *tab, int i, int j)
{
	int x;

	x = j;
	while (tab[x])
	{
		if (tab[x] == ' ')
			x++;
		else
			return (0);
	}
	printf("i = %d .  %d\n", i, j);
	return (1);
}

int	ft_check_map_again(char **tab, int i, int j)
{
	int	ver;

	ver = ft_strlen_tab(tab);
	ft_remove_newline(&tab[0], ver);
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] && tab[i][j] == ' ')
			j++;
		while (tab[i][j])
		{
			if (tab[i][j] == ' ')
			{
				if (ft_last_space_in_line(tab[i], i, j))
					j = j;
				else if (ft_go_check_if_one_surronded_space(tab, i, j, ver))
				{
					printf("here is the problem 4\n");
					return (ft_error(7));
				}
			}
			j++;
		}
		i++;
	}
	if (ft_check_if_sides_suronded_by_one(tab, 0, ver))
	{
		printf("here is the problem 5\n");
			return (ft_error(7));
	}
	return (0);
}
