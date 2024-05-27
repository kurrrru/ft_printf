/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:55:49 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/26 01:55:49 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	ft_printf_u(unsigned int u)
{
	char	memo[11];
	int		i;

	memo[10] = '\0';
	memo[9] = u % 10 + '0';
	i = 9;
	while (u >= 10)
	{
		u /= 10;
		memo[--i] = u % 10 + '0';
	}
	ft_putstr_fd(memo + i, STDOUT_FILENO);
	return (10 - i);
}
