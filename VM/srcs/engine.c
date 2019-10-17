/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:16:51 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/17 15:40:14 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		do_op(t_cw *corewar, t_cursor *cursor)
{
	unsigned char op;

	if (cursor->remaining_cycles == 0)
	{
		op = corewar->map[cursor->position];
		if (op > 16 || !op)
			return (1);
		cursor->op = op;
		cursor->remaining_cycles += g_op_tab[op - 1].cycle_before_exec;
	}
	if (cursor->remaining_cycles > 0)
		cursor->remaining_cycles--;
	if (cursor->remaining_cycles <= 0)
	{
		if (cursor->op)
		{
			check_operation(corewar, cursor, cursor->op);
			cursor->op = 0;
			return (0);
		}
	}
	return (0);
}

void	iterate_all_cursors(t_cw *corewar, t_cursor *cursor)
{
	t_cursor	*start;
	int			pos;
	int			count;
	int			i;

	pos = 0;
	count = 0;
	i = 0;
	start = cursor;
	while (start)
	{
		pos = start->position;
		start->position += do_op(corewar, start);
		start->position %= MEM_SIZE;
		start->cycles_num++;
		if (corewar->flags & 2)
		{
			draw_cursor(pos, start, corewar, cursor);
			ft_check_size_win(corewar, &i);
			count++;
		}
		start = start->next;
	}
	draw_cursor_count(corewar, count, i);
}

void	end(t_cw *corewar, char c)
{
	t_player	player;

	player = check_winner(corewar->players, corewar->player_nbr);
	if (!(corewar->flags & 2))
		ft_printf("Winner: Player %i \"%s\"\n", player.id,\
			player.head->prog_name);
	if (corewar->flags & 2)
		after_game(corewar, player, c);
}

void	start_game(t_cw *corewar, char c, int *i, int *tmp_die)
{
	*i = 0;
	*tmp_die = 0;
	check_dump_flag(corewar, c, *i);
	if (corewar->flags & 2)
	{
		while (c != 32)
			c = getch();
		c = '\0';
		nodelay(stdscr, TRUE);
	}
}

void	engine(t_cw *corewar)
{
	int			i;
	char		c;
	int			tmp_die;

	c = '\0';
	start_game(corewar, c, &i, &tmp_die);
	while (1)
	{
		i++;
		tmp_die++;
		g_i = i;
		iterate_all_cursors(corewar, corewar->cursor);
		if (tmp_die >= corewar->cycle_to_die)
		{
			if ((tmp_die = check_cycle_to_die(corewar)))
			{
				add_speed_pause(corewar, c, i);
				break ;
			}
			tmp_die = 0;
		}
		check_dump_flag(corewar, c, i);
		add_speed_pause(corewar, c, i);
	}
	end(corewar, c);
}
