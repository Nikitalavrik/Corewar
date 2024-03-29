/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box_and_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:07:11 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/29 13:07:12 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			draw_box(t_cw *corewar)
{
	wattron(corewar->vis->win, COLOR_PAIR(14));
	box(corewar->vis->win, 0, 0);
	wattroff(corewar->vis->win, COLOR_PAIR(14));
	wrefresh(corewar->vis->win);
}

void			draw_box_and_words(t_cw *corewar)
{
	wattron(corewar->vis->info, COLOR_PAIR(1));
	mvwprintw(corewar->vis->info, 2, 28, "STATUS");
	wattroff(corewar->vis->info, COLOR_PAIR(1));
	mvwprintw(corewar->vis->info, 4, 5, "Cycles: ");
	mvwprintw(corewar->vis->info, 6, 5, "Cycles to die: ");
	mvwprintw(corewar->vis->info, 8, 5, "Cycle delta: ");
	mvwprintw(corewar->vis->info, 8, 21, "%i", CYCLE_DELTA);
	mvwprintw(corewar->vis->info, 10, 5, "Nbr LIVE: ");
	mvwprintw(corewar->vis->info, 10, 21, "%i", NBR_LIVE);
	mvwprintw(corewar->vis->info, 12, 5, "Max cheks: ");
	mvwprintw(corewar->vis->info, 12, 21, "%i", MAX_CHECKS);
	wattron(corewar->vis->win, COLOR_PAIR(14));
	box(corewar->vis->win, 0, 0);
	wattroff(corewar->vis->win, COLOR_PAIR(14));
	wrefresh(corewar->vis->win);
	draw_box_and_words2(corewar);
}

void			draw_box_and_words2(t_cw *corewar)
{
	wattron(corewar->vis->info, COLOR_PAIR(14));
	box(corewar->vis->info, 0, 0);
	wattroff(corewar->vis->info, COLOR_PAIR(14));
	wrefresh(corewar->vis->info);
	wattron(corewar->vis->help, COLOR_PAIR(14));
	box(corewar->vis->help, 0, 0);
	wattroff(corewar->vis->help, COLOR_PAIR(14));
	wattron(corewar->vis->help, COLOR_PAIR(1));
	mvwprintw(corewar->vis->help, 2, 25, "INFORMATION");
	wattroff(corewar->vis->help, COLOR_PAIR(1));
	mvwprintw(corewar->vis->help, 4, 5, "Press spase to start or to pause.");
	mvwprintw(corewar->vis->info, 14, 5, "Processes: ");
	mvwprintw(corewar->vis->help, 8, 5, "Press '+' to increase speed");
	mvwprintw(corewar->vis->help, 10, 5, "Press '-' to decrease speed");
	wrefresh(corewar->vis->info);
	wrefresh(corewar->vis->help);
}

void			add_speed_pause(t_cw *corewar, char c, int i)
{
	c = '\0';
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

void			check_dump_flag(t_cw *corewar, char c, int i)
{
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
}
