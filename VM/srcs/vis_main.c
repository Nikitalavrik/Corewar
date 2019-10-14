/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:55:15 by tbratsla          #+#    #+#             */
/*   Updated: 2019/10/11 13:55:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			vis_init(t_cw *corewar)
{
	system("printf '\033[8;76;362t' && printf '\e[3;0;0t' && sleep 1");
	initscr();
	curs_set(0);
	refresh();
	noecho();
	corewar->vis = ft_memalloc(sizeof(t_vis));
	corewar->vis->speed = 11000;
	corewar->vis->cols = 362;
	corewar->vis->lines = 76;
	corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
	corewar->vis->info = newwin(HEIGHT / 2, 64, 1, WIDTH + 5);
	corewar->vis->help = newwin(HEIGHT / 2 + 1, 64, HEIGHT / 2, WIDTH + 5);
	ft_bzero(corewar->vis->map, MEM_SIZE);
	corewar->vis->player = 0;
	ft_init_colors();
	system("afplay music/sound.mp3&");
}

void			ft_init_colors(void)
{
	start_color();
	has_colors();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLUE, COLOR_YELLOW);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
	init_pair(12, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_WHITE, COLOR_WHITE);
}

void			ft_check_size_win(t_cw *corewar, int *i)
{
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
		reinit_win(corewar, i);
	}
}

void			reinit_win(t_cw *corewar, int *i)
{
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
	while (*i < corewar->player_nbr)
	{
		corewar->vis->player = (*i) + 1;
		draw_player_name(corewar->players[*i].head->prog_name, corewar);
		(*i)++;
	}
	corewar->vis->player = 0;
	wrefresh(corewar->vis->win);
	wrefresh(corewar->vis->help);
	wrefresh(corewar->vis->info);
}

void			draw_cursor_count(t_cw *corewar, int count, int i)
{
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
