/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:08 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/12 17:00:40 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	vizual_save(t_cw *corewar, t_cursor *cursor, int wh)
{
	int i[2];
	int j;
	int	player;

	j = 0;
	player = cursor->player_nbr;
	set_color_by_cursor(corewar, cursor);
	while (j < 4)
	{
		i[0] = place_cur(cursor->position + wh + j) / 64;
		i[1] = place_cur(cursor->position + wh + j) % 64;
		mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x",
											corewar->map[i[0] * 64 + i[1]]);
		corewar->vis->map[place_cur(cursor->position + wh + j)] = player;
		j++;
	}
}

static void	save_arg(t_cw *corewar, t_cursor *cursor, int where, int val)
{
	corewar->map[place_cur(cursor->position + where)] = val >> 24;
	corewar->map[place_cur(cursor->position + where + 1)] = val << 8 >> 24;
	corewar->map[place_cur(cursor->position + where + 2)] = val << 16 >> 24;
	corewar->map[place_cur(cursor->position + where + 3)] = val << 24 >> 24;
	if (corewar->flags & 2)
		vizual_save(corewar, cursor, where);
}

void		ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int		*args;
	t_type	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	if (type.t_tp.t1 == REG_CODE &&\
					(type.t_tp.t2 == REG_CODE || type.t_tp.t2 == IND_CODE))
	{
		if (type.t_tp.t2 == REG_CODE && args[0] <= 16 &&\
								args[0] > 0 && args[1] <= 16 && args[1] > 0)
			cursor->reg[args[1] - 1] = cursor->reg[args[0] - 1];
		else if (type.t_tp.t2 == IND_CODE && args[0] > 0 && args[0] <= 16)
			save_arg(corewar, cursor, args[1] % IDX_MOD,
												cursor->reg[args[0] - 1]);
	}
	ft_memdel((void **)&args);
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 2, op));
}
