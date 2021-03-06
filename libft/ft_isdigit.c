/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isdigit.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: abba <abba@student.codam.nl>                  +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/18 22:19:15 by abba           #+#    #+#                */
/*   Updated: 2022/01/18 22:19:17 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
