/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:55:57 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	fill(char filler, int len)
{
	int	ret;

	ret = len;
	while (len-- > 0)
		ft_putchar_fd(filler, STDOUT_FILENO);
	return (max(0, ret));
}

int	ft_printf_atoi(const char **str)
{
	long	ret;
	long	sign;

	ret = 0l;
	sign = 1l;
	while ((9 <= **str && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
		if (**str++ == '-')
			sign = -1l;
	while (ft_isdigit(**str))
	{
		if (ret > LONG_MAX / 10 || (ret == LONG_MAX / 10 && **str > '7'))
			return ((int)LONG_MAX);
		if (ret < LONG_MIN / 10 || (ret == LONG_MIN / 10 && **str > '8'))
			return ((int)LONG_MIN);
		ret = ret * 10l + (*(*str)++ - '0') * sign;
	}
	return ((int)ret);
}
