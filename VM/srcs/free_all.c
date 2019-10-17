/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:41:24 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/14 14:05:37 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_player(t_player *players, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_memdel((void **)&players[i].head);
		i++;
	}
	ft_memdel((void **)&players);
}

void	free_corewar(t_cw *corewar)
{
	free_player(corewar->players, corewar->player_nbr);
	ft_memdel((void **)&corewar);
}
