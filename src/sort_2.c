/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexie <alexie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:17:56 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/09 13:19:47 by alexie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	big_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
		rotate_both(a, b, &cost_a, &cost_b);
	if (cost_a || cost_b)
		rotate_one(a, b, &cost_a, &cost_b);
	move(a, b, "pa");
}

static void	cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	big_moves(a, b, cost_a, cost_b);
}

static void	divide_and_rule(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			move(a, b, "pb");
			pushed++;
		}
		else
			move(a, NULL, "ra");
		i++;
	}
	while (stack_size - pushed > 3)
	{
		move(a, b, "pb");
		pushed++;
	}
}

static void	shift_stack(t_stack **a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*a);
	lowest_pos = get_lowest_pos(a);
	if (lowest_pos > stack_size / 2)
	{
		while (!is_sorted(*a))
		{
			move(a, NULL, "rra");
			lowest_pos++;
		}
	}
	else
	{
		while (!is_sorted(*a))
		{
			move(a, NULL, "ra");
			lowest_pos--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	divide_and_rule(a, b);
	sort_3(a);
	while (*b)
	{
		get_target_pos(a, b);
		get_cost(a, b);
		cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
