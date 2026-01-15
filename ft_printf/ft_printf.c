/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:38:52 by moabed            #+#    #+#             */
/*   Updated: 2025/08/28 21:10:50 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	typesearcher(va_list *args, char type, int *ssize)
{
	if (type == 'c')
		*ssize += ft_printchar(va_arg(*args, int));
	if (type == 's')
		*ssize += ft_printstr(va_arg(*args, char *));
	if (type == 'i' || type == 'd')
		*ssize += ft_printnbr(va_arg(*args, int));
	if (type == 'X')
		*ssize += ft_printhex(va_arg(*args, unsigned int));
	if (type == 'x')
		*ssize += ft_printshex(va_arg(*args, unsigned int));
	if (type == 'u')
		*ssize += ft_printudecimal(va_arg(*args, unsigned int));
	if (type == 'p')
		*ssize += ft_printptr(va_arg(*args, void *));
}

int	ft_printf(const char *s, ...)
{
	int		ssize;
	va_list	args;

	va_start(args, s);
	ssize = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				ssize += write(1, "%", 1);
			}
			else
				typesearcher(&args, *s, &ssize);
		}
		else
			ssize += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (ssize);
}
