/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:17:59 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/15 19:45:48 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] && is_sign(av[i]) && av[i + 1] != 0)
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != 0 && !is_digit(av[i]))
		return (0);
	return (1);
}

static int	no_duplicates(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 2;
		while (j < ac)
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] && is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static int	arg_is_int(char *av)
{
	long int	i;

	i = ft_atoi(av);
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}

int	is_correct_input(char **av, int ac)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	av[0] = 0;
	while (i < ac)
	{
		if (!av[i][0] || !arg_is_number(av[i]) || !arg_is_int(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (!no_duplicates(av, ac))
		return (0);
	return (1);
}
