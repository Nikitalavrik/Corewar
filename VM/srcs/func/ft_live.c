/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/19 14:14:44 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	(void)op;
	arg1 = check_grep_args(corewar->map, cursor->position + 1, T_DIR, op.t_dirsize);
	// ft_printf("hex = %#x %#x\n", corewar->map[cursor->position + 1], corewar->map[cursor->position + 2]);
	// ft_printf("arg1 = %i arg2 = %i\n", arg1, cursor->reg[0]);
	if (-arg1 == cursor->reg[0])
		cursor->cycles_num = 0;
	cursor->position = place_cur(cursor->position + 1 + 2 * T_DIR);
}
