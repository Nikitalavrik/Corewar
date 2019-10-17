/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:36:23 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/15 15:36:24 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_player_collor(int i, t_cw *corewar, WINDOW *win)
{
	if (i == 0)
	{
		corewar->vis->player = 1;
		wattron(win, COLOR_PAIR(2));
	}
	else if (i == 1)
	{
		corewar->vis->player = 2;
		wattron(win, COLOR_PAIR(4));
	}
	else if (i == 2)
	{
		corewar->vis->player = 3;
		wattron(win, COLOR_PAIR(1));
	}
	else if (i == 3)
	{
		corewar->vis->player = 4;
		wattron(win, COLOR_PAIR(3));
	}
}

void	reset_player_collor(int i, t_cw *corewar)
{
	if (i == 0)
		wattroff(corewar->vis->win, COLOR_PAIR(2));
	else if (i == 1)
		wattroff(corewar->vis->win, COLOR_PAIR(4));
	else if (i == 2)
		wattroff(corewar->vis->win, COLOR_PAIR(1));
	else if (i == 3)
		wattroff(corewar->vis->win, COLOR_PAIR(3));
	corewar->vis->player = 0;
}

void	cursor_color_to_player(int pos, t_cw *corewar)
{
	if (corewar->vis->map[pos] == 1)
		wattron(corewar->vis->win, COLOR_PAIR(2));
	if (corewar->vis->map[pos] == 2)
		wattron(corewar->vis->win, COLOR_PAIR(4));
	if (corewar->vis->map[pos] == 3)
		wattron(corewar->vis->win, COLOR_PAIR(1));
	if (corewar->vis->map[pos] == 4)
		wattron(corewar->vis->win, COLOR_PAIR(3));
	if (corewar->vis->map[pos] == 0)
		wattron(corewar->vis->win, COLOR_PAIR(11));
}

void	set_color_by_cursor(t_cw *corewar, t_cursor *cursor)
{
	if (cursor->player_nbr == 1)
		wattron(corewar->vis->win, COLOR_PAIR(2));
	if (cursor->player_nbr == 2)
		wattron(corewar->vis->win, COLOR_PAIR(4));
	if (cursor->player_nbr == 3)
		wattron(corewar->vis->win, COLOR_PAIR(1));
	if (cursor->player_nbr == 4)
		wattron(corewar->vis->win, COLOR_PAIR(3));
}

void	set_cursor_color_by_pos(t_cw *corewar, t_cursor *start)
{
	if (corewar->vis->map[start->position] == 1)
		wattron(corewar->vis->win, COLOR_PAIR(6));
	if (corewar->vis->map[start->position] == 2)
		wattron(corewar->vis->win, COLOR_PAIR(8));
	if (corewar->vis->map[start->position] == 3)
		wattron(corewar->vis->win, COLOR_PAIR(5));
	if (corewar->vis->map[start->position] == 4)
		wattron(corewar->vis->win, COLOR_PAIR(7));
	if (corewar->vis->map[start->position] == 0)
		wattron(corewar->vis->win, COLOR_PAIR(14));
}
