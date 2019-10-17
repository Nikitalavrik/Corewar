/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:36:28 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/13 14:53:21 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 12:44:05 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lfork(t_cw *corewar, t_cursor *cursor, t_op op)
{
<<<<<<< HEAD
	int				arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	arg1 = (int)grep_args(corewar->map, place_cur(cursor->position + 1), T_DIR);
	add_cursor(corewar, cursor->player_nbr);
	copy_cursor(cursor, corewar->cursor);
	corewar->cursor->id = ++g_id;
	corewar->cursor->position = place_cur(cursor->position + arg1);
	cursor->position = place_cur(cursor->position + 1 + T_DIR);
=======
	int			arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	(void)op;
	arg1 = (int)grep_args(corewar->map, cursor->position + 1, T_DIR);
	add_cursor(corewar, cursor->player_nbr);
	copy_cursor(cursor, corewar->cursor);
	corewar->cursor->id = ++g_id;
	corewar->cursor->position = place_cur(arg1);
	cursor->position = place_cur(cursor->position + 1 + T_DIR);
	// ft_printf("lcur id = %i\n", corewar->cursor->id);
>>>>>>> master
}
