/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:28:46 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/07 19:28:46 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_printf_sub(const char *format, va_list ap, int *ret)
{
	if (*format == 'd' || *format == 'i')
		*ret += ft_printf_d(va_arg(ap, int));
	else if (*format == 's')
		*ret += ft_printf_s(va_arg(ap, char *));
	else if (*format == 'c')
		*ret += ft_printf_c(va_arg(ap, int));
	else if (*format == 'u')
		*ret += ft_printf_u(va_arg(ap, unsigned int));
	else if (*format == 'x')
		*ret += ft_printf_x(va_arg(ap, unsigned int));
	else if (*format == 'X')
		*ret += ft_printf_x_upper(va_arg(ap, unsigned int));
	else if (*format == 'p')
		*ret += ft_printf_p(va_arg(ap, void *));
	else if (*format == '%')
		*ret += ft_printf_c('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (!format)
		return (-1);
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_printf_sub(++format, ap, &ret);
		else
			ret += ft_printf_c(*format);
		format++;
	}
	va_end(ap);
	return (ret);
}
