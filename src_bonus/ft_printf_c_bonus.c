/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:02:52 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/29 01:02:52 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_printf_c_with_flag(char c, int flag[])
{
	int	ret[8];

	ft_memset(ret, 0, sizeof(ret));
	if (flag[f_minus] == 0)
		ret[0] = mf(' ', flag[f_width] - 1, ret);
	ret[1] = mw(&c, 1, ret);
	if (flag[f_minus] == 1)
		ret[2] = mf(' ', flag[f_width] - 1, ret);
	return (sum_arr(ret));
}
