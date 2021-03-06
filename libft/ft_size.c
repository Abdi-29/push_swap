/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_size.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/18 22:17:30 by abba           #+#    #+#                */
/*   Updated: 2022/01/18 22:17:31 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

int	ft_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	while (n != 0)
	{
		if (n / 10 != 0)
		{
			n /= 10;
			len++;
		}
		else
		{
			n %= 10;
			n = 0;
			len++;
		}
	}
	return (len);
}
