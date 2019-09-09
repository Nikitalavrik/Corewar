/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:28:01 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 18:17:37 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned int arg1;

	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	arg1 = grep_args(corewar->map, cursor->position + 1, T_DIR);
	if (arg1 == (unsigned int)cursor->player_nbr)
		cursor->cycles_num = 0;
	return ;
}

void	ft_ld(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned char	type;
	unsigned int	type_arg1;

	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	arg1 = 0;
	type = corewar->map[cursor->position + 1];
	type_arg1 = type >> 6;
	arg2 = (char)(type << 2) >> 6;
	if (type_arg1 == IND_CODE)
		arg1 = grep_args(corewar->map, cursor->position + 2, T_IND);
	else if (type_arg1 == DIR_CODE)
		arg1 = grep_args(corewar->map, cursor->position + 2, T_DIR);
	cursor->carry = !arg1 ? 1 : cursor->carry;
	if (arg2 == REG_CODE)
		arg2 = (char)grep_args(corewar->map, cursor->position + 2 +\
		(type_arg1 == IND_CODE ? T_IND : T_DIR), T_REG);
	cursor->reg[arg2] = type_arg1 == IND_CODE ? cursor->position + 2 + arg1 % IDX_MOD : arg1;
	cursor->position += (3 + (type_arg1 == IND_CODE ? T_IND : T_DIR));
	return ;
}

void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned char	type;
	unsigned int	type_arg2;

	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	arg2 = 0;
	type = corewar->map[cursor->position + 1];
	arg1 = type >> 6;
	type_arg2 = (char)(type << 2) >> 6;
	if (arg1 == REG_CODE)
		arg1 = grep_args(corewar->map, cursor->position + 2, T_REG);
	if (type_arg2 == REG_CODE)
		arg2 = grep_args(corewar->map, cursor->position + 2 + T_REG, T_REG);
	else if (type_arg2 == IND_CODE)
		arg2 = grep_args(corewar->map, cursor->position + 2 + T_REG, T_IND);
	if (type_arg2 == REG_CODE)
		cursor->reg[arg2] = cursor->reg[arg1];
	else if (type_arg2 == IND_CODE)
	{
		corewar->map[cursor->position + arg2 % IDX_MOD] = cursor->reg[arg1];
	}
	cursor->position += (2 + T_REG + (type_arg2 == IND_CODE ? T_IND : T_REG));
	return ;
}

void	ft_add(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}
