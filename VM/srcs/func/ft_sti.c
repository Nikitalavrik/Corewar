/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:52 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/17 14:40:34 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_incorrect_reg(t_type type, int *args, t_cursor *cursor,
																	t_op op)
{
	if ((type.t_tp.t2 == REG_CODE && (args[1] <= 0 || args[1] > 16))\
	|| (type.t_tp.t3 == REG_CODE && (args[2] <= 0 || args[2] > 16))
	|| !type.t_tp.t1 || !type.t_tp.t2 || !type.t_tp.t3)
	{
		ft_memdel((void **)&args);
		cursor->position = place_cur(cursor->position + 2 +\
														calc_pos(type, 3, op));
		return (1);
	}
	return (0);
}

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

void		ft_sti(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int				*args;
	t_type			type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[place_cur(cursor->position + 1)];
	args = init_args(corewar, cursor, op, type);
	// ft_printf("arg1 = %i arg2 = %i arg3 = %i\n", args[0], args[1], args[2]);
	// ft_printf("t1 = %i t2 = %i t3 = %i\n", type.t_tp.t1, type.t_tp.t2, type.t_tp.t3);
	if (check_incorrect_reg(type, args, cursor, op))
		return ;
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
		if (args[0] > 0 && args[0] <= 16)
		{
			// ft_printf("arg1 = %i arg2 = %i arg3 = %i\n", args[0], args[1], args[2]);
			save_arg(corewar, cursor, (args[1] + args[2]) % IDX_MOD,
									cursor->reg[args[0] - 1]);
		}

	}
	cursor->position = place_cur(cursor->position + 2 + calc_pos(type, 3, op));
	ft_memdel((void **)&args);
}
