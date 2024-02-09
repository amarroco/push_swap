/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexie <alexie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:18:01 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/09 13:09:36 by alexie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*b_tail;

	tail = stack_bottom(*stack);
	b_tail = *stack;
	while (b_tail && b_tail->next && b_tail->next->next != NULL)
		b_tail = b_tail->next;
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	b_tail->next = NULL;
}

void	move(t_stack **a, t_stack **b, char *mv)
{
	if (mv[0] == 's' && mv[1] == 'a')
		swap(*a);
	if (mv[0] == 's' && mv[1] == 'b')
		swap(*b);
	if (mv[0] == 'p' && mv[1] == 'a')
		push(b, a);
	if (mv[0] == 'p' && mv[1] == 'b')
		push(a, b);
	if (mv[0] == 'r' && (mv[1] == 'a' || (mv[1] == 'r' && mv[2] == 0)))
		rotate(a);
	if (mv[0] == 'r' && (mv[1] == 'b' || (mv[1] == 'r' && mv[2] == 0)))
		rotate(b);
	if (mv[0] == 'r' && mv[1] == 'r' && (mv[2] == 'a' || mv[2] == 'r'))
		rev_rotate(a);
	if (mv[0] == 'r' && mv[1] == 'r' && (mv[2] == 'b' || mv[2] == 'r'))
		rev_rotate(b);
	ft_putstr_fd(mv, 1);
	ft_putstr_fd("\n", 1);
}
