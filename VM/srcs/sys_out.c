/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:48:57 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/10 15:36:04 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	out_players(t_player *players)
{
	int i;

	i = 0;
	players[i].id++;
	players[i].id--;
	while(i < MAX_PLAYERS){
		// ft_printf("id = %i player = %s\n", players[i].id, players[i].name);
		i++;
	}
}

void	out_cursor(t_cursor *cursor)
{
	t_cursor *start;

	start = cursor;
	while (start != NULL)
	{
		// ft_printf("id = %i carry = %i position = %i\n", start->id, start->carry, start->position);
		start = start->next;
	}	
}

void	out_print_bytes(unsigned char *line, int count)
{
	int i;

	i = 0;
	line[i]++;
	line[i]--;
	while (i < count)
	{
		// ft_printf("%x ", line[i]);
		i++;
	}
	// ft_printf("\n");
}

void	out_func_info(t_cw *corewar, t_cursor *cursor, t_op op)
{
	t_cursor *start;
	t_op      op1;
	int			i;

	i = corewar->player_nbr;
	start = cursor;
	op1 = op;
	// ft_printf("process %s nbr_players %i cursor id %i\n",\
	// op.func_name, corewar->player_nbr, cursor->id);
}

void	dump(t_cursor *cursor)
{
	int i;

	i = 0;
	cursor->reg[i]++;
	cursor->reg[i]--;
	while (i < 16)
	{
		// ft_printf("%i ", cursor->reg[i]);
		i++;
	}
	// ft_printf("\n\n");
}