/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 18:22:10 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 10:59:47 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int nb, bool check)
{
	while (nb)
	{
		if (check)
			ft_putendl_fd("ra", 1);
		else
			ft_putendl_fd("rb", 1);
		nb--;
	}
}

void	rra(int nb, bool check)
{
	while (nb)
	{
		if (check)
			ft_putendl_fd("rra", 1);
		else
			ft_putendl_fd("rrb", 1);
		nb--;
	}
}

void	rotate_to_top(int first, t_list **stack_a, t_list **stack_b)
{
	int		count;
	t_list	*current;
	t_list	*tmp;

	count = 0;
	current = *stack_a;
	if (!first)
	{
		push_stacks(stack_a, stack_b);
		return ;
	}
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
	current->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	push_stacks(stack_a, stack_b);
}
