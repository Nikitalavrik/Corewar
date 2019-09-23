/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:30:24 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 15:35:07 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		add_foo(int num1, int num2)
{
	return (num1 + num2);
}

void	ft_add(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_add_sub(corewar, cursor, op, add_foo);
}