/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:29:25 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/28 02:08:07 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_argv(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	if (av[i - 5] == '/')
	{
		ft_printf("file name forgotten\n");
		return(0);
	}
	if (av[i - 1] == 'r' && av[i - 2] == 'e'
		&& av[i - 3] == 'b' && av[i - 4] == '.')
		return (1);
	
	return (0);
}
