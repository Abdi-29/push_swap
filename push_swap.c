/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 16:26:07 by abba          #+#    #+#                 */
/*   Updated: 2022/01/24 20:36:55 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == *s2)
		return (1);
	return (0);
}

bool	parse(t_list **stack, char **str)
{
	while (*str)
	{
		if (!(ft_is_valid(*str)))
		{
			ft_error(stack);
			free(*str);
			return (true);
		}
		ft_lstadd_back(stack, ft_atoi(*str));
		free(*str);
		str++;
	}
	return (false);
}

bool	is_valid_input(char **argv, t_list **stack_a)
{
	char	**s_str;

	while (*argv)
	{
		if (ft_len_error(*argv))
		{
			ft_error(stack_a);
			return (false);
		}
		s_str = ft_split(*argv, ' ');
		if (parse(stack_a, s_str) || !s_str)
		{
			free(s_str);
			return (false);
		}
		free(s_str);
		argv++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	argv += 1;
	if (!is_valid_input(argv, &stack_a))
		return (1);
	else if (has_duplicated(stack_a) || is_overflow(stack_a))
	{
		ft_error(&stack_a);
		return (1);
	}
	else if (ft_lstsize(stack_a) < 6)
		sort_small_stack(stack_a, stack_b);
	else if (is_sorted(stack_a))
		free_node(&stack_a);
	else
		sort_big_stack(stack_a, stack_b);
	system("leaks push_swap");
	return (0);
}
