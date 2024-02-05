#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */

t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *a, int ac);

/* Sorting Algorithms */

int			is_sorted(t_stack *stack);
void		sort_3(t_stack **stack);
void		sort(t_stack **a, t_stack **b);

/* Operations */

void    	move(t_stack **a, t_stack **b, char *mv);

/* Stack Functions */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
int			stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

void		get_cost(t_stack **a, t_stack **b);
int			get_lowest_pos(t_stack **stack);
void		get_target_pos(t_stack **a, t_stack **b);

void		free_stack(t_stack **stack);
void		exit_error(t_stack **a, t_stack **b);
int			nb_abs(int nb);
long int	ft_atoi(const char *nptr);
void		ft_putstr_fd(char *s, int fd);

/* Input Check */

int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

#endif