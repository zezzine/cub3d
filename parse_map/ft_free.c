/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <tel-bouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:57:29 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/16 22:22:02 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_free_tab(char **str, char *arg1, char *arg2)
{
	int	i;

	if (arg1 != NULL)
		free(arg1);
	if (arg2 != NULL)
		free(arg2);
	arg1 = NULL;
	arg2 = NULL;
	if (str == NULL)
		return (str);
	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
	}
	str = NULL;
	return (str);
}
