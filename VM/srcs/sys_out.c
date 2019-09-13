/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:48:57 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 16:12:50 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	out_players(t_player *players)
{
	int i;

	i = 0;
	while(i < MAX_PLAYERS){
		ft_printf("id = %i player = %s\n", players[i].id, players[i].name);
		i++;
	}
}

void	out_cursor(t_cursor *cursor)
{
	t_cursor *start;

	start = cursor;
	while (start != NULL)
	{
		ft_printf("id = %i carry = %i position = %i\n", start->id, start->carry, start->position);
		start = start->next;
	}	
}

void	out_print_bytes(unsigned char *line, int count)
{
	int i;
	int k;

	i = 0;
	count++;
	while (i < 64)
	{
		k = -1;
		while (++k < 64)
			ft_printf("%.2x ", line[i * 64 + k]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	out_func_info(t_cw *corewar, t_cursor *cursor, t_op op)
{
	ft_printf("process %s nbr_players %i cursor id %i\n",\
	op.func_name, corewar->player_nbr, cursor->id);
}

void	dump(t_cursor *cursor)
{
	int i;

	i = 0;
	cursor->reg[i]++;
	cursor->reg[i]--;
	while (i < 16)
	{
		ft_printf("%i ", cursor->reg[i]);
		i++;
	}
	ft_printf("\n\n");
}