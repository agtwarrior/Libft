/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:47:03 by david             #+#    #+#             */
/*   Updated: 2026/09/24 12:58:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	neg;

	i = 0;
	neg = 0;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-r);
	return (r);
}
