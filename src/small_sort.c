#include "../includes/push_swap.h"

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