/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:52 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 16:41:27 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int				i[2];
	unsigned char	arg1;
	int				arg2;
	int				arg3;
	t_type			type;


	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type.t_tp.t1, op.t_dirsize);
	arg2 = check_grep_args(corewar->map, cursor->position + 2 + \
		get_val_size(type.t_tp.t1, op.t_dirsize), type.t_tp.t2, op.t_dirsize);
	arg3 = check_grep_args(corewar->map, cursor->position + 2 +\
		get_val_size(type.t_tp.t1, op.t_dirsize) +\
		get_val_size(type.t_tp.t2, op.t_dirsize), type.t_tp.t3, op.t_dirsize);
	if (type.t_tp.t2 == REG_CODE && arg2 > 0 && arg2 <= 16)
		arg2 = cursor->reg[arg2 - 1];
	else if (type.t_tp.t2 == IND_CODE)
		arg2 = check_grep_args(corewar->map, cursor->position\
									+ arg2 % IDX_MOD, IND_CODE, op.t_dirsize);
	if (type.t_tp.t3 == REG_CODE && arg3 > 0 && arg3 <= 16)
		arg3 = cursor->reg[arg3 - 1];
	if (type.t_tp.t1 == REG_CODE && type.t_tp.t2 &&\
									type.t_tp.t3 && type.t_tp.t3 != IND_CODE)
	{
		if (arg1 && arg1 <= 16)
		{
			corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD))] = cursor->reg[arg1 - 1] >> 24;
			corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 1)] = cursor->reg[arg1 - 1] << 8 >> 24;
			corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 2)] = cursor->reg[arg1 - 1] << 16 >> 24;
			corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 3)] = cursor->reg[arg1 - 1] << 24 >> 24;
			if (corewar->flags == 2)
			{
				i[0] = place_cur(cursor->position + (arg2 + arg3) % IDX_MOD) / 64;
				i[1] = place_cur(cursor->position + (arg2 + arg3) % IDX_MOD) % 64;
				set_color_by_cursor(corewar, cursor);
				mvwprintw(corewar->vis->win, corewar->map\
				[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD))]\
				/ 64 + 2, 3 * corewar->map[place_cur(cursor->position + ((arg2 + arg3)\
					% IDX_MOD))] % 64 + 5, "%.2x",\
				corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD))]);
				mvwprintw(corewar->vis->win, corewar->map\
				[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 1)]\
				/ 64 + 2, 3 * corewar->map[place_cur(cursor->position + ((arg2 + arg3)\
					% IDX_MOD) + 1)] % 64 + 5, "%.2x",\
				corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 1)]);
				mvwprintw(corewar->vis->win, corewar->map\
				[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 2)]\
				/ 64 + 2, 3 * corewar->map[place_cur(cursor->position + ((arg2 + arg3)\
					% IDX_MOD) + 2)] % 64 + 5, "%.2x",\
				corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 2)]);
				mvwprintw(corewar->vis->win, corewar->map\
				[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 3)]\
				/ 64 + 2, 3 * corewar->map[place_cur(cursor->position + ((arg2 + arg3)\
					% IDX_MOD) + 3)] % 64 + 5, "%.2x",\
				corewar->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 3)]);
				corewar->vis->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD))] = -cursor->reg[0];
				corewar->vis->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 1)] = -cursor->reg[0];
				corewar->vis->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 2)] = -cursor->reg[0];
				corewar->vis->map[place_cur(cursor->position + ((arg2 + arg3) % IDX_MOD) + 3)] = -cursor->reg[0];
				wrefresh(corewar->vis->win);
			}
		}
			
	}
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}
