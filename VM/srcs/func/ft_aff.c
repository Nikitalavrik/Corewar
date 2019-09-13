/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:36:49 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 18:06:20 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_aff(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned char	arg1;
	unsigned char	type_arg1;
	unsigned char	type;

	corewar->flags & 8 ? out_func_info(corewar, cursor, op) : 0;
	(void)op;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	arg1 = check_grep_args(corewar->map, cursor->position + 2, type_arg1, op.t_dirsize);
	if (type_arg1 == REG_CODE && arg1 && arg1 <= 16)
		arg1 = cursor->reg[arg1 - 1] % 256;
	ft_printf("Aff: %c\n", arg1);
	cursor->position = place_cur(cursor->position + (2 + T_REG));
}
