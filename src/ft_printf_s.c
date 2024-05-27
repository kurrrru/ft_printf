/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:01:21 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/25 20:01:21 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	ft_printf_s(char *s)
{
	if (!s)
		return (ft_printf_s("(null)"));
	ft_putstr_fd(s, STDOUT_FILENO);
	return (ft_strlen(s));
}
