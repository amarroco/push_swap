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

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		move(a, b, "sa");
	else if (size == 3)
		sort_3(a);
	else if (size > 3 && !is_sorted(*a))
		sort(a, b);
}

/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac < 2)
        exit_error(NULL, NULL);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	b = NULL;
	a = fill_stack_values(ac, av);
	size = get_stack_size(a);
	assign_index(a, size + 1);
	push_swap(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}