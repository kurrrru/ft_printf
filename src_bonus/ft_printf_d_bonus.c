/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:04:54 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/28 22:04:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

// ft_printf_d: convert the integer d to a string
// return: the number of characters without the sign
int	ft_printf_d(int d, char memo[12], int prec)
{
	int		i;
	int		sign;

	if (prec == 0 && d == 0)
		return (ft_bzero(memo, 12), 0);
	sign = (d >= 0) * 2 - 1;
	memo[11] = '\0';
	memo[10] = d % 10 * sign + '0';
	i = 10;
	while (d <= -10 || d >= 10)
	{
		d /= 10;
		memo[--i] = d % 10 * sign + '0';
	}
	return (11 - i);
}

// ft_printf_d_with_flag: output the integer d with the flag
// flag[0]: '#' (not used)
// flag[1]: '+'
// flag[2]: '-'
// flag[3]: ' '
// flag[4]: '0'
// flag[5]: field width
// flag[6]: precision
// return: the number of characters printed
int	ft_printf_d_with_flag(int d, int flag[])
{
	char	memo[12];
	int		ret[8];
	int		d_len;
	int		sign;

	ft_memset(ret, 0, sizeof(ret));
	d_len = ft_printf_d(d, memo, flag[f_prec]);
	sign = (d < 0) | (flag[f_plus] == 1) | (flag[f_space] == 1);
	if ((flag[f_minus] == 0) && ((flag[f_prec] != -1) || (flag[f_zero] == 0)))
		ret[0] = fill(' ', flag[f_width] - max(d_len, flag[f_prec]) - sign);
	if (d < 0)
		ret[1] = fill('-', 1);
	else if (d >= 0 && flag[f_plus] == 1)
		ret[2] = fill('+', 1);
	else if (d >= 0 && flag[f_plus] == 0 && flag[f_space] == 1)
		ret[3] = fill(' ', 1);
	if ((flag[f_minus] == 0) && (flag[f_prec] == -1) && (flag[f_zero] == 1))
		ret[4] = fill('0', flag[f_width] - max(d_len, flag[f_prec]) - sign);
	ret[5] = fill('0', max(0, flag[f_prec] - d_len));
	ret[6] = write(STDOUT_FILENO, memo + 11 - d_len, d_len);
	if (flag[f_minus] == 1)
		ret[7] = fill(' ', flag[f_width] - max(d_len, flag[f_prec]) - sign);
	return (sum_arr(ret, 8));
}
