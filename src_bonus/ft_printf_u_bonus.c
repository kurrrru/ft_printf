/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:02:37 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/29 01:02:37 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	ft_printf_u(unsigned int u, char memo[12], int prec)
{
	int		i;

	if (prec == 0 && u == 0)
		return (ft_bzero(memo, 12), 0);
	memo[11] = '\0';
	memo[10] = u % 10 + '0';
	i = 10;
	while (u >= 10)
	{
		u /= 10;
		memo[--i] = u % 10 + '0';
	}
	return (11 - i);
}

// ft_printf_u_with_flag: output the unsigned integer u with the flag
// flag[0]: '#' (not used)
// flag[1]: '+' (not used)
// flag[2]: '-'
// flag[3]: ' ' (not used)
// flag[4]: '0'
// flag[5]: field width
// flag[6]: precision
// return: the number of characters printed
int	ft_printf_u_with_flag(unsigned int u, int flag[])
{
	char	memo[12];
	int		ret;
	int		u_len;

	u_len = ft_printf_u(u, memo, flag[f_prec]);
	ret = u_len;
	if ((flag[f_minus] == 0) && ((flag[f_prec] != -1) || (flag[f_zero] == 0)))
		ret += fill(' ', flag[f_width] - max(u_len, flag[f_prec]));
	if ((flag[f_minus] == 0) && (flag[f_prec] == -1) && (flag[f_zero] == 1))
		ret += fill('0', flag[f_width] - max(u_len, flag[f_prec]));
	ret += fill('0', max(0, flag[f_prec] - u_len));
	ft_putstr_fd(memo + 11 - u_len, STDOUT_FILENO);
	if (flag[f_minus] == 1)
		ret += fill(' ', flag[f_width] - max(u_len, flag[f_prec]));
	return (ret);
}
