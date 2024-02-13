/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:18:09 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/13 19:37:46 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*get_stack_values(int ac, char **av)
{
	t_stack		*a;
	long int	nb;
	int			i;

	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		if (i == 1)
		{
			a = stack_new((int)nb);
			if (!a)
				return (0);
		}
		else if (!stack_add_bottom(&a, stack_new((int)nb)))
			return (0);
		i++;
	}
	return (a);
}

static void	get_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = a;
		value = -2147483648;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == -2147483648 && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	get_index(*a, size + 1);
	if (size == 2 && !is_sorted(*a))
		move(a, b, "sa");
	else if (size == 3)
		sort_3(a);
	else if (size > 3 && !is_sorted(*a))
		sort(a, b);
	free_stack(a);
	free_stack(b);
}

static int	initialize(t_stack **a, t_stack **b, int ac, char **av)
{
	int		size;

	*b = NULL;
	*a = get_stack_values(ac, av);
	if (!(*a))
		return (free_stack(a), 0);
	size = get_stack_size(*a);
	push_swap(a, b, size);
	return (1);
}

int	main(int ac, char **av)
{
	char	**split;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2 || av[1][0] == 0)
		exit_error(NULL, NULL, NULL, 0);
	if (ac == 2 && ft_count(av[1], ' ') > 1)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			exit_error(NULL, NULL, NULL, 0);
		if (!is_correct_input(split, ft_count(av[1], ' ') + 1))
			exit_error(NULL, NULL, split, ft_count(av[1], ' '));
		if (!initialize(&a, &b, ft_count(av[1], ' ') + 1, split))
			exit_error(&a, &b, split, ft_count(av[1], ' '));
		ft_free(split, ft_count(av[1], ' '));
	}
	else if (!is_correct_input(av, ac))
		exit_error(NULL, NULL, NULL, 0);
	else if (!initialize(&a, &b, ac, av))
		exit_error(&a, &b, NULL, 0);
	return (0);
}
