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
	int	i;

	if (flag[f_prec] == -1)
		flag[f_prec] = INT_MAX;
	if (!s && flag[f_prec] >= 6)
		return (ft_printf_s_with_flag("(null)", flag));
	else if (!s)
		return (ft_printf_s_with_flag("", flag));
	len = ft_strlen(s);
	if (flag[f_plus] == 0 && (flag[f_width] >= flag[f_prec] || flag[f_width] >= len))
		fill(' ', flag[f_width] - min(len, flag[f_prec]));
	write(1, s, min(len, flag[f_prec]));
	if (flag[f_plus] == 1 && (flag[f_width] >= flag[f_prec] || flag[f_width] >= len))
		fill(' ', flag[f_width] - min(len, flag[f_prec]));
	return (max(flag[f_width], min(len, flag[f_prec])));
}