/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:39 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 20:20:27 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_ld(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	if ((type.t_tp.t1 == DIR_CODE || type.t_tp.t1 == IND_CODE)\
						&& type.t_tp.t2 == REG_CODE)
	{
		if (args[1] > 0 && args[1] <= 16)
		{
			cursor->reg[args[1] - 1] = type.t_tp.t1 == IND_CODE ?\
			check_grep_args(corewar->map, place_cur(cursor->position +\
								args[0] % IDX_MOD), DIR_CODE, 0) : args[0];
			cursor->carry = !cursor->reg[args[1] - 1] ? 1 : 0;
		}
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 2, op));
}
