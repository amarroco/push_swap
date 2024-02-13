/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:18:18 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/13 17:40:02 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **a, t_stack **b, char **av, int ac)
{
	if (a == NULL || *a != NULL)
		free_stack(a);
	if (b == NULL || *b != NULL)
		free_stack(b);
	if (av)
		ft_free(av, ac);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

int	cost(int a, int b)
{
	int	nb;

	if (a >= 0 && b >= 0 && a >= b)
		nb = a;
	else if (a >= 0 && b >= 0 && a < b)
		nb = b;
	else if (a <= 0 && b <= 0 && a >= b)
		nb = -b;
	else if (a <= 0 && b <= 0 && a < b)
		nb = -a;
	else if (a >= 0 && b <= 0)
		nb = a - b;
	else if (a <= 0 && b >= 0)
		nb = b - a;
	return (nb);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}
