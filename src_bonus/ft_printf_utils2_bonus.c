/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:07:20 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/06/30 19:18:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	mw(char *c, int size, int *ret)
{
	if (sum_arr(ret) < 0)
		return (-1);
	return (write(STDOUT_FILENO, c, size));
}

int	mf(char filler, int len, int *ret)
{
	if (sum_arr(ret) < 0)
		return (-1);
	return (fill(filler, len));
}
