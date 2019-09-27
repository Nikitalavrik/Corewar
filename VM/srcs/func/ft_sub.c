/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:32:28 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 15:36:04 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		sub_foo(int num1, int num2)
{
	return (num1 - num2);
}

void	ft_sub(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_add_sub(corewar, cursor, op, sub_foo);
}
