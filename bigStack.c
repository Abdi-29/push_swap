/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigStack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 16:24:56 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 21:01:28 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	hold(t_scan scan, t_num *num, int sort)
{
	static int			i = 1;

	num->bucket = num->max * i + sort;
	num->check = false;
	while (scan.top)
	{
		if (scan.top->content < num->bucket)
		{
			num->check = true;
			break ;
		}
		num->first++;
		scan.top = scan.top->next;
	}
	while (scan.bottom)
	{
		if (scan.bottom->content < num->bucket)
			return (true);
		num->second++;
		scan.bottom = scan.bottom->prev;
	}
	if (num->check)
		return (true);
	i++;
	return (false);
}

void	compare(int first, int second, t_list **stack_a, t_list **stack_b)
{
	if (first <= second)
	{
		rotate_to_top(first, stack_a, stack_b);
		ra(first, true);
	}
	else
	{
		rotate_to_top(ft_lstsize(*stack_a) - second - 1, stack_a, stack_b);
		rra(second + 1, true);
	}
	ft_putendl_fd("pb", 1);
}

void	ft_big_sort(t_list *stack_a, t_list *stack_b, t_num num, int sort)
{
	t_scan	scan;

	num.first = 0;
	num.second = 0;
	if (stack_a)
	{
		init_scan(&scan);
		add_element(&scan, stack_a);
		if (hold(scan, &num, sort))
			compare(num.first, num.second, &stack_a, &stack_b);
		free_node(&scan.top);
	}
	else
	{
		b_stack(stack_a, stack_b);
		return ;
	}
	ft_big_sort(stack_a, stack_b, num, sort);
}

void	sort_big_stack(t_list *stack_a, t_list *stack_b)
{
	t_num	num;
	t_list	*tmp;
	t_list	*copy;

	num.min = get_min(stack_a);
	if (num.min < 0)
		num.min *= -1;
	copy = NULL;
	while (stack_a)
	{
		tmp = stack_a->next;
		ft_lstadd_back(&copy, stack_a->content + num.min);
		free(stack_a);
		stack_a = tmp;
	}
	ft_index(&copy);
	num.max = get_max(copy);
	if (ft_lstsize(copy) <= 100)
	{
		num.max = num.max / 5;
		ft_big_sort(copy, stack_b, num, 5);
		return ;
	}
	num.max = num.max / 13;
	ft_big_sort(copy, stack_b, num, 25);
}
