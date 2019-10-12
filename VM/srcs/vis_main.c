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
#define HEIGHT	(MEM_SIZE / 64 + 4)
#define WIDTH	(64 * 3 + 5)

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
	// system("afplay music/sound.mp3&");
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
