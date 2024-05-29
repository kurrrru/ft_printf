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
	if (flag[f_minus] == 0)
		fill(' ', flag[f_width] - 1);
	write(1, &c, 1);
	if (flag[f_minus] == 1)
		fill(' ', flag[f_width] - 1);
	return (max(1, flag[f_width]));
}
