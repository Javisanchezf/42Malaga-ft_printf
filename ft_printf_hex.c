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

static void	ft_showhexint(unsigned int nbr, char *base)
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

static	int	ft_counthexint(unsigned int v)
{
	int	i;

	i = 0;
	if (v == 0)
		i++;
	while (v >= 1 && i++ >= 0)
		v = v / 16;
	return (i);
}

int	ft_printfhex(void *v, char type)
{
	int		i;

	i = 0;
	if (type == 'p')
	{
		i = 2;
		write (1, "0x", 2);
		ft_showhex((unsigned long)v, "0123456789abcdef");
		return (ft_counthex((unsigned long)v) + i);
	}
	if (type == 'x')
		ft_showhexint((unsigned int)v, "0123456789abcdef");
	else if (type == 'X')
		ft_showhexint((unsigned int)v, "0123456789ABCDEF");
	return (ft_counthexint((unsigned int)v) + i);
}
