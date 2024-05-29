/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:26:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/05/28 16:26:26 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

int				ft_printf(const char *format, ...);

int				max(int a, int b);
int				min(int a, int b);
int				ft_printf_atoi(const char **str);
int				fill(char filler, int len);

int				ft_printf_c_with_flag(char c, int flag[]);
int				ft_printf_s_with_flag(char *s, int flag[]);
int				ft_printf_d_with_flag(int d, int flag[]);
int				ft_printf_u_with_flag(unsigned int u, int flag[]);
int				ft_printf_x_with_flag(unsigned int x, int flag[],
					char *base, char *prefix);
// int				ft_printf_p_with_flag(void *p, int flag[]);

typedef enum e_flag_type
{
	f_hash,
	f_plus,
	f_minus,
	f_space,
	f_zero,
	f_width,
	f_prec
}				t_flag_type;

#endif
