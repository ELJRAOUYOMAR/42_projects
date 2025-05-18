/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:57:21 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/29 03:24:08 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b, char **split)
{
	if (stack_a)
		ft_stack_clear(stack_a);
	if (stack_b)
		ft_stack_clear(stack_b);
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

int	add_number_to_stack(char *str, t_stack **stack_a, char **split)
{
	int		error;
	int		num;
	t_stack	*new;

	error = 0;
	num = ft_atoi_check(str, &error);
	if (error)
	{
		free_split(split);
		return (0);
	}
	new = ft_stack_new(num);
	if (!new)
		ft_error(stack_a, NULL, split);
	ft_stack_add_back(stack_a, new);
	return (1);
}

int	parse_and_add_numbers(char *arg, t_stack **stack_a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!add_number_to_stack(split[j], stack_a, split))
			return (0);
		j++;
	}
	free_split(split);
	return (1);
}

static int	check_space(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (1);
		str++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_space(argv[i]))
			return (0);
		if (!parse_and_add_numbers(argv[i], stack_a))
			return (0);
		i++;
	}
	return (1);
}
