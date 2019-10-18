/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:18:23 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 16:24:19 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				count_players(t_player *players)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS && players[i].id)
		i++;
	return (i);
}

void			init_corewar(t_cw *corewar, t_player *players)
{
	corewar->player_nbr = count_players(players);
	corewar->players = players;
	ft_bzero(corewar->map, MEM_SIZE);
	if (corewar->flags & 2)
	{
		vis_init(corewar);
		draw_map(corewar);
	}
	ft_printf("Introducing contestants...\n");
}

int				init_file(char *filename, t_header **head)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Bad file\n");
	if (!(*head = ft_memalloc(sizeof(t_header))))
		print_error("Some trouble with malloc\n");
	return (fd);
}
