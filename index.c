/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 21:29:20 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 20:42:41 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_minus(t_arr *arr)
{
	int		i;

	arr->tmp = malloc(arr->len * sizeof(long));
	i = 0;
	while (i < arr->len)
	{
		arr->tmp[i] = -1;
		i++;
	}
}

void	set_neg(t_arr *arr, int value)
{
	int	i;

	i = 0;
	while (i < arr->len)
	{
		if (arr->array[i] == value)
			break ;
		i++;
	}
	arr->array[i] = -1;
}

void	min_value(t_arr *arr)
{
	long	min;
	int		i;
	int		j;

	arr->index = 0;
	j = 0;
	i = 0;
	min = INT_MAX;
	while (i < arr->len)
	{
		if (min > arr->array[i] && arr->array[i] != -1)
		{
			min = arr->array[i];
			arr->index = j;
		}
		j++;
		i++;
	}
	set_neg(arr, min);
}

void	copy_stack(t_list **stack, t_arr *arr)
{
	int		i;
	t_list	*tmp;

	arr->array = malloc(ft_lstsize(*stack) * sizeof(long));
	if (!arr->array)
		return ;
	i = 0;
	while (*stack)
	{
		tmp = (*stack)->next;
		arr->array[i] = (*stack)->content;
		free(*stack);
		*stack = tmp;
		i++;
	}
	arr->len = i;
}

void	ft_index(t_list **stack)
{
	t_arr	arr;
	int		i;

	copy_stack(stack, &arr);
	set_minus(&arr);
	i = 0;
	while (i < arr.len)
	{
		min_value(&arr);
		arr.tmp[arr.index] = i;
		i++;
	}
	i = 0;
	while (i < arr.len)
	{
		ft_lstadd_back(stack, arr.tmp[i]);
		i++;
	}
	free(arr.array);
	free(arr.tmp);
}
