/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:58 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/12 15:47:13 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 16:35:56 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
<<<<<<< HEAD
	arg1 = check_grep_args(corewar->map, place_cur(cursor->position + 1),\
														T_DIR, op.t_dirsize);
	if (arg1 == cursor->reg[0] && -arg1 > 0 && -arg1 <= 4)
		corewar->players[-arg1 - 1].last_live = g_i;
	cursor->cycles_num = 0;
	corewar->live_process++;
=======
	(void)op;
	arg1 = check_grep_args(corewar->map, cursor->position + 1, T_DIR, op.t_dirsize);
	// if (-arg1 != cursor->reg[0])
	// 	cursor->reg[0] = 0;
	cursor->cycles_num = 0;
>>>>>>> master
	cursor->position = place_cur(cursor->position + 1 + 2 * T_DIR);
}
