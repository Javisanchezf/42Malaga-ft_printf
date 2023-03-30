/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:06:39 by javiersa          #+#    #+#             */
/*   Updated: 2022/12/20 18:05:52 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(const char *type, va_list args)
{
	int	i;

	i = 0;
	if (*type == 'c')
		i += ft_printfchar(va_arg(args, int));
	else if (*type == 's')
		i += ft_printfstring(va_arg(args, char *));
	else if (*type == 'd' || *type == 'i')
		i += ft_printfnbr(va_arg(args, int));
	else if (*type == 'u')
		i += ft_printfunsnbr(va_arg(args, int));
	else if (*type == 'p')
		i += ft_printfpointer(va_arg(args, unsigned long));
	else if (*type == 'x' || *type == 'X')
		i += ft_printfhex(va_arg(args, int), *type);
	else if (*type != 0)
		i += ft_printfchar((char)type[0]);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		printf_len;

	if (write(1, "", 0) == -1)
		return (-1);
	printf_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printf_len += ft_checkformat(str, args);
		}
		else
			printf_len += ft_printfchar(*str);
		if (*str)
			str++;
	}
	va_end(args);
	return (printf_len);
}
