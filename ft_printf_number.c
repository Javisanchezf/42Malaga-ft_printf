/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:43:31 by javiersa          #+#    #+#             */
/*   Updated: 2022/12/19 16:30:24 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_shownbr(long n)
{
	if (n < 0)
	{
		ft_printfchar('-');
		ft_shownbr(n * -1);
	}
	else if (n > 9)
	{
		ft_shownbr(n / 10);
		ft_shownbr(n % 10);
	}
	else
		ft_printfchar(n + '0');
}

int	ft_printfnbr(int n)
{
	int	i;

	if (n == 0)
		return (ft_printfchar('0'));
	ft_shownbr(n);
	i = 0;
	if (n < 0)
	{
		n = n * -0.1;
		i += 2;
	}
	while (n >= 1 && i++ >= 0)
		n = n / 10;
	return (i);
}

int	ft_printfunsnbr(unsigned int n)
{
	int	i;

	if (n == 0)
		return (ft_printfchar('0'));
	ft_shownbr(n);
	i = 0;
	while (n >= 1 && i++ >= 0)
		n = n / 10;
	return (i);
}
