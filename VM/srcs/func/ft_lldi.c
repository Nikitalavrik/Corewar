/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:29 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 16:34:13 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 12:51:17 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
static int	check_incorrect_reg(t_type type, int *args,
													t_cursor *cursor, t_op op)
{
	if ((type.t_tp.t1 == REG_CODE && (args[0] <= 0 || args[0] > 16))\
	|| (type.t_tp.t2 == REG_CODE && (args[1] <= 0 || args[1] > 16))
	|| !type.t_tp.t1 || !type.t_tp.t2 || !type.t_tp.t3)
	{
		ft_memdel((void **)&args);
		cursor->position = place_cur(cursor->position + 2 +\
														calc_pos(type, 3, op));
		return (1);
	}
	return (0);
}

void		ft_lldi(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	if (check_incorrect_reg(type, args, cursor, op))
		return ;
	if (type.t_tp.t1 == REG_CODE && args[0] > 0 && args[0] <= 16)
		args[0] = cursor->reg[args[0] - 1];
	else if (type.t_tp.t1 == IND_CODE)
		args[0] = check_grep_args(corewar->map, place_cur(cursor->position + 2\
								+ args[0] % IDX_MOD), DIR_CODE, 0);
	if (type.t_tp.t2 == REG_CODE && args[1] > 0 && args[1] <= 16)
		args[1] = cursor->reg[args[1] - 1];
	if (type.t_tp.t3 == REG_CODE && type.t_tp.t1 &&\
								type.t_tp.t2 && type.t_tp.t2 != IND_CODE)
	{
		cursor->reg[args[2] - 1] = check_grep_args(corewar->map,
		place_cur(cursor->position + (args[0] + args[1])), DIR_CODE, 0);
		cursor->carry = !cursor->reg[args[2] - 1] ? 1 : 0;
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
=======
void	ft_lldi(t_cw *corewar, t_cursor *cursor, t_op op)
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
	arg2 = check_grep_args(corewar->map, cursor->position +\
					get_val_size(type_arg1, op.t_dirsize), type_arg2, op.t_dirsize);
	if (type_arg1 == REG_CODE && arg1 && arg1 <= 16)
		arg1 = cursor->reg[arg1 - 1];
	else if (type_arg1 == IND_CODE)
		arg1 = check_grep_args(corewar->map, cursor->position + 2\
											+ arg1 % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type_arg2 == REG_CODE && arg2 && arg2 <= 16)
		arg2 = cursor->reg[arg2 - 1];

	if (type == REG_CODE && type_arg1 && type_arg2 && type_arg2 != IND_CODE)
	{
		arg3 = grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type_arg1, op.t_dirsize) +\
		get_val_size(type_arg2, op.t_dirsize), T_REG);
		cursor->reg[arg3 - 1] = (arg1 + arg2);
		cursor->carry = !cursor->reg[arg3 - 1] ? 1 : 0;
	}
	cursor->position = place_cur(cursor->position + 2 + get_val_size(type_arg1, op.t_dirsize) +\
	get_val_size(type_arg2, op.t_dirsize) + get_val_size(type, op.t_dirsize));
>>>>>>> master
}
