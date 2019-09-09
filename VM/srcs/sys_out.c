/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:48:57 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 15:03:29 by nlavrine         ###   ########.fr       */
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

	i = 0;
	while (i < count)
	{
		ft_printf("%x ", line[i]);
		i++;
	}
	ft_printf("\n");
}
