/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:36:28 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/13 12:38:52 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lfork(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int				arg1;
	unsigned int	next_op;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	arg1 = (int)grep_args(corewar->map, place_cur(cursor->position + 1), T_DIR);
	add_cursor(corewar, cursor->player_nbr);
	copy_cursor(cursor, corewar->cursor);
	corewar->cursor->id = ++g_id;
	corewar->cursor->position = place_cur(cursor->position + arg1);
	cursor->position = place_cur(cursor->position + 1 + T_DIR);
	next_op = corewar->map[corewar->cursor->position];
	// if (next_op && next_op <= 16)
	// {
	// 	arg1 = g_op_tab[next_op - 1].cycle_before_exec - 1;
	// 	corewar->cursor->op = next_op;
	// 	corewar->cursor->remaining_cycles += arg1;
	// 	corewar->cursor->is_wait = 1;
	// }
	// else
	// 	corewar->cursor->position += 1;
}
