/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:31:09 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/25 20:31:09 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	ft_printf_x_upper(unsigned int x)
{
	char	*base;
	char	memo[9];
	int		i;

	base = "0123456789ABCDEF";
	memo[8] = '\0';
	memo[7] = base[x % 16];
	i = 7;
	while (x >= 16)
	{
		x /= 16;
		memo[--i] = base[x % 16];
	}
	ft_putstr_fd(memo + i, STDOUT_FILENO);
	return (8 - i);
}
