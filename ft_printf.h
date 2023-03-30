/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:52:58 by javiersa          #+#    #+#             */
/*   Updated: 2022/12/19 21:51:23 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_printfchar(char c);
int	ft_printfstring(char *s);
int	ft_printfnbr(int n);
int	ft_printfunsnbr(unsigned int n);
int	ft_printfhex(unsigned int v, char type);
int	ft_printfpointer(unsigned long v);

#endif