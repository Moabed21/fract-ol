/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:31 by moabed            #+#    #+#             */
/*   Updated: 2025/08/28 21:10:58 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hexfinder(int x)
{
	char	y;

	if (x >= 0 && x <= 9)
	{
		y = x + '0';
		write(1, &y, 1);
	}
	if (x == 10)
		write(1, "A", 1);
	if (x == 11)
		write(1, "B", 1);
	if (x == 12)
		write(1, "C", 1);
	if (x == 13)
		write(1, "D", 1);
	if (x == 14)
		write(1, "E", 1);
	if (x == 15)
		write(1, "F", 1);
}

int	ft_printhex(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_printhex(nb / 16);
	hexfinder(nb % 16);
	return (count + 1);
}
