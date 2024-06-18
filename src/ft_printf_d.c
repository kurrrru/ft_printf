/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:16:37 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/25 20:16:37 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	ft_printf_d(int d)
{
	char	memo[12];
	int		i;
	int		sign;

	sign = (d >= 0) * 2 - 1;
	ft_memset(memo, '-', 10);
	memo[11] = '\0';
	memo[10] = d % 10 * sign + '0';
	i = 10;
	while (d <= -10 || d >= 10)
	{
		d /= 10;
		memo[--i] = d % 10 * sign + '0';
	}
	return (write(STDOUT_FILENO, memo + i - (d < 0), 11 - i + (d < 0)));
}
