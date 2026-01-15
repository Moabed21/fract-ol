/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:38:57 by moabed            #+#    #+#             */
/*   Updated: 2025/08/28 23:34:48 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printchar(char x);
int	ft_printstr(char *p);
int	ft_printnbr(int nb);
int	ft_printhex(unsigned int nb);
int	ft_printshex(unsigned int nb);
int	ft_printudecimal(unsigned int nb);
int	ft_printptr(void *p);
int	ft_printf(const char *s, ...);

#endif