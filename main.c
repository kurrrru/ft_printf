/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 00:06:57 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/06/03 00:06:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int main()
{
	int	ret;

	ret = printf("[%5%]");
	printf("\n");
	printf("ret = %d\n", ret);
	ret = ft_printf("[%5%]");
	printf("\n");
	printf("ret = %d\n", ret);
}
