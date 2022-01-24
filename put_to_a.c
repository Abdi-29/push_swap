/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_to_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 16:26:30 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 21:00:40 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_move(t_scan scan, int max, int *first, int *second)
{
	*first = 0;
	*second = 0;
	while (scan.top)
	{
		if (scan.top->content == max)
			break ;
		(*first)++;
		scan.top = scan.top->next;
	}
	while (scan.bottom)
	{
		if (scan.bottom->content == max)
			return ;
		(*second)++;
		scan.bottom = scan.bottom->prev;
	}
}

void	rotate_to_top_in_b(int first, t_list **stack_b)
{
	int		count;
	t_list	*current;
	t_list	*tmp;

	count = 0;
	current = *stack_b;
	if (!first)
		return ;
	while (current && count < first - 1)
	{
		current = current->next;
		count++;
	}
	if (!current)
		return ;
	tmp = current;
	while (current->next)
		current = current->next;
	current->next = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
}

void	compare_in_b(int first, int second, t_list **stack_b, t_list **stack_a)
{
	if (first <= second)
	{
		rotate_to_top_in_b(first, stack_b);
		ra(first, false);
	}
	else
	{
		rotate_to_top_in_b(ft_lstsize(*stack_b) - second - 1, stack_b);
		rra(second + 1, false);
	}
	push_stacks(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	b_stack(t_list *stack_a, t_list *stack_b)
{
	t_scan	scan;
	int		first;
	int		second;
	int		max;

	if (stack_b)
	{
		init_scan(&scan);
		add_element(&scan, stack_b);
		max = get_max(stack_b);
		get_move(scan, max, &first, &second);
		compare_in_b(first, second, &stack_b, &stack_a);
		free_node(&scan.top);
	}
	else
	{
		free_node(&stack_a);
		return ;
	}
	b_stack(stack_a, stack_b);
}
