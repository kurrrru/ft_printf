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
	int	w;

	ret = 0;
	while (len-- > 0)
	{
		w = write(STDOUT_FILENO, &filler, 1);
		if (w == -1)
			return (-1);
		ret += w;
	}
	return (ret);
}

int	ft_printf_atoi(const char **str)
{
	long	ret;
	long	sign;

	ret = 0L;
	sign = 1L;
	while ((9 <= **str && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+')
		if (**str++ == '-')
			sign = -1L;
	while (ft_isdigit(**str))
	{
		if (ret > LONG_MAX / 10L || (ret == LONG_MAX / 10L && **str > '7'))
			return ((int)LONG_MAX);
		if (ret < LONG_MIN / 10L || (ret == LONG_MIN / 10L && **str > '8'))
			return ((int)LONG_MIN);
		ret = ret * 10L + (*(*str)++ - '0') * sign;
	}
	return ((int)ret);
}

int	sum_arr(int *arr)
{
	int	ret;
	int	n;

	n = 8;
	ret = 0;
	while (n--)
	{
		if (arr[n] < 0)
			return (-1);
		ret += arr[n];
	}
	return (ret);
}
