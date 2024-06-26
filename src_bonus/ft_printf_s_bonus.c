/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:31:04 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/29 02:31:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_printf_s_with_flag(char *s, int flag[])
{
	int	len;
	int	ret[8];

	ft_memset(ret, 0, sizeof(ret));
	if (flag[f_prec] == -1)
		flag[f_prec] = INT_MAX;
	if (!s)
		return (ft_printf_s_with_flag("(null)", flag));
	len = ft_strlen(s);
	if (flag[f_minus] == 0 && (flag[f_width] >= flag[f_prec]
			|| flag[f_width] >= len))
		ret[0] = mf(' ', flag[f_width] - min(len, flag[f_prec]), ret);
	ret[1] = mw(s, min(len, flag[f_prec]), ret);
	if (flag[f_minus] == 1 && (flag[f_width] >= flag[f_prec]
			|| flag[f_width] >= len))
		ret[2] = mf(' ', flag[f_width] - min(len, flag[f_prec]), ret);
	return (sum_arr(ret));
}
