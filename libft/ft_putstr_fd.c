/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putstr_fd.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/18 22:15:24 by abba           #+#    #+#                */
/*   Updated: 2022/01/18 22:15:26 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, *&s, 1);
		s++;
	}
}
