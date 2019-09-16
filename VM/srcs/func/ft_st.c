/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:08 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 18:06:54 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	unsigned char	type;
	int	type_arg1;
	int i[2];


	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	arg2 = 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	type = (unsigned char)(type << 2) >> 6;
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type_arg1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position + 2 + T_REG, type, op.t_dirsize);
	if (type_arg1 == REG_CODE && (type == REG_CODE || type == IND_CODE))
	{
		if (type == REG_CODE && arg1 <= 16 && arg1 && arg2 <= 16 && arg2)
			cursor->reg[arg2 - 1] = cursor->reg[arg1 - 1];
		else if (type == IND_CODE && arg1 && arg1 <= 16)
		{
			corewar->map[place_cur(cursor->position + arg2 % IDX_MOD)] = cursor->reg[arg1 - 1];
			// ft_putnbr(cursor->reg[0]);
			if (corewar->flags == 2)
			{
				i[0] = place_cur(cursor->position + arg2 % IDX_MOD) / 64;
				i[1] = place_cur(cursor->position + arg2 % IDX_MOD) % 64;
				set_color_by_cursor(corewar, cursor);
				mvwprintw(corewar->vis->win, place_cur(cursor->position + arg2 %\
					IDX_MOD)/ 64 + 2, 3 * (place_cur(cursor->position + arg2 %\
					IDX_MOD) % 64) + 5, "%.2x",\
					corewar->map[place_cur(cursor->position + arg2 % IDX_MOD)]);
				corewar->vis->map[place_cur(cursor->position + arg2 % IDX_MOD)] = -cursor->reg[0];	
			}
			// ft_printf("where %i and what = %i\n", cursor->position + arg2 % IDX_MOD, cursor->reg[arg1 - 1]);
		}
			
	}
	cursor->position = place_cur(cursor->position + 2 + get_val_size(type_arg1, op.t_dirsize) +\
						get_val_size(type, op.t_dirsize));
	// dump(cursor);
}
