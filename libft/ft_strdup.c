/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/18 22:09:49 by abba           #+#    #+#                */
/*   Updated: 2022/01/18 22:09:51 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_copy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	s_copy = (char *)malloc(len * sizeof(char) + 1);
	if (s_copy == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
