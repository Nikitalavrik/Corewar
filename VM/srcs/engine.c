/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:16:51 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/23 13:58:33 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

# define HEIGHT					(MEM_SIZE / 64 + 4)
# define WIDTH					(64 * 3 + 5)

int		check_cycle_to_die(t_cw *corewar)
{
	t_cursor	*start;
	t_cursor	*prev;
	t_cursor	*next;
	int			live_process;

	start = corewar->cursor;
	prev = NULL;
	live_process = 0;
	while (start)
	{
		next = start->next;
		if (start->cycles_num > corewar->cycle_to_die)
			del_cursor(&start, &prev, &corewar->cursor, corewar);
		else
			live_process++;
		prev = start ? start : prev;
		start = next;
	}
	if (live_process >= NBR_LIVE || corewar->check_cycle > MAX_CHECKS)
	{
		corewar->cycle_to_die -= CYCLE_DELTA;
		corewar->check_cycle = corewar->check_cycle > MAX_CHECKS ? 0 :\
		corewar->check_cycle;
	}
	else
		corewar->check_cycle++;
	return (corewar->cursor == NULL ? 1 : 0);
}

int		do_op(t_cw *corewar, t_cursor *cursor)
{
	unsigned char op;

	op = corewar->map[cursor->position];
	if (op > 16 || !op)
		return (1);
	if (!cursor->is_wait)
	{
		cursor->op = op;
		cursor->remaining_cycles = g_op_tab[op - 1].cycle_before_exec;
		cursor->is_wait = 1;
	}
	if (cursor->remaining_cycles <= 0 && cursor->is_wait)
	{
		check_operation(corewar, cursor, cursor->op);
		cursor->is_wait = 0;
		do_op(corewar, cursor);
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
		start->remaining_cycles -= start->is_wait ? 1 : 0; 
		pos = start->position;
		start->position += do_op(corewar, start);
		start->position %= MEM_SIZE;
		start->cycles_num++;
		if (corewar->flags == 2)
		{
			if (COLS != corewar->vis->cols || LINES != corewar->vis->lines)
			{
				system("sleep 1 && printf '\033[8;100;1000t' && printf '\e[3;0;0t' && sleep 2");
				draw_map(corewar);
				draw_box_and_words(corewar);
			}
			draw_cursor(pos, start, corewar, cursor);
			count++;
		}
		start = start->next;
	}
	if (corewar->flags == 2)
	{
		 mvwprintw(corewar->vis->info, 14, 21, "%i", count);
		 while (i < corewar->player_nbr)
		 {
		 	mvwprintw(corewar->vis->info, 15 + corewar->vis->player * 3 + (i + 1) * 3, 16, "%i", corewar->players[i].last_live);
		 	i++;
		 }
		 wrefresh(corewar->vis->info);
	}
}

void	engine(t_cw *corewar)
{
	int			i;
	char		c;
	int			tmp_die;
	t_player	player;

	i = 0;
	tmp_die = 0;
	corewar->cycle_to_die = CYCLE_TO_DIE;
	c = '\0';
	if (corewar->flags == 2)
	{
		while (c != 32)
		    c = getch();
		c = '\0';
		nodelay(stdscr, TRUE);
	}
	while (1)
	{
		g_i = i;
		iterate_all_cursors(corewar, corewar->cursor);
		if (tmp_die >= corewar->cycle_to_die)
		{
			if ((tmp_die = check_cycle_to_die(corewar)))
				break ;
			tmp_die = 0;
		}
		else
			tmp_die++;
		if (corewar->flags & 2)
		{	
			c = getch();
			if (c == 32)
			{
				c = '\0';
				while (c != 32)
		    		c = getch();
		    	c = '\0';
			}
			else if (c == '+' && corewar->vis->speed > 100)
				corewar->vis->speed -= 100;
			else if (c == '-' && corewar->vis->speed < 10000)
				corewar->vis->speed += 100;
			mvwprintw(corewar->vis->info, 4, 21, "%i", i);
			mvwprintw(corewar->vis->info, 6, 21, "%i", corewar->cycle_to_die);
			wrefresh(corewar->vis->info);
		}
		i++;
	}
	player = check_winner(corewar->players, corewar->player_nbr);
	if (!(corewar->flags & 2))
		ft_printf("Winner %s\n", player.head->prog_name);
	if (corewar->flags == 2)
	{
		set_player_collor(player.id - 1, corewar, corewar->vis->info);
		mvwprintw(corewar->vis->info, 29, 5, "Winner player %i: %s", player.id, player.head->prog_name);
		wrefresh(corewar->vis->info);
		nodelay(stdscr, FALSE);
		c = '\0';
		while (c != 27)
		{
			mvwprintw(corewar->vis->help, 6, 5, "Press esc to exit.");
			wrefresh(corewar->vis->help);
			c = getch();
			if (c == 27)
			{
				delwin(corewar->vis->win);
				delwin(corewar->vis->help);
				delwin(corewar->vis->info);
	   	 		endwin();
			}
		}
		free(corewar->vis);
	}
}
