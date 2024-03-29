/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:35:15 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/13 14:53:15 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_fork(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int				arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	arg1 = (short int)grep_args(corewar->map,\
									place_cur(cursor->position + 1), T_DIR);
	add_cursor(corewar, cursor->player_nbr);
	copy_cursor(cursor, corewar->cursor);
	corewar->cursor->id = ++g_id;
	corewar->cursor->position = place_cur(cursor->position\
														+ (arg1 % IDX_MOD));
	cursor->position = place_cur(cursor->position + 1 + T_DIR);
}
