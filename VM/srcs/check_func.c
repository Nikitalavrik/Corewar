/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:07:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/04 19:08:50 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		check_operation(t_cw *corewar, t_cursor *cursor, int op)
{
	g_func[op - 1](corewar, cursor, g_op_tab[op - 1]);
	return (op);
}

int		check_uniq_id(t_player *players, int id)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (players[i].id == id)
			return (1);
		i++;
	}
	return (0);
}

void	check_uniq_name(t_player *players)
{
	int	i;

	i = MAX_PLAYERS - 1;
	while (i > 0 && !players[i].id)
		i--;
	while (i >= 0)
	{
		
		if (!players[i].name)
			print_error("Bad player number");
		if (ft_strcmp(ft_strrchr(players[i].name, '.'), ".cor"))
			print_error("Bad filename");
		i--;
	}
}

t_player check_winner(t_player *players, int n)
{
	int i;
	int	player_id;
	long min_live;

	min_live = -1;
	i = n;
	while (i)
	{
		if (players[i - 1].last_live > min_live)
		{
			min_live = players[i - 1].last_live;
			player_id = i - 1;
		}
		i--;
	}
	return (players[player_id]);
}
