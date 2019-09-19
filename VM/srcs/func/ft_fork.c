/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:35:15 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/19 13:06:05 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		max_curs(t_cursor *cursor, int player)
{
	t_cursor	*start;
	int			count;

	count = 0;
	start = cursor;
	while (cursor)
	{
		if (cursor->player_nbr == player)
			count++;
		cursor = cursor->next;
	}
	return (count);
}

void	ft_fork(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int			arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	(void)op;
	arg1 = (short int)grep_args(corewar->map, cursor->position + 1, T_DIR);
	// ft_printf("pos = %i\n", cursor->position);
	add_cursor(corewar, cursor->player_nbr);
	copy_cursor(cursor, corewar->cursor);
	corewar->cursor->id = ++g_id;
	corewar->cursor->position = cursor->position + (arg1 % IDX_MOD);
	cursor->position = place_cur(cursor->position + 1 + T_DIR);
	// ft_printf("cur id = %i\n", corewar->cursor->id);
	// out_cursor(corewar->cursor);
	// ft_printf("next op = %x\n", corewar->map[cursor->position]);
}
