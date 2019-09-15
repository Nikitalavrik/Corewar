/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:44:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/13 18:20:49 by nlavrine         ###   ########.fr       */
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
	cw->cursor->position = MEM_SIZE / cw->player_nbr * (i - 1);
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
	// out_cursor(cw->cursor);
}

int	del_cursor(t_cursor **cursor, t_cursor **prev, t_cursor **main_cursor)
{
	int id;

	// ft_printf("del = %i\n", (*cursor)->id);
	id = (*cursor) ? (*cursor)->player_nbr : 0;
	if (*prev)
		(*prev)->next = (*cursor)->next;
	if (*cursor == *main_cursor)
		*main_cursor = *prev;
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
