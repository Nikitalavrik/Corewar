/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:44:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/09 12:16:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_cursor(t_cw *cw, int i)
{
	int			j;
	t_cursor	*tmp;

	j = 1;
	tmp = cw->cursor;
	cw->cursor = ft_memalloc(sizeof(t_cursor));
	cw->cursor->next = tmp;
	cw->cursor->id = i;
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
		init_cursor(cw, i);
		i++;
	}
	out_cursor(cw->cursor);
}

void	del_cursor(t_cursor **cursor, t_cursor **prev, t_cursor **main_cursor)
{
	if (*prev)
		*prev = (*cursor)->next;
	if (*cursor == *main_cursor)
		*main_cursor = *prev;
	if (*cursor)
		ft_memdel((void **)cursor);
}