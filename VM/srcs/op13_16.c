/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op13_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:33:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 13:38:22 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lld(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_lldi(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_lfork(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}

void	ft_aff(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
	return ;
}
