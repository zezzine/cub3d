/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:47:55 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/19 14:20:35 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_a_file(char *line)
{
	int		fd;

	fd = open(line, O_RDONLY);
	if (fd > 2)
	{
		close(fd);
		return (1);
	}
	if (fd != -1)
		close (fd);
	return (0);
}

int	ft_check_line(char *line, char *elem, int len)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	if (ft_strcmp(tab[0], elem) == 0)
	{
		i = ft_strlen(tab[1]);
		if (tab[1][i - 1] == '\n')
			tab[1][i - 1] = 0;
		if (len == 2 && ft_is_a_file(tab[1]))
		{
			ft_free_tab(tab, NULL, NULL);
			return (1);
		}
		else if (len == 1 && ft_is_color(tab[1]))
		{
			ft_free_tab(tab, NULL, NULL);
			return (1);
		}
	}
	ft_free_tab(tab, NULL, NULL);
	return (0);
}

int	ft_number_of_lines_in_file(char	*av)
{
	char	*line;
	int		fd;
	int		i;
	int		len;

	fd = open(av, O_RDONLY);
	if (fd < 3)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 1)
			i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	ft_check_elem_identifers(int **elem, char **elem_tab, int i)
{
	if (elem[0][0] == 0)
		elem[0][0] = ft_check_line(elem_tab[i], "NO", 2);
	if (elem[0][1] == 0)
		elem[0][1] = ft_check_line(elem_tab[i], "SO", 2);
	if (elem[0][2] == 0)
		elem[0][2] = ft_check_line(elem_tab[i], "WE", 2);
	if (elem[0][3] == 0)
		elem[0][3] = ft_check_line(elem_tab[i], "EA", 2);
	if (elem[0][4] == 0)
		elem[0][4] = ft_check_line(elem_tab[i], "F", 1);
	if (elem[0][5] == 0)
		elem[0][5] = ft_check_line(elem_tab[i], "C", 1);
}

int	ft_check_elems(char	**elem_tab)
{
	int	i;
	int	*elem;
	int	sum;

	elem = (int *) malloc(sizeof(int) * 6);
	i = 0;
	while (i < 6)
		elem[i++] = 0;
	i = 0;
	while (elem_tab[i] && i < 6)
	{
		ft_check_elem_identifers(&elem, elem_tab, i);
		i++;
	}
	i = 0;
	sum = 0;
	while (i < 6)
	{
		sum += elem[i];
		i++;
	}
	free(elem);
	return (sum);
}
