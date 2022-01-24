/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallStack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 16:26:50 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 20:18:06 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *stack)
{
	t_list	*tmp;

	while (stack->next)
	{
		tmp = stack->next;
		if (stack->content > tmp->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	get_min_and_max(t_list *stack, int *min_e, int *max_e)
{
	int	min;
	int	max;

	max = INT_MIN;
	min = INT_MAX;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		if (max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	*min_e = min;
	*max_e = max;
}

bool	ft_check(t_list *stack, int value, int step)
{
	if (step)
	{
		while (stack->next)
			stack = stack->next;
		if (stack->content != value)
			return (false);
	}
	else
	{
		if (stack->content != value)
			return (false);
	}
	return (true);
}

void	sort_small_stack(t_list *stack_a, t_list *stack_b)
{
	int	min_element;
	int	max_element;

	get_min_and_max(stack_a, &min_element, &max_element);
	if (is_sorted(stack_a) && !stack_b)
	{
		free_node(&stack_a);
		return ;
	}
	else if (is_sorted(stack_a) && stack_b)
		push_to_a(&stack_a, &stack_b);
	else if (ft_check(stack_a, max_element, 0))
		rotate_a(&stack_a, 1);
	else if (ft_check(stack_a, min_element, 1))
		rotate_a(&stack_a, ft_lstsize(stack_a) - 1);
	else if (stack_a->content == min_element || stack_a->content != max_element)
		swap_a(&stack_a, &stack_b);
	sort_small_stack(stack_a, stack_b);
}
