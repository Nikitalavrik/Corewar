/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:18 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/19 13:48:54 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_zjmp(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	(void)op;
	arg1 = (int)grep_args(corewar->map, cursor->position + 1, T_DIR);
	// ft_printf("+carry = %i arg1 = %i - pos = %i\n", cursor->carry, arg1, cursor->position);
	if (cursor->carry)
		cursor->position = place_cur(cursor->position + arg1 % IDX_MOD);
	else
		cursor->position = place_cur(cursor->position + 1 + T_DIR);
	// ft_printf("-carry = %i arg1 = %i - pos = %i\n", cursor->carry, arg1, cursor->position);
}
