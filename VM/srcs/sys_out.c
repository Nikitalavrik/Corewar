/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:48:57 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 17:41:59 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 13:18:58 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	out_players(t_player *players)
{
	int i;

	i = 0;
<<<<<<< HEAD
	while (i < MAX_PLAYERS)
	{
=======
	while(i < MAX_PLAYERS){
>>>>>>> master
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
<<<<<<< HEAD
		ft_printf("id = %i cycle_num %i position = %i remaining %i\n",
		start->id, start->cycles_num, start->position,
												start->remaining_cycles);
		start = start->next;
	}
=======
		ft_printf("id = %i carry = %i position = %i\n", start->id, start->carry, start->position);
		start = start->next;
	}	
>>>>>>> master
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
<<<<<<< HEAD
	ft_printf("i = %i process %s cursor id %i cursor\
	position %i max_players = %i\n", g_i, op.func_name, cursor->id,
							cursor->position, corewar->player_nbr);
}
=======
	ft_printf("i = %i process %s nbr_players %i cursor id %i\n",\
	g_i, op.func_name, corewar->player_nbr, cursor->id);
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
>>>>>>> master
