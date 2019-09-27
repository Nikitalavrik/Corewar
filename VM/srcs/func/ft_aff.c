/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:36:49 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 15:12:41 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_aff(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned char	arg1;
	t_type			type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	type.types = corewar->map[cursor->position + 1];
	arg1 = check_grep_args(corewar->map, cursor->position + 2,\
	type.t_tp.t1, op.t_dirsize);
	if (type.t_tp.t1 == REG_CODE && arg1 && arg1 <= 16)
		arg1 = cursor->reg[arg1 - 1] % 256;
	if (corewar->flags & 1)
		ft_printf("Aff: %c\n", arg1);
	cursor->position = place_cur(cursor->position + (2 + T_REG));
}
