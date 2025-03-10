/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:02:43 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/04 04:19:49 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	long	nb1;

	nb1 = n;
	if (nb1 < 0)
	{
		*len += write(1, "-", 1);
		nb1 *= -1;
	}
	if (nb1 < 10)
	{
		nb1 += 48;
		*len += write (1, &nb1, 1);
	}
	else
	{
		ft_putnbr(nb1 / 10, len);
		ft_putnbr(nb1 % 10, len);
	}
}
