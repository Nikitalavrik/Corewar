/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:08 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/28 15:46:39 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int		*args;
	t_type	type;
	int		i[2];

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t1 == REG_CODE && (type.t_tp.t2 == REG_CODE || type.t_tp.t2 == IND_CODE))
	{
		if (type.t_tp.t2 == REG_CODE && args[0] <= 16 && args[0] > 0 && args[1] <= 16 && args[1] > 0)
			cursor->reg[args[1] - 1] = cursor->reg[args[0] - 1];
		else if (type.t_tp.t2 == IND_CODE && args[0] > 0 && args[0] <= 16)
		{
			corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD))] = cursor->reg[args[0] - 1] >> 24;
			corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 1)] = cursor->reg[args[0] - 1] << 8 >> 24;
			corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 2)] = cursor->reg[args[0] - 1] << 16 >> 24;
			corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 3)] = cursor->reg[args[0] - 1] << 24 >> 24;
			// ft_printf("%.2x %.2x %.2x %.2x\n",
			// corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD))],
			// corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 1)],
			// corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 2)],
			// corewar->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 3)]);
			if (corewar->flags & 2)
			{
				set_color_by_cursor(corewar, cursor);
				i[0] = place_cur(cursor->position + (args[1] % IDX_MOD)) / 64;
				i[1] = place_cur(cursor->position + (args[1] % IDX_MOD)) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				i[0] = place_cur(cursor->position + (args[1] % IDX_MOD) + 1) / 64;
				i[1] = place_cur(cursor->position + (args[1] % IDX_MOD) + 1) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				i[0] = place_cur(cursor->position + (args[1] % IDX_MOD) + 2) / 64;
				i[1] = place_cur(cursor->position + (args[1] % IDX_MOD) + 2) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				i[0] = place_cur(cursor->position + (args[1] % IDX_MOD) + 3) / 64;
				i[1] = place_cur(cursor->position + (args[1] % IDX_MOD) + 3) % 64;
				mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x", corewar->map[i[0] * 64 + i[1]]);
				corewar->vis->map[place_cur(cursor->position + (args[1] % IDX_MOD))] = cursor->player_nbr;;
				corewar->vis->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 1)] = cursor->player_nbr;;
				corewar->vis->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 2)] = cursor->player_nbr;;
				corewar->vis->map[place_cur(cursor->position + (args[1] % IDX_MOD) + 3)] = cursor->player_nbr;;	
				wrefresh(corewar->vis->win);
			}
		}		
	}
	// exit(0);
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 2, op));
}
