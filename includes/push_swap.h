/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/14 00:45:40 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 14:11:04 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_arr
{
	long	*array;
	long	*tmp;
	int		len;
	int		index;
}			t_arr;

typedef struct s_num
{
	bool	check;
	long	bucket;
	long	min;
	long	max;
	int		first;
	int		second;
}			t_num;

void	rotate_a(t_list **stack, int done);
bool	is_sorted(t_list *stack);
void	get_min_and_max(t_list *stack, int *min_e, int *max_e);
bool	ft_check(t_list *stack, int value, int step);
void	sort_small_stack(t_list *stack_a, t_list *stack_b);
void	swap_a(t_list **stack_a, t_list **stack_b);
void	ft_swap(long *a, long *b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	sort_big_stack(t_list *stack_a, t_list *stack_b);
void	init_scan(t_scan *scan);
void	add_element(t_scan *scan, t_list *stack);
void	b_stack(t_list *stack_a, t_list *stack_b);
long	get_max(t_list *stack);
long	get_min(t_list *stack);
void	ra(int nb, bool check);
void	rra(int nb, bool check);
void	sort_big_stack_two(t_list *stack_a, t_list *stack_b, long max);
void	compare(int first, int second, t_list **stack_a, t_list **stack_b);
void	rotate_to_top(int first, t_list **stack_a, t_list **stack_b);
bool	hold(t_scan scan, t_num *num, int sort);
void	free_node(t_list **stack);
void	push_stacks(t_list **stack_a, t_list **stack_b);
void	ft_error(t_list **stack);
bool	has_duplicated(t_list *stack);
bool	ft_is_valid(char *str);
bool	is_overflow(t_list *stack);
bool	ft_len_error(char *str);
void	ft_free(t_list **stack_a, t_list **stack_b);
void	ft_big_sort(t_list *stack_a, t_list *stack_b, t_num num, int sort);
void	ft_index(t_list **stack);

#endif
