/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op5_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:31:11 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 18:32:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sub(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned char	arg1;
	unsigned char	arg2;
	unsigned char	arg3;
	unsigned char	type;

	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	type = corewar->map[cursor->position + 1];
	arg1 = type >> 6;
	arg2 = (char)(type << 2) >> 6;
	arg3 = (char)(type << 4) >> 6;
	if (arg1 != REG_CODE || arg2 != REG_CODE || arg2 != REG_CODE)
	{
		cursor->position++;
		return ;
	}
	arg1 = grep_args(corewar->map, cursor->position + 2, T_REG);
	arg2 = grep_args(corewar->map, cursor->position + 2, T_REG);
	arg3 = grep_args(corewar->map, cursor->position + 2, T_REG);
	if (arg1 > 16 || arg2 > 16 || arg3 > 16)
	{
		cursor->position++;
		return ;
	}
	cursor->reg[arg3] = cursor->reg[arg1] - cursor->reg[arg2];
	cursor->carry = !cursor->reg[arg3] ? 1 : cursor->carry;
	cursor->position += (2 + 3 * T_REG);
	return ;
}

void	ft_and(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_or(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_xor(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}
