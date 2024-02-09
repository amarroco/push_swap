/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexie <alexie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:18:12 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/09 22:29:18 by alexie           ###   ########.fr       */
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

static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_3(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		move(stack, NULL, "ra");
	else if ((*stack)->next->index == highest)
		move(stack, NULL, "rra");
	if ((*stack)->index > (*stack)->next->index)
		move(stack, NULL, "sa");
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		move(a, b, "rrr");
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_a > 0 && *cost_b > 0)
	{
		move(a, b, "rr");
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_one(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a || *cost_b)
	{
		if (*cost_a < 0)
		{
			move(a, NULL, "rra");
			(*cost_a)++;
		}
		else if (*cost_b < 0)
		{
			move(NULL, b, "rrb");
			(*cost_b)++;
		}
		else if (*cost_a > 0)
		{
			move(a, NULL, "ra");
			(*cost_a)--;
		}
		else if (*cost_b > 0)
		{
			move(NULL, b, "rb");
			(*cost_b)--;
		}
	}
}
