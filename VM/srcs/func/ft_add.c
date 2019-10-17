/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:30:24 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/09/27 13:22:42 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 12:48:21 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
int		add_foo(int num1, int num2)
{
	return (num1 + num2);
}

void	ft_add(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_add_sub(corewar, cursor, op, add_foo);
}
=======
void	ft_add(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned char	arg1;
	unsigned char	arg2;
	unsigned char	arg3;
	unsigned char	type;
	unsigned char	type_arg1;
	unsigned char	type_arg2;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	type_arg2 = (unsigned char)(type << 2) >> 6;
	type = (unsigned char)(type << 4) >> 6;
	if (type_arg1 == REG_CODE && type_arg2 == REG_CODE && type == REG_CODE)
	{
		arg1 = grep_args(corewar->map, cursor->position + 2, T_REG);
		arg2 = grep_args(corewar->map, cursor->position + 2 + T_REG, T_REG);
		arg3 = grep_args(corewar->map, cursor->position + 2 + 2 * T_REG, T_REG);
		if (arg1 && arg1 <= 16 && arg2 && arg2 <= 16 && arg3 && arg3 <= 16)
		{
			cursor->reg[arg3 - 1] = cursor->reg[arg1 - 1] + cursor->reg[arg2 - 1];
			cursor->carry = !cursor->reg[arg3 - 1] ? 1 : 0;
		}
	}
	cursor->position = place_cur(cursor->position +(2 + get_val_size(type_arg1, op.t_dirsize) +\
	get_val_size(type_arg2, op.t_dirsize) + get_val_size(type, op.t_dirsize)));
	// dump(cursor);
}
>>>>>>> master
