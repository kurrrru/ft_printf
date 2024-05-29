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

int	ft_printf_x(unsigned int x, char memo[9], char *base)
{
	int		i;

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
	int		ret;
	int		x_len;
	int		pre_len;

	x_len = ft_printf_x(x, memo, base);
	ret = x_len;
	pre_len = (x != 0 && flag[f_hash]) * 2;
	if ((flag[f_minus] == 0) && ((flag[f_prec] != -1) || (flag[f_zero] == 0)))
		ret += fill(' ', flag[f_width] - max(x_len, flag[f_prec]) - pre_len);
	if (x != 0 && flag[f_hash])
		ret += write(1, prefix, 2);
	if ((flag[f_minus] == 0) && (flag[f_prec] == -1) && (flag[f_zero] == 1))
		ret += fill('0', flag[f_width] - max(x_len, flag[f_prec]) - pre_len);
	ret += fill('0', max(0, flag[f_prec] - x_len));
	ft_putstr_fd(memo + 8 - x_len, STDOUT_FILENO);
	if (flag[f_minus] == 1)
		ret += fill(' ', flag[f_width] - max(x_len, flag[f_prec]) - pre_len);
	return (ret);
}
