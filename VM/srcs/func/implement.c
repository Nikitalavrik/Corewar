/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:04:43 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 16:28:15 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and_xor_or(t_cw *corewar, t_cursor *cursor, t_op op, int f(int, int))
{
	int	arg1;
	int	arg2;
	unsigned char	arg3;
	t_type			type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	arg1 = check_grep_args(corewar->map, cursor->position + 2,\
										type.t_tp.t1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position + 2 +\
	get_val_size(type.t_tp.t1, op.t_dirsize),\
										type.t_tp.t2, op.t_dirsize);
	if (type.t_tp.t1 == REG_CODE && arg1 && arg1 <= 16)
		arg1 = cursor->reg[arg1 - 1];
	else if (type.t_tp.t1 == IND_CODE)
		arg1 = (int)check_grep_args(corewar->map, cursor->position\
								+ arg1 % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t2 == REG_CODE && arg2 && arg2 <= 16)
		arg2 = cursor->reg[arg2 - 1];
	else if (type.t_tp.t2 == IND_CODE)
		arg2 = (int)check_grep_args(corewar->map, cursor->position\
								+ arg2 % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t3 == REG_CODE)
	{
		arg3 = grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type.t_tp.t1, op.t_dirsize) +\
		get_val_size(type.t_tp.t2, op.t_dirsize), T_REG);
		cursor->reg[arg3 - 1] = f(arg1, arg2);
		cursor->carry = !cursor->reg[arg3 - 1] ? 1 : 0;
	}
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}

void	ft_add_sub(t_cw *corewar, t_cursor *cursor, t_op op, int f(int, int))
{
	unsigned char	arg1;
	unsigned char	arg2;
	unsigned char	arg3;
	t_type			type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	if (type.t_tp.t1 == REG_CODE &&\
	type.t_tp.t2 == REG_CODE && type.t_tp.t3 == REG_CODE)
	{
		arg1 = grep_args(corewar->map, cursor->position + 2, T_REG);
		arg2 = grep_args(corewar->map, cursor->position + 2 + T_REG, T_REG);
		arg3 = grep_args(corewar->map, cursor->position + 2 + 2 * T_REG, T_REG);
		if (arg1 && arg1 <= 16 && arg2 && arg2 <= 16 && arg3 && arg3 <= 16)
		{
			cursor->reg[arg3 - 1] = f(cursor->reg[arg1 - 1],\
													cursor->reg[arg2 - 1]);
			cursor->carry = !cursor->reg[arg3 - 1] ? 1 : 0;
		}
	}
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}

int		calc_pos(t_type	type, int n, t_op op)
{
	int num;

	num = 0;
	if (n >= 1)
		num += get_val_size(type.t_tp.t1, op.t_dirsize);
	if (n >= 2)
		num += get_val_size(type.t_tp.t2, op.t_dirsize);
	if (n >= 3)
		num += get_val_size(type.t_tp.t3, op.t_dirsize);
	return (num);
}
