/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:39 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 16:37:28 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_ld(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int				arg1;
	unsigned char	arg2;
	t_type			type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	if ((type.t_tp.t1 == DIR_CODE || type.t_tp.t1 == IND_CODE)\
												&& type.t_tp.t2 == REG_CODE)
	{
		arg1 = check_grep_args(corewar->map, cursor->position + 2,\
										type.t_tp.t1, op.t_dirsize);
		arg2 = check_grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type.t_tp.t1, op.t_dirsize), type.t_tp.t2, op.t_dirsize);
		if (arg2 && arg2 <= 16)
		{
			cursor->reg[arg2 - 1] = type.t_tp.t1 == IND_CODE ? cursor->position\
		+ 2 + get_val_size(type.t_tp.t1, op.t_dirsize) + arg1 % IDX_MOD : arg1;
			cursor->carry = !cursor->reg[arg2 - 1] ? 1 : 0;
		}
	}
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 2, op));
}
