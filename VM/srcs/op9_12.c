/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op9_12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:32:55 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 13:38:47 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_zjmp(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_ldi(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_sti(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_fork(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}
