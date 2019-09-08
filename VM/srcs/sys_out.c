/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:48:57 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/08 16:32:08 by nlavrine         ###   ########.fr       */
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