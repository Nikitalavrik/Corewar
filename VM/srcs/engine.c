/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:16:51 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/10 13:42:25 by nlavrine         ###   ########.fr       */
/*   Updated: 2019/09/13 18:22:11 by nlavrine         ###   ########.fr       */
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
	// check if cursor is live(if not we del it)
	while (start)
	{
		next = start->next;
		if (start->cycles_num > corewar->cycle_to_die)
			del_cursor(&start, &prev, &corewar->cursor);
		else
			live_process++;
		prev = start;
		start = next;
	}
	// check if we need to reduce cycle_to_die
	if (live_process >= NBR_LIVE || corewar->check_cycle > MAX_CHECKS)
	{
		corewar->cycle_to_die -= CYCLE_DELTA;
		corewar->check_cycle = corewar->check_cycle > MAX_CHECKS ? 0 :\
		corewar->check_cycle;
	}
	else
	{
		corewar->check_cycle++;
	}
	if (corewar->cursor == NULL)
		return (1);
	return (0);
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
		// ft_printf("g_i = %i\n", g_i);
		check_operation(corewar, cursor, op);
		cursor->is_wait = 0;
	}
	// ft_printf("cursor id %i do %s op %i\n", cursor->id, g_op_tab[op - 1].func_name, op);
	return (0);
}

void	iterate_all_cursors(t_cw *corewar, t_cursor *cursor)
{
	t_cursor	*start;
	int			pos;

	pos = 0;
	start = cursor;
	while (start)
	{
		pos = start->position;
		start->position += do_op(corewar, start);
		start->position %= MEM_SIZE;
		start->cycles_num++;
		start->remaining_cycles--;
		if (corewar->flags == 2)
			draw_cursor(pos, start, corewar, cursor);
		start = start->next;
	}
}

void	engine(t_cw *corewar)
{
	int		i;
	char	c;
	int		tmp_die;

	i = 0;
	tmp_die = 0;
	corewar->cycle_to_die = CYCLE_TO_DIE;
	// out_print_bytes(corewar->map, MEM_SIZE);
	c = '\0';
	if (corewar->flags == 2)
		while (c != 32)
		{
		    c = getch();
		    if (c == 32)
		    {
		        delwin(corewar->vis->win);
		        endwin();
		    }
		}
	while (1)
	{
		g_i = i;
		iterate_all_cursors(corewar, corewar->cursor);
		if (tmp_die >= corewar->cycle_to_die)
		{
			// out_print_bytes(corewar->map, MEM_SIZE);
			// if (check_cycle_to_die(corewar))
			// out_print_bytes(corewar->map, MEM_SIZE);
			// ft_printf("CHECK %i\n", corewar->cycle_to_die);

			if ((tmp_die = check_cycle_to_die(corewar)))
				break ;
			tmp_die = 0;
		}
		else
			tmp_die++;
		i++;
		mvwprintw(corewar->vis->info, 4, 21, "%i", i);
		mvwprintw(corewar->vis->info, 6, 21, "%i", corewar->cycle_to_die - tmp_die);
		wrefresh(corewar->vis->info);
		// draw_map(corewar);
	}
	// wprintw(corewar->vis->win, "Press q to exit ");
	// wrefresh(corewar->vis->win);
	c = '\0';
	if (corewar->flags == 2)
	{
		while (c != 27)
		{
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
