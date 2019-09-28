/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:36:11 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/28 13:13:29 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_ldi(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t1 == REG_CODE && args[0] > 0 && args[0] <= 16)
		args[0] = cursor->reg[args[0] - 1];
	else if (type.t_tp.t1 == IND_CODE)
		args[0] = check_grep_args(corewar->map, cursor->position\
								+ args[0] % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t2 == REG_CODE && args[1] && args[1] <= 16)
		args[1] = cursor->reg[args[1] - 1];
	if (type.t_tp.t3 == REG_CODE && type.t_tp.t1 && type.t_tp.t2\
												&& type.t_tp.t2 != IND_CODE)
	{
		if (args[2] > 0 && args[2] <= 16)
		{
			cursor->reg[args[2] - 1] = check_grep_args(corewar->map, cursor->position +\
									(args[0] + args[1]) % IDX_MOD, DIR_CODE, 0);
			cursor->carry = !cursor->reg[args[2] - 1] ? 1 : 0;
		}
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}
