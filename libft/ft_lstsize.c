/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstsize.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/14 00:47:29 by abba           #+#    #+#                */
/*   Updated: 2022/01/14 00:47:31 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	long	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
