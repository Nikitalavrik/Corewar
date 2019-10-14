/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:11:35 by tbratsla          #+#    #+#             */
/*   Updated: 2019/10/04 16:25:06 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			draw_player(unsigned char *area, int i,\
				unsigned int prog_size, t_cw *corewar)
{
	int				j;
	unsigned int	k;

	k = 0;
	j = i % 64;
	i = i / 64;
	wmove(corewar->vis->win, i + 2, (5 + j * 3));
	while (i < 64)
	{
		while (j < 64 && k < prog_size)
		{
			wprintw(corewar->vis->win, "%.2x ", area[i * 64 + j]);
			corewar->vis->map[i * 64 + j] = corewar->vis->player;
			j++;
			k++;
		}
		if (k < prog_size)
			wprintw(corewar->vis->win, "\n");
		else
			break ;
		i++;
		wmove(corewar->vis->win, i + 2, 5);
		j = 0;
	}
	draw_box(corewar);
}

void			draw_map(t_cw *corewar)
{
	int		k;
	int		j;

	wattron(corewar->vis->win, COLOR_PAIR(COLOR_BLACK));
	k = 0;
	while (k < 64)
	{
		wmove(corewar->vis->win, k + 2, 5);
		j = 0;
		while (j < 64)
		{
			cursor_color_to_player(k * 64 + j, corewar);
			wprintw(corewar->vis->win, "%.2x ", corewar->map[k * 64 + j]);
			j++;
		}
		wprintw(corewar->vis->win, "\n");
		k++;
	}
	draw_box_and_words(corewar);
}

void			draw_cursor(int pos, t_cursor *start, t_cw *corewar,\
				t_cursor *cursor)
{
	t_cursor	*begin;
	int			i[2];

	i[0] = start->position / 64;
	i[1] = start->position % 64;
	set_cursor_color_by_pos(corewar, start);
	mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x",\
		corewar->map[i[0] * 64 + i[1]]);
	begin = cursor;
	while (begin)
	{
		if (begin->position == pos)
			break ;
		begin = begin->next;
	}
	if (!begin)
	{
		cursor_color_to_player(pos, corewar);
		i[0] = pos / 64;
		i[1] = pos % 64;
		mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x",\
			corewar->map[i[0] * 64 + i[1]]);
	}
	wrefresh(corewar->vis->win);
	usleep(corewar->vis->speed);
}

void			draw_player_name(char *prog_name, t_cw *corewar)
{
	int i;
	int n;

	i = 0;
	n = 0;
	mvwprintw(corewar->vis->info, 14 + corewar->vis->player * 3, 5,\
		"Player %i:", corewar->vis->player);
	mvwprintw(corewar->vis->info, 15 + corewar->vis->player * 3, 5,\
		"Last live:");
	while (prog_name[i])
	{
		mvwprintw(corewar->vis->info, 14 + corewar->vis->player * 3\
			+ n, 16 + i % 47, "%c", prog_name[i]);
		if (i > 30)
		{
			mvwprintw(corewar->vis->info, 14 + corewar->vis->player\
				* 3 + n, 16 + i % 47, "...");
			break ;
		}
		i++;
	}
	wrefresh(corewar->vis->info);
}

void			after_game(t_cw *corewar, t_player player, char c)
{
	mvwprintw(corewar->vis->info, 14, 21, "0  ");
	set_player_collor(player.id - 1, corewar, corewar->vis->info);
	mvwprintw(corewar->vis->info, 29, 5, "Winner player %i: %s",\
		player.id, player.head->prog_name);
	wrefresh(corewar->vis->info);
	nodelay(stdscr, FALSE);
	c = '\0';
	while (c != 27)
	{
		system("afplay music/sound.mp3&");
		system("killall afplay");
		system("afplay music/winner.mp3&");
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
	system("killall afplay");
	free(corewar->vis);
}
