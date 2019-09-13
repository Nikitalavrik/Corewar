/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:35:40 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 16:16:38 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lld(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	unsigned char	type;
	int	type_arg1;

	// out_func_info(corewar, cursor, op);
	arg1 = 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	type = (unsigned char)(type << 2) >> 6;
	if ((type_arg1 == DIR_CODE || type_arg1 == IND_CODE) && type == REG_CODE)
	{
		arg1 = check_grep_args(corewar->map, cursor->position + 2,\
										type_arg1, op.t_dirsize);
		cursor->carry = !arg1 ? 1 : cursor->carry;
		arg2 = check_grep_args(corewar->map, cursor->position + 2 +\
				get_val_size(type_arg1, op.t_dirsize), type, op.t_dirsize);
		if (arg2 && arg2 <= 16)
			cursor->reg[arg2 - 1] = type_arg1 == IND_CODE ? cursor->position + 2 +\
					get_val_size(type_arg1, op.t_dirsize) + arg1 : arg1;
	}
	cursor->position += (2 + get_val_size(type_arg1, op.t_dirsize) +\
									get_val_size(type, op.t_dirsize));
	// dump(cursor);
}
