/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:52 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 18:20:34 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	unsigned char	arg3;
	unsigned char	type_arg1;
	unsigned char	type_arg2;
	unsigned char	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	type_arg2 = (unsigned char)(type << 2) >> 6;
	type = (unsigned char)(type << 4) >> 6;
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type_arg1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position + 2 + \
					get_val_size(type_arg1, op.t_dirsize), type_arg2, op.t_dirsize);
	arg3 = check_grep_args(corewar->map, cursor->position + 2 +\
						get_val_size(type_arg1, op.t_dirsize) +\
						get_val_size(type_arg1, op.t_dirsize), type_arg2, op.t_dirsize);
	if (type_arg2 == REG_CODE && arg2 && arg2 <= 16)
		arg2 = cursor->reg[arg2 - 1];
	else if (type_arg2 == IND_CODE)
		arg2 = check_grep_args(corewar->map, cursor->position\
											+ arg2 % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type == REG_CODE && arg3 && arg3 <= 16)
		arg3 = cursor->reg[arg3 - 1];

	if (type_arg1 == REG_CODE && type_arg1 && type_arg2 && type != IND_CODE)
	{
		if (arg1 && arg1 <= 16)
		{
			// ft_printf("where %i and what %i\n", cursor->position + (arg2 + arg3) % IDX_MOD, cursor->reg[arg1 - 1]);
			corewar->map[place_cur(cursor->position + (arg2 + arg3) % IDX_MOD)] = cursor->reg[arg1 - 1];
			// exit(0);
		}
			
	}
	cursor->position = place_cur(cursor->position + 2 + get_val_size(type_arg1, op.t_dirsize) +\
	get_val_size(type_arg2, op.t_dirsize) + get_val_size(type, op.t_dirsize));
	// dump(cursor);
}
