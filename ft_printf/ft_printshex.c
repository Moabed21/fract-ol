/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printshex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:47:57 by moabed            #+#    #+#             */
/*   Updated: 2025/08/28 21:11:52 by moabed           ###   ########.fr       */
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

int	ft_printshex(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_printshex(nb / 16);
	hexfinder(nb % 16);
	return (count + 1);
}
