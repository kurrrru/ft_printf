/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:08:57 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/28 20:08:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	select_op(const char *format, va_list ap, int flag_cnt[], int *ret)
{
	if (*format == 'd' || *format == 'i')
		*ret += ft_printf_d_with_flag(va_arg(ap, int), flag_cnt);
	else if (*format == 's')
		*ret += ft_printf_s_with_flag(va_arg(ap, char *), flag_cnt);
	else if (*format == 'c')
		*ret += ft_printf_c_with_flag(va_arg(ap, int), flag_cnt);
	else if (*format == 'u')
		*ret += ft_printf_u_with_flag(va_arg(ap, unsigned int), flag_cnt);
	else if (*format == 'x')
		*ret += ft_printf_x_with_flag(va_arg(ap, unsigned int), flag_cnt,
				"0123456789abcdef", "0x");
	else if (*format == 'X')
		*ret += ft_printf_x_with_flag(va_arg(ap, unsigned int), flag_cnt,
				"0123456789ABCDEF", "0X");
	else if (*format == 'p')
	{
		*ret += ft_printf_p_with_flag(va_arg(ap, void *), flag_cnt);
	}
	else if (*format == '%')
		*ret += write(STDOUT_FILENO, "%", 1);
}

// ft_printf_flagcnt: sub function for ft_printf
// analyze the format string and call the corresponding function
// format[flag_len]: conversion specifier
// flags[0]: '#'
// flags[1]: '+'
// flags[2]: '-'
// flags[3]: ' '
// flags[4]: '0'
// flags[5]: field width
// flags[6]: precision
static void	ft_printf_flagcnt(const char *format, va_list ap, int *ret,
		int flag_len)
{
	int	flag_cnt[7];

	ft_memset(flag_cnt, 0, sizeof(flag_cnt));
	flag_cnt[f_prec] = -1;
	while (*(++format) && --flag_len && (*format < '1' || *format > '9'))
	{
		if (*format == '#')
			flag_cnt[f_hash] = 1;
		else if (*format == '+')
			flag_cnt[f_plus] = 1;
		else if (*format == '-')
			flag_cnt[f_minus] = 1;
		else if (*format == ' ')
			flag_cnt[f_space] = 1;
		else if (*format == '0')
			flag_cnt[f_zero] = 1;
	}
	if (*format >= '1' && *format <= '9')
		flag_cnt[f_width] = ft_printf_atoi(&format);
	if (*format == '.')
	{
		format++;
		flag_cnt[f_prec] = ft_printf_atoi(&format);
	}
	select_op(format, ap, flag_cnt, ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		flag_len;

	if (!format)
		return (-1);
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			flag_len = 1;
			while (!ft_strrchr("cspdiuxX%%", format[flag_len]))
				flag_len++;
			ft_printf_flagcnt(format, ap, &ret, flag_len);
			format += flag_len;
		}
		else
			ret += write(STDOUT_FILENO, format, 1);
		format++;
	}
	va_end(ap);
	return (ret);
}

// int main(void)
// {
// 	int ret;

// 	ret = ft_printf("%d\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("%d\n", -123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("%d\n", 0);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5d]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5d]\n", -123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5d]\n", 0);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-5d]\n", -123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 5d]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 05d]\n", -123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+5d]\n", 0);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+10.5d]\n", 123);
// 	ft_printf("ret = %d\n", ret);

// 	// test for s
// 	ret = ft_printf("%s\n", "Hello, world!");
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%20s]\n", "Hello, world!");
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-20s]\n", "Hello, world!");
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%20.5s]\n", "Hello, world!");	
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%20.15s]\n", "Hello, world!");
// 	ft_printf("ret = %d\n", ret);

// 	// test for c
// 	ret = ft_printf("%c\n", 'A');
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5c]\n", 'A');
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-5c]\n", 'A');
// 	ft_printf("ret = %d\n", ret);

// 	// test for u
// 	ret = ft_printf("%u\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5u]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-5u]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 5u]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 05u]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+5u]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+10.5u]\n", 123);
// 	ft_printf("ret = %d\n", ret);

// 	// test for x
// 	ret = ft_printf("%x\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 05x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+10.5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#10.5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#-10.5x]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#010x]\n", 0);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#010x]\n", 123);
// 	ft_printf("ret = %d\n", ret);

// 	// test for X
// 	ret = ft_printf("%X\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 05X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+10.5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#10.5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#-10.5X]\n", 123);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#010X]\n", 0);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#010X]\n", 123);
// 	ft_printf("ret = %d\n", ret);

// 	// test for p
// 	ret = ft_printf("%p\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%-5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[% 05p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%+10.5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#10.5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#-10.5p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#010p]\n", &ret);
// 	ft_printf("ret = %d\n", ret);
// 	ret = ft_printf("[%#10p]\n", NULL);
// 	ft_printf("ret = %d\n", ret);

// 	// // test for %%
// 	// printf("%%\n");
// 	// ret = ft_printf("%%\n");
// 	// ft_printf("ret = %d\n", ret);
// 	// printf("[%5%]\n");
// 	// ret = ft_printf("[%5%]\n");
// 	// ft_printf("ret = %d\n", ret);
// 	// printf("[%-5%]\n");
// 	// ret = ft_printf("[%-5%]\n");
// 	// ft_printf("ret = %d\n", ret);
// 	// printf("[%-05%]\n");
// 	// ret = ft_printf("[%-05%]\n");
// 	// ft_printf("ret = %d\n", ret);
// }
