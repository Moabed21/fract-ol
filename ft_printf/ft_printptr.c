/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:35 by moabed            #+#    #+#             */
/*   Updated: 2025/08/28 21:11:13 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hexfinder(unsigned long x)
{
	char	y;

	if (x <= 9)
	{
		y = x + '0';
		write(1, &y, 1);
	}
	if (x == 10)
		write(1, "a", 1);
	if (x == 11)
		write(1, "b", 1);
	if (x == 12)
		write(1, "c", 1);
	if (x == 13)
		write(1, "d", 1);
	if (x == 14)
		write(1, "e", 1);
	if (x == 15)
		write(1, "f", 1);
}

static int	printaddr(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += printaddr(nb / 16);
	hexfinder(nb % 16);
	return (count + 1);
}

int	ft_printptr(void *p)
{
	unsigned long	address;
	int				count;

	count = 0;
	address = (unsigned long)p;
	if (address == 0)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += write(1, "0x", 2);
		count += printaddr(address);
	}
	return (count);
}
