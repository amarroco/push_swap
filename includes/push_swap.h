/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:18:27 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/13 19:37:05 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			is_sorted(t_stack *stack);
void		sort_3(t_stack **stack);
void		sort(t_stack **a, t_stack **b);
void		rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		rotate_one(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		move(t_stack **a, t_stack **b, char *mv);
t_stack		*stack_bottom(t_stack *stack);
t_stack		*stack_new(int value);
int			stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);
void		get_cost(t_stack **a, t_stack **b);
int			get_lowest_pos(t_stack **stack);
void		get_target_pos(t_stack **a, t_stack **b);
void		free_stack(t_stack **stack);
void		exit_error(t_stack **a, t_stack **b, char **av, int ac);
int			cost(int a, int b);
long int	ft_atoi(const char *nptr);
void		ft_putstr_fd(char *s, int fd);
int			is_correct_input(char **av, int ac);
int			is_digit(char c);
int			is_sign(char c);
int			is_char(char src, char c);
int			ft_strlen(const char *s);
int			nbstr_cmp(const char *s1, const char *s2);
int			ft_count(char const *s, char c);
char		**ft_free(char **d, int n);
char		*ft_substr(char const *s, int start, int len);
char		**ft_split(char const *s, char c);

#endif