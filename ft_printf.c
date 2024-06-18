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

static int	ft_printf_sub(const char *format, va_list ap, int *ret)
{
	int	w;

	w = 0;
	if (*format == 'd' || *format == 'i')
		w = ft_printf_d(va_arg(ap, int));
	else if (*format == 's')
		w = ft_printf_s(va_arg(ap, char *));
	else if (*format == 'c')
		w = ft_printf_c(va_arg(ap, int));
	else if (*format == 'u')
		w = ft_printf_u(va_arg(ap, unsigned int));
	else if (*format == 'x')
		w = ft_printf_x(va_arg(ap, unsigned int));
	else if (*format == 'X')
		w = ft_printf_x_upper(va_arg(ap, unsigned int));
	else if (*format == 'p')
		w = ft_printf_p(va_arg(ap, void *));
	else if (*format == '%')
		w = ft_printf_c('%');
	if (w < 0)
		return (-1);
	*ret += w;
	return (0);
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
		if (*format != '%')
		{
			if (write(STDOUT_FILENO, format, 1) < 0)
				return (-1);
			ret += 1;
		}
		else if (ft_printf_sub(++format, ap, &ret) < 0)
			return (-1);
		format++;
	}
	va_end(ap);
	return (ret);
}
