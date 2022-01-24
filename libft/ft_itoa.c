/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_itoa.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/18 22:09:23 by abba           #+#    #+#                */
/*   Updated: 2022/01/18 22:09:25 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_positive(int len, int n)
{
	char	*s;
	int		i;

	i = len;
	s = malloc(len * sizeof(char) + 1);
	if (s == 0)
		return (0);
	len -= 1;
	while (len > -1)
	{
		s[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_negative(int len, int n)
{
	char		*s;
	int			i;
	long long	neg;

	i = len + 1;
	s = malloc((len + 1) * sizeof(char) + 1);
	if (s == 0)
		return (0);
	neg = (long long)n;
	neg *= -1;
	while (len > 0)
	{
		s[len] = neg % 10 + '0';
		neg /= 10;
		len--;
	}
	s[0] = '-';
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_size(n);
	if (n < 0)
	{
		s = ft_negative(len, n);
	}
	else
	{
		s = ft_positive(len, n);
	}
	return (s);
}
