/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/11 18:08:39 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	arg1 = check_grep_args(corewar->map, place_cur(cursor->position + 1),\
														T_DIR, op.t_dirsize);
	if (arg1 == cursor->reg[0] && -arg1 > 0 && -arg1 <= 4)
		corewar->players[-arg1 - 1].last_live = g_i;
	cursor->cycles_num = 0;
	corewar->live_process++;
	cursor->position = place_cur(cursor->position + 1 + 2 * T_DIR);
	// ft_printf("pos = %i\n", cursor->position);
}
