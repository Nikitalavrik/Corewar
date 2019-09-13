/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:08 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 15:31:22 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	unsigned char	type;
	int	type_arg1;

	out_func_info(corewar, cursor, op);
	arg2 = 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	type = (char)(type << 2) >> 6;
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type_arg1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position + 2 + T_REG, type, op.t_dirsize);
	if (type_arg1 == REG_CODE && (type == REG_CODE || type == IND_CODE))
	{
		if (type == REG_CODE && arg1 <= 16 && arg1 && arg2 <= 16 && arg2)
			cursor->reg[arg2 - 1] = cursor->reg[arg1 - 1];
		else if (type == IND_CODE && arg1 && arg1 <= 16)
			corewar->map[cursor->position + arg2 % IDX_MOD] = cursor->reg[arg1];
	}
	cursor->position += (2 + get_val_size(type_arg1, op.t_dirsize) +\
						get_val_size(type, op.t_dirsize));
	// dump(cursor);
}
