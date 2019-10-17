/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:08 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 13:36:04 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 12:42:32 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
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
	if (type.t_tp.t1 == REG_CODE && !type.t_tp.t3 &&\
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
=======
void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;
	int	arg2;
	unsigned char	type;
	int	type_arg1;


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
			// ft_printf("cursor->reg = %i\n", cursor->reg[arg1]);
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD))] = cursor->reg[arg1 - 1] >> 24;
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 1)] = cursor->reg[arg1 - 1] << 8 >> 24;
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 2)] = cursor->reg[arg1 - 1] << 16 >> 24;
			corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 3)] = cursor->reg[arg1 - 1] << 24 >> 24;
			// ft_printf("map[%i] = %x\n", place_cur(cursor->position + (arg2 % IDX_MOD)), corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD))]);
			// ft_printf("map[%i] = %x\n", place_cur(cursor->position + (arg2 % IDX_MOD) + 1), corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 1)]);
			// ft_printf("map[%i] = %x\n", place_cur(cursor->position + (arg2 % IDX_MOD) + 2), corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 2)]);
			// ft_printf("map[%i] = %x\n", place_cur(cursor->position + (arg2 % IDX_MOD) + 3), corewar->map[place_cur(cursor->position + (arg2 % IDX_MOD) + 3)]);

			// ft_putnbr(cursor->reg[0]);
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
			// ft_printf("where %i and what = %i\n", cursor->position + arg2 % IDX_MOD, cursor->reg[arg1 - 1]);
		}
			
	}
	cursor->position = place_cur(cursor->position + 2 + get_val_size(type_arg1, op.t_dirsize) +\
						get_val_size(type, op.t_dirsize));
	// dump(cursor);
>>>>>>> master
}
