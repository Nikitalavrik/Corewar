/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:29 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 15:50:37 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lldi(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	unsigned char	arg3;
	t_type			type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type.t_tp.t1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position +\
		get_val_size(type.t_tp.t1, op.t_dirsize), type.t_tp.t2, op.t_dirsize);
	if (type.t_tp.t1 == REG_CODE && arg1 && arg1 <= 16)
		arg1 = cursor->reg[arg1 - 1];
	else if (type.t_tp.t1 == IND_CODE)
		arg1 = check_grep_args(corewar->map, cursor->position + 2\
											+ arg1 % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t2 == REG_CODE && arg2 && arg2 <= 16)
		arg2 = cursor->reg[arg2 - 1];

	if (type.t_tp.t3 == REG_CODE && type.t_tp.t1 && type.t_tp.t2 && type.t_tp.t2 != IND_CODE)
	{
		arg3 = grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type.t_tp.t1, op.t_dirsize) +\
		get_val_size(type.t_tp.t2, op.t_dirsize), T_REG);
		cursor->reg[arg3 - 1] = (arg1 + arg2);
		cursor->carry = !cursor->reg[arg3 - 1] ? 1 : 0;
	}
	cursor->position = place_cur(cursor->position + 2 +\
	get_val_size(type.t_tp.t1, op.t_dirsize) +\
	get_val_size(type.t_tp.t2, op.t_dirsize) +\
	get_val_size(type.t_tp.t3, op.t_dirsize));
}
