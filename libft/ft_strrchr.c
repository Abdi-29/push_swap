/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strrchr.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/18 22:11:23 by abba           #+#    #+#                */
/*   Updated: 2022/01/18 22:11:24 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*s_copy;

	s_copy = (char *)s;
	i = ft_strlen(s_copy) - 1;
	j = i + 1;
	while (&s_copy[i] != s - 1)
	{
		if (s_copy[i] == (char)c)
			return (s_copy + i);
		i--;
	}
	if (c == 0)
		return (s_copy + j);
	return (0);
}
