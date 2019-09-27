/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:29 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/27 16:08:40 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lldi(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t1 == REG_CODE && args[0] > 0 && args[0] <= 16)
		args[0] = cursor->reg[args[0] - 1];
	else if (type.t_tp.t1 == IND_CODE)
		args[0] = check_grep_args(corewar->map, cursor->position + 2\
								+ args[0] % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t2 == REG_CODE && args[1] > 0 && args[1] <= 16)
		args[1] = cursor->reg[args[1] - 1];
	if (type.t_tp.t3 == REG_CODE && type.t_tp.t1 &&\
								type.t_tp.t2 && type.t_tp.t2 != IND_CODE)
	{
		cursor->reg[args[2] - 1] = (args[0] + args[1]);
		cursor->carry = !cursor->reg[args[2] - 1] ? 1 : 0;
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}
