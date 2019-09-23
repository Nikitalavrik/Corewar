/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:08 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 16:01:59 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	t_type		type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type.t_tp.t1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position + 2 + T_REG, type.t_tp.t2, op.t_dirsize);
	if (type.t_tp.t1 == REG_CODE && (type.t_tp.t2 == REG_CODE || type.t_tp.t2 == IND_CODE))
	{
		if (type.t_tp.t2 == REG_CODE && arg1 <= 16 && arg1 && arg2 <= 16 && arg2)
			cursor->reg[arg2 - 1] = cursor->reg[arg1 - 1];
		else if (type.t_tp.t2 == IND_CODE && arg1 && arg1 <= 16)
		{
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD))] = cursor->reg[arg1 - 1] >> 24;
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 1)] = cursor->reg[arg1 - 1] << 8 >> 24;
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 2)] = cursor->reg[arg1 - 1] << 16 >> 24;
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 3)] = cursor->reg[arg1 - 1] << 24 >> 24;
			if (corewar->flags == 2)
			{
				set_color_by_cursor(corewar, cursor);
				mvwprintw(corewar->vis->win, place_cur(cursor->position + arg2 %\
					IDX_MOD)/ 64 + 2, 3 * (place_cur(cursor->position + arg2 %\
					IDX_MOD) % 64) + 5, "%.2x",\
					corewar->map[place_cur(cursor->position + arg2 % IDX_MOD)]);
				mvwprintw(corewar->vis->win, place_cur(cursor->position + arg2 %\
					IDX_MOD + 1)/ 64 + 2, 3 * (place_cur(cursor->position + arg2 %\
					IDX_MOD + 1) % 64) + 5, "%.2x",\
					corewar->map[place_cur(cursor->position + arg2 % IDX_MOD) + 1]);
				mvwprintw(corewar->vis->win, place_cur(cursor->position + arg2 %\
					IDX_MOD + 2)/ 64 + 2, 3 * (place_cur(cursor->position + arg2 %\
					IDX_MOD + 2) % 64) + 5, "%.2x",\
					corewar->map[place_cur(cursor->position + arg2 % IDX_MOD) + 2]);
				mvwprintw(corewar->vis->win, place_cur(cursor->position + arg2 %\
					IDX_MOD + 3)/ 64 + 2, 3 * (place_cur(cursor->position + arg2 %\
					IDX_MOD + 3) % 64) + 5, "%.2x",\
					corewar->map[place_cur(cursor->position + arg2 % IDX_MOD) + 3]);
				corewar->vis->map[place_cur(cursor->position + arg2 % IDX_MOD)] = -cursor->reg[0];
				corewar->vis->map[place_cur(cursor->position + arg2 % IDX_MOD) + 1] = -cursor->reg[0];
				corewar->vis->map[place_cur(cursor->position + arg2 % IDX_MOD) + 2] = -cursor->reg[0];
				corewar->vis->map[place_cur(cursor->position + arg2 % IDX_MOD) + 3] = -cursor->reg[0];	
				wrefresh(corewar->vis->win);
			}
		}
			
	}
	cursor->position = place_cur(cursor->position + 2 +\
	get_val_size(type.t_tp.t1, op.t_dirsize) +\
	get_val_size(type.t_tp.t2, op.t_dirsize));
}
