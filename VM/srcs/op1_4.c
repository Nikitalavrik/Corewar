/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:28:01 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 16:34:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
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
		arg1 = grep_args(corewar->map, cursor->position + 2, IND_SIZE);
	else if (type_arg1 == DIR_CODE)
		arg1 = grep_args(corewar->map, cursor->position + 2, DIR_SIZE);
	if (arg2 == REG_CODE)
		arg2 = (char)grep_args(corewar->map, cursor->position + 2 +\
		(type_arg1 == IND_CODE ? IND_SIZE : DIR_SIZE), 1);
	cursor->reg[arg2] = type_arg1 == IND_CODE ? arg1 % IDX_MOD : arg1;
	cursor->position += (3 + (type_arg1 == IND_CODE ? IND_SIZE : DIR_SIZE));
	return ;
}

void	ft_st(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_add(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}
