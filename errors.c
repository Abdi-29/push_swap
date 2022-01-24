/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 12:18:33 by abba          #+#    #+#                 */
/*   Updated: 2022/01/22 13:58:24 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_len_error(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '0' && str[i + 1])
			i++;
		else
			break ;
	}
	if (ft_strlen(str) - i < 1 || ft_strlen(str) - i > 10)
		return (true);
	return (false);
}

bool	is_overflow(t_list *stack)
{
	while (stack)
	{
		if (stack->content < 0 && stack->content < INT_MIN)
			return (true);
		else if (stack->content >= 0 && stack->content > INT_MAX)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	ft_error(t_list **stack)
{
	free_node(stack);
	ft_putendl_fd("Error", 1);
	return ;
}

bool	has_duplicated(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->content == stack->content)
				return (true);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (false);
}

bool	ft_is_valid(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strcmp(str, ""))
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
