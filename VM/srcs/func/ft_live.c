/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 15:32:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cw *corewar, t_cursor *cursor, t_op op)
{
	int arg1;

	out_func_info(corewar, cursor, op);
	arg1 = grep_args(corewar->map, cursor->position + 1, T_DIR);
	if (arg1 == cursor->reg[0])
		cursor->cycles_num = 0;
	cursor->position += (1 + T_DIR);
}
