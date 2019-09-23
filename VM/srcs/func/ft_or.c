/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:33:10 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 15:24:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		or_foo(int num1, int num2)
{
	return (num1 | num2);
}

void	ft_or(t_cw *corewar, t_cursor *cursor, t_op op)
{
	 ft_and_xor_or(corewar, cursor, op, or_foo);
}
