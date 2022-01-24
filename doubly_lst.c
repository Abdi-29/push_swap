/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubly_lst.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 16:25:48 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 20:35:00 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_scan *scan, t_list *element)
{
	if (!element)
		return ;
	if (!scan->top)
	{
		scan->bottom = element;
		scan->top = element;
		return ;
	}
	scan->bottom->next = element;
	element->prev = scan->bottom;
	scan->bottom = element;
}

t_list	*new_element(int value)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->next = NULL;
	element->prev = NULL;
	element->content = value;
	return (element);
}

void	add_element(t_scan *scan, t_list *stack)
{
	while (stack)
	{
		push(scan, new_element(stack->content));
		stack = stack->next;
	}
}

void	init_scan(t_scan *scan)
{
	scan->top = NULL;
	scan->bottom = NULL;
}
