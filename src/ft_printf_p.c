/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:58:45 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/26 01:58:45 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	ft_printf_p(void *p)
{
	unsigned long	ul;
	char			memo[19];
	char			*base;
	int				i;

	ul = (unsigned long)p;
	base = "0123456789abcdef";
	memo[18] = '\0';
	memo[17] = base[ul % 16];
	i = 17;
	while (ul >= 16)
	{
		ul /= 16;
		memo[--i] = base[ul % 16];
	}
	memo[--i] = 'x';
	memo[--i] = '0';
	return (write(STDOUT_FILENO, memo + i, 18 - i));
}
