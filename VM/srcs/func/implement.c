/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:04:43 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/27 15:27:30 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_and_xor_or(t_cw *corewar, t_cursor *cursor, t_op op, int f(int, int))
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t1 == REG_CODE && args[0] > 0 && args[0] <= 16)
		args[0] = cursor->reg[args[0] - 1];
	else if (type.t_tp.t1 == IND_CODE)
		args[0] = (int)check_grep_args(corewar->map, cursor->position\
								+ args[0] % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t2 == REG_CODE && args[1] > 0 && args[1] <= 16)
		args[1] = cursor->reg[args[1] - 1];
	else if (type.t_tp.t2 == IND_CODE)
		args[1] = (int)check_grep_args(corewar->map, cursor->position\
								+ args[1] % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t3 == REG_CODE)
	{
		cursor->reg[args[2] - 1] = f(args[0], args[0]);
		cursor->carry = !cursor->reg[args[2] - 1] ? 1 : 0;
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}

void	ft_add_sub(t_cw *corewar, t_cursor *cursor, t_op op, int f(int, int))
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t1 == REG_CODE &&\
	type.t_tp.t2 == REG_CODE && type.t_tp.t3 == REG_CODE)
	{
		if (args[0] > 0 && args[0] <= 16 && args[1] > 0\
			&& args[1] <= 16 && args[2] > 0 && args[2] <= 16)
		{
			cursor->reg[args[2] - 1] = f(cursor->reg[args[0] - 1],\
													cursor->reg[args[1] - 1]);
			cursor->carry = !cursor->reg[args[2] - 1] ? 1 : 0;
		}
	}
	ft_memdel((void **)&args);
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

int		*init_args(t_cw *corewar, t_cursor *cursor, t_op op, t_type type)
{
	int *args;

	args = ft_memalloc(sizeof(int) * op.num_of_args);
	if (op.num_of_args >= 1)
		args[0] = check_grep_args(corewar->map, cursor->position + 2,\
											type.t_tp.t1, op.t_dirsize);
	if (op.num_of_args >= 2)
		args[1] = check_grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type.t_tp.t1, op.t_dirsize), type.t_tp.t2, op.t_dirsize);
	if (op.num_of_args >= 3)
		args[2] = grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type.t_tp.t1, op.t_dirsize) +\
		get_val_size(type.t_tp.t2, op.t_dirsize), type.t_tp.t3);
	return (args);
}
