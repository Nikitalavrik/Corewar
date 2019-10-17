/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:39 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 16:26:28 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 13:05:06 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_ld(t_cw *corewar, t_cursor *cursor, t_op op)
{
<<<<<<< HEAD
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	if ((type.t_tp.t1 == DIR_CODE || type.t_tp.t1 == IND_CODE)\
						&& type.t_tp.t2 == REG_CODE && !type.t_tp.t3)
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
=======
	int	arg1;
	int	arg2;
	unsigned char	type;
	int	type_arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	arg1 = 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	type = (unsigned char)(type << 2) >> 6;
	if ((type_arg1 == DIR_CODE || type_arg1 == IND_CODE) && type == REG_CODE)
	{
		arg1 = check_grep_args(corewar->map, cursor->position + 2,\
										type_arg1, op.t_dirsize);
		arg2 = check_grep_args(corewar->map, cursor->position + 2 +\
				get_val_size(type_arg1, op.t_dirsize), type, op.t_dirsize);
		if (arg2 && arg2 <= 16)
		{
			cursor->reg[arg2 - 1] = type_arg1 == IND_CODE ? cursor->position + 2 +\
					get_val_size(type_arg1, op.t_dirsize) + arg1 % IDX_MOD : arg1;
			cursor->carry = !cursor->reg[arg2 - 1] ? 1 : 0;
		}
	}
	cursor->position = place_cur(cursor->position + 2 + get_val_size(type_arg1, op.t_dirsize) +\
									get_val_size(type, op.t_dirsize));
	// dump(cursor);
>>>>>>> master
}
