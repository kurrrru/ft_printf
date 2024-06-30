/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinrf_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:31:37 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/29 15:31:37 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_printf_x(unsigned int x, char memo[9], char *base, int prec)
{
	int		i;

	if (prec == 0 && x == 0)
		return (ft_bzero(memo, 9), 0);
	memo[8] = '\0';
	memo[7] = base[x % 16];
	i = 7;
	while (x >= 16)
	{
		x /= 16;
		memo[--i] = base[x % 16];
	}
	return (8 - i);
}

int	ft_printf_x_with_flag(unsigned int x, int flag[], char *base, char *prefix)
{
	char	memo[9];
	int		ret[8];
	int		x_len;
	int		pre_len;

	ft_memset(ret, 0, sizeof(ret));
	x_len = ft_printf_x(x, memo, base, flag[f_prec]);
	pre_len = (x != 0 && flag[f_hash]) * 2;
	if ((flag[f_minus] == 0) && ((flag[f_prec] != -1) || (flag[f_zero] == 0)))
		ret[0] = mf(' ', flag[f_width] - max(x_len, flag[f_prec]) - pre_len,
				ret);
	if (x != 0 && flag[f_hash])
		ret[1] = mw(prefix, 2, ret);
	if ((flag[f_minus] == 0) && (flag[f_prec] == -1) && (flag[f_zero] == 1))
		ret[2] = mf('0', flag[f_width] - max(x_len, flag[f_prec]) - pre_len,
				ret);
	ret[3] = mf('0', max(0, flag[f_prec] - x_len), ret);
	ret[4] = mw(memo + 8 - x_len, x_len, ret);
	if (flag[f_minus] == 1)
		ret[5] = mf(' ', flag[f_width] - max(x_len, flag[f_prec]) - pre_len,
				ret);
	return (sum_arr(ret));
}
