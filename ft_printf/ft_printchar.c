/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:21 by moabed            #+#    #+#             */
/*   Updated: 2025/08/28 21:10:41 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char x)
{
	return (write(1, &x, 1));
}
// int sum(int count, ...)
// {
// 	va_list args;
// 	int	x = 0;

// 	va_start(args,count);
// 	int i =0;
// 	while (i < count)
// 	{
// 		int num = va_arg(args, int);
// 		x+=num ;
// 		i++;
// 	}
// 	va_end(args);
// 	return(x);
// }
// int	main(void)
// {
// 	printf("%d ", sum(2,1,2,3));
// }