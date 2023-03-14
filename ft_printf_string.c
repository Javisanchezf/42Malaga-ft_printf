/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:28:50 by javiersa          #+#    #+#             */
/*   Updated: 2022/12/19 16:30:28 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfchar(char c)
{
	write (1, &c, sizeof(char));
	return (1);
}

int	ft_printfstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printfstring("(null)"));
	while (s[i])
		i += ft_printfchar(s[i]);
	return (i);
}
