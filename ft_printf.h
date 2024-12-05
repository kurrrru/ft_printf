/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:29:53 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/07 19:29:53 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# if defined(__GNUC__) || defined(__clang__)
#  define PRINTF_ATTRIBUTE(a, b) __attribute__((format(printf, a, b)))
# else
#  define PRINTF_ATTRIBUTE(a, b)
# endif

int	ft_printf_c(char c);
int	ft_printf_s(char *s);
int	ft_printf_d(int d);
int	ft_printf_u(unsigned int u);
int	ft_printf_x(unsigned int x);
int	ft_printf_x_upper(unsigned int x);
int	ft_printf_p(void *p);
int	ft_printf(const char *format, ...) PRINTF_ATTRIBUTE(1, 2);

#endif
