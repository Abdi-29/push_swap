/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 16:26:40 by abba          #+#    #+#                 */
/*   Updated: 2022/01/19 18:52:34 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack, int done)
{
	t_list	*current;
	t_list	*tmp;
	int		count;

	current = *stack;
	count = 0;
	while (current && count < done - 1)
	{
		current = current->next;
		count++;
	}
	if (!current)
		return ;
	tmp = current;
	while (current->next)
		current = current->next;
	current->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	if (done == 1)
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rra", 1);
}

void	ft_swap(long *a, long *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	push_to_b(int value, t_list **stack)
{
	t_list	*new;

	new = ft_lstnew(value);
	ft_lstadd_front(stack, new);
	ft_putendl_fd("pb", 1);
	if (ft_lstsize(*stack) >= 2)
	{
		if ((*stack)->content < (*stack)->next->content)
		{
			ft_swap(&(*stack)->content, &(*stack)->next->content);
			ft_putendl_fd("sb", 1);
		}
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*new;

	tmp = (*stack_b)->next;
	new = ft_lstnew((*stack_b)->content);
	free(*stack_b);
	*stack_b = tmp;
	ft_lstadd_front(stack_a, new);
	ft_putendl_fd("pa", 1);
}

void	swap_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		ft_swap(&(*stack_a)->content, &(*stack_a)->next->content);
		ft_putendl_fd("sa", 1);
		return ;
	}
	else
		push_to_b((*stack_a)->content, stack_b);
	free(*stack_a);
	*stack_a = tmp;
}
