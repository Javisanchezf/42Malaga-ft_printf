/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:27:12 by javiersa          #+#    #+#             */
/*   Updated: 2023/03/29 19:22:33 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_showhex(unsigned long nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_showhex(nbr / 16, base);
		ft_showhex(nbr % 16, base);
	}
	else
		ft_printfchar(base[nbr]);
}

static	int	ft_counthex(unsigned long v)
{
	int	i;

	i = 0;
	if (v == 0)
		i++;
	while (v >= 1 && i++ >= 0)
		v = v / 16;
	return (i);
}

int	ft_printfpointer(unsigned long v)
{
	int		i;

	i = 0;
	i = 2;
	write (1, "0x", 2);
	ft_showhex(v, "0123456789abcdef");
	return (ft_counthex(v) + i);
}

int	ft_printfhex(unsigned int v, char type)
{
	int		i;

	i = 0;
	if (type == 'x')
		ft_showhex(v, "0123456789abcdef");
	else if (type == 'X')
		ft_showhex(v, "0123456789ABCDEF");
	return (ft_counthex(v) + i);
}
