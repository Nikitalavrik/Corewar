/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:16:51 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/13 14:25:58 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"
#define HEIGHT					(MEM_SIZE / 64 + 4)
#define WIDTH					(64 * 3 + 5)

int		check_cycle_to_die(t_cw *corewar)
{
	t_cursor	*start;
	t_cursor	*prev;
	t_cursor	*next;

	start = corewar->cursor;
	prev = NULL;
	while (start)
	{
		next = start->next;
		if (start->cycles_num > corewar->cycle_to_die)
			del_cursor(&start, &prev, &corewar->cursor, corewar);
		prev = start ? start : prev;
		start = next;
	}
	if (corewar->live_process >= NBR_LIVE || corewar->check_cycle >= MAX_CHECKS)
	{
		corewar->cycle_to_die -= CYCLE_DELTA;
		corewar->check_cycle = corewar->check_cycle >= MAX_CHECKS ? 0 :\
		corewar->check_cycle;
	}
	else
		corewar->check_cycle++;
	corewar->live_process = 0;
	return (corewar->cursor == NULL ? 1 : 0);
}

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
			if (COLS != corewar->vis->cols || LINES != corewar->vis->lines)
			{
				delwin(corewar->vis->win);
				delwin(corewar->vis->help);
				delwin(corewar->vis->info);
				endwin();
				system("sleep 1");
				system("reset");
				system("clear");
				system("printf '\033[8;76;362t'"); 
				system("printf '\e[3;0;0t'");
				system("sleep 2");
				initscr();
				curs_set(0);
				refresh();
				noecho();
				corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
				corewar->vis->info = newwin(HEIGHT / 2, 64, 1, WIDTH + 5);
				corewar->vis->help = newwin(HEIGHT / 2 + 1, 64, HEIGHT / 2, WIDTH + 5);
				ft_init_colors();
				draw_map(corewar);
				draw_box_and_words(corewar);
				while (i < corewar->player_nbr)
				{
					corewar->vis->player = i + 1;
					draw_player_name(corewar->players[i].head->prog_name, corewar);
				 	i++;
				}
				corewar->vis->player = 0;
				wrefresh(corewar->vis->win);
				wrefresh(corewar->vis->help);
				wrefresh(corewar->vis->info);
			}
			count++;
		}
		start = start->next;
	}
	if (corewar->flags & 2)
	{
		 mvwprintw(corewar->vis->info, 14, 21, "%i  ", count);
		 i = 0;
		 while (i < corewar->player_nbr)
		 {
		 	mvwprintw(corewar->vis->info, 15 + corewar->vis->player * 3\
		 		+ (i + 1) * 3, 16, "%i", corewar->players[i].last_live);
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
	// out_cursor(corewar->cursor);
	c = '\0';
	if (corewar->flags & 2)
	{
		while (c != 32)
		    c = getch();
		c = '\0';
		nodelay(stdscr, TRUE);
	}
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
					mvwprintw(corewar->vis->info, 6, 21, "%i  ", corewar->cycle_to_die);
					wrefresh(corewar->vis->info);
				}
				break ;
			}
				
			tmp_die = 0;
		}
		if (i == corewar->dump && corewar->flags & 16)
		{
			if (!(corewar->flags & 2))
			{
				dump(corewar->map);
				exit(0);
			}
			else
			{
				mvwprintw(corewar->vis->info, 4, 21, "%i", i);
				mvwprintw(corewar->vis->info, 6, 21, "%i  ", corewar->cycle_to_die);
				wrefresh(corewar->vis->info);
				while (c != 32)
					c = getch();
			}
		}
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
			mvwprintw(corewar->vis->info, 6, 21, "%i  ", corewar->cycle_to_die);
			wrefresh(corewar->vis->info);
		}
	}
	if (corewar->flags & 8)
		ft_printf("i = %i\n", i);
	player = check_winner(corewar->players, corewar->player_nbr);
	if (!(corewar->flags & 2))
		ft_printf("Winner: Player %i \"%s\"\n", player.id, player.head->prog_name);
	if (corewar->flags & 2)
		after_game(corewar, player, c);
}
