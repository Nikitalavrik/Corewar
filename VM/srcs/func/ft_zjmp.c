/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:18 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 16:17:08 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_zjmp(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int	arg1;

	// out_func_info(corewar, cursor, op);
	(void)op;
	arg1 = (int)grep_args(corewar->map, cursor->position + 1, T_DIR);
	if (cursor->carry)
		cursor->position += (arg1 % IDX_MOD);
	else
		cursor->position += (1 + T_DIR);
}
