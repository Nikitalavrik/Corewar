/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:52 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/28 16:39:33 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include "corewar.h"

void	ft_sti(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int				i[2];
	int				*args;
	t_type			type;


	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t2 == REG_CODE && args[1] > 0 && args[1] <= 16)
		args[1] = cursor->reg[args[1] - 1];
	else if (type.t_tp.t2 == IND_CODE)
		args[1] = check_grep_args(corewar->map, place_cur(cursor->position\
									+ args[1] % IDX_MOD), DIR_CODE, 0);
	if (type.t_tp.t3 == REG_CODE && args[2] > 0 && args[2] <= 16)
		args[2] = cursor->reg[args[2] - 1];
	if (type.t_tp.t1 == REG_CODE && type.t_tp.t2 &&\
									type.t_tp.t3 && type.t_tp.t3 != IND_CODE)
	{
		if (args[0] && args[0] <= 16)
		{
			corewar->map[place_cur(cursor->position + ((args[1] + args[2]) % IDX_MOD))] = cursor->reg[args[0] - 1] >> 24;
			corewar->map[place_cur(cursor->position + ((args[1] + args[2]) % IDX_MOD) + 1)] = cursor->reg[args[0] - 1] << 8 >> 24;
			corewar->map[place_cur(cursor->position + ((args[1] + args[2]) % IDX_MOD) + 2)] = cursor->reg[args[0] - 1] << 16 >> 24;
			corewar->map[place_cur(cursor->position + ((args[1] + args[2]) % IDX_MOD) + 3)] = cursor->reg[args[0] - 1] << 24 >> 24;
			// ft_printf("arg1 = %i arg2 = %i arg3 = %i\n", 
			// 			cursor->reg[args[0] - 1], args[1], args[2]);
			if (corewar->flags == 2)
			{
				i[0] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD) / 64;
				i[1] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD) % 64;
				set_color_by_cursor(corewar, cursor);
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				corewar->vis->map[i[0] * 64 + i[1]] = cursor->player_nbr;
				i[0] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD + 1) / 64;
				i[1] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD + 1) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				corewar->vis->map[i[0] * 64 + i[1]] = cursor->player_nbr;
				i[0] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD + 2) / 64;
				i[1] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD + 2) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				corewar->vis->map[i[0] * 64 + i[1]] = cursor->player_nbr;
				i[0] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD + 3) / 64;
				i[1] = place_cur(cursor->position + (args[1] + args[2]) % IDX_MOD + 3) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				corewar->vis->map[i[0] * 64 + i[1]] = cursor->player_nbr;
			}
		}		
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
}