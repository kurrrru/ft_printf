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
	char			memo[17];
	char			*base;
	int				i;

	if (!p)
		return (ft_printf_s("(nil)"));
	ul = (unsigned long)p;
	base = "0123456789abcdef";
	memo[16] = '\0';
	memo[15] = base[ul % 16];
	i = 15;
	while (ul >= 16)
	{
		ul /= 16;
		memo[--i] = base[ul % 16];
	}
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(memo + i, STDOUT_FILENO);
	return (18 - i);
}
