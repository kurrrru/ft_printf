/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:49:42 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/29 16:49:42 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

// ft_printf_p: convert a pointer to a string and print it
// just convert, not print
// return: the length of the string
static int	ft_printf_p(void *p, char memo[17])
{
	unsigned long	ul;
	char			*base;
	int				i;

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
	return (16 - i);
}

// ft_printf_p_with_flag: print a pointer with flags
// return: the length of the string
int	ft_printf_p_with_flag(void *p, int flag[])
{
	char	memo[17];
	int		ret;
	int		p_len;

	p_len = ft_printf_p(p, memo);
	ret = p_len;
	if (flag[f_minus] == 0)
		ret += fill(' ', flag[f_width] - p_len - 2);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(memo + 16 - p_len, STDOUT_FILENO);
	if (flag[f_minus] == 1)
		ret += fill(' ', flag[f_width] - p_len - 2);
	return (ret + 2);
}
