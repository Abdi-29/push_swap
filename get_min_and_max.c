/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_min_and_max.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 11:32:45 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 11:32:52 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min(t_list *stack)
{
	long	min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->content)
		{
			min = stack->content;
		}
		stack = stack->next;
	}
	return (min);
}

long	get_max(t_list *stack)
{
	long	max;

	max = INT_MIN;
	while (stack)
	{
		if (max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
