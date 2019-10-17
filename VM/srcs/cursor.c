/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:44:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/10/14 13:39:02 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_cursor(t_cw *cw, int i)
{
	int			j;
	t_cursor	*tmp;

	j = 1;
	tmp = cw->cursor;
	cw->cursor = ft_memalloc(sizeof(t_cursor));
	cw->cursor->next = tmp;
	cw->cursor->id = i;
	cw->cursor->player_nbr = i;
	cw->cursor->carry = 0;
	cw->cursor->reg[0] = -i;
	cw->cursor->position = (MEM_SIZE / cw->player_nbr * (i - 1));
	cw->cursor->cycles_num = 0;
}

void	cursor(t_cw *cw)
{
	int	i;

	cw->cursor = NULL;
	i = 1;
	while (i <= cw->player_nbr)
	{
		add_cursor(cw, i);
		i++;
	}
	g_id = cw->player_nbr;
}

void	del_vizual(t_cursor **cursor, t_cursor **main_cursor, t_cw *corewar)
{
	int			count;
	int			i[2];
	t_cursor	*begin;

	count = 0;
	begin = *main_cursor;
	while (begin)
	{
		if (begin->position == (*cursor)->position)
			count++;
		begin = begin->next;
	}
	if (count == 1)
	{
		cursor_color_to_player((*cursor)->position, corewar);
		i[0] = (*cursor)->position / 64;
		i[1] = (*cursor)->position % 64;
		mvwprintw(corewar->vis->win, i[0] + 2, 3 * i[1] + 5, "%.2x",
											corewar->map[i[0] * 64 + i[1]]);
	}
}

int		del_cursor(t_cursor **cursor, t_cursor **prev,
										t_cursor **main_cursor, t_cw *corewar)
{
	int			id;

	if (corewar->flags & 2)
		del_vizual(cursor, main_cursor, corewar);
	id = (*cursor) ? (*cursor)->player_nbr : 0;
	if (*prev)
		(*prev)->next = (*cursor)->next;
	if (*cursor == *main_cursor)
		*main_cursor = *prev ? *prev : (*main_cursor)->next;
	if (*cursor)
		ft_memdel((void **)cursor);
	return (id);
}

void	copy_cursor(t_cursor *src, t_cursor *dist)
{
	int	i;

	i = 0;
	dist->carry = src->carry;
	dist->cycles_num = src->cycles_num;
	dist->player_nbr = src->player_nbr;
	while (i < 16)
	{
		dist->reg[i] = src->reg[i];
		i++;
	}
}
