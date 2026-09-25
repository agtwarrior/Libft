/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <davguerr@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:09:27 by david             #+#    #+#             */
/*   Updated: 2026/09/25 13:16:45 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = num * -1;
	}
	if (num >= 10)
	{
		c = num % 10 + '0';
		num = num / 10;
		ft_putnbr_fd(num, fd);
	}
	else
		c = num + '0';
	write(fd, &c, 1);
}
