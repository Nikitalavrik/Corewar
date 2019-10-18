/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:07:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 16:49:47 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int			check_operation(t_cw *corewar, t_cursor *cursor, int op)
{
	g_func[op - 1](corewar, cursor, g_op_tab[op - 1]);
	return (op);
}

int			check_uniq_id(t_player *players, int id)
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

void		check_uniq_name(t_player *players)
{
	int		i;
	char	*extent;

	i = MAX_PLAYERS - 1;
	while (i > 0 && !players[i].id)
		i--;
	while (i >= 0)
	{
		if (!players[i].name)
			print_error("", "Bad player number\n");
		extent = ft_strrchr(players[i].name, '.');
		if (!extent || ft_strcmp(extent, ".cor"))
			print_error(players[i].name, ": Bad filename\n");
		i--;
	}
}

t_player	check_winner(t_player *players, int n)
{
	int		i;
	int		player_id;
	long	min_live;

	min_live = -1;
	i = n;
	player_id = 0;
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

int			check_cycle_to_die(t_cw *corewar)
{
	t_cursor	*start;
	t_cursor	*prev;
	t_cursor	*next;

	start = corewar->cursor;
	prev = NULL;
	while (start)
	{
		next = start->next;
		if (start->cycles_num >= corewar->cycle_to_die)
			del_cursor(&start, &prev, &corewar->cursor, corewar);
		prev = start ? start : prev;
		start = next;
	}
	if (corewar->live_process < NBR_LIVE)
		corewar->check_cycle++;
	if (corewar->live_process >= NBR_LIVE || corewar->check_cycle >= MAX_CHECKS)
	{
		corewar->cycle_to_die -= CYCLE_DELTA;
		corewar->check_cycle = 0;
	}
	corewar->live_process = 0;
	return (corewar->cursor == NULL ? 1 : 0);
}
