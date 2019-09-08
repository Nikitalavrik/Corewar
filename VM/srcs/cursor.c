/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:44:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/07 11:44:04 by tbratsla         ###   ########.fr       */
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
	cw->cursor->reg[0] = -id;
	while (j < REG_NUMBER)
	{
		cw->cursor->reg[j] = 0;
		j++;
	}
	cw->cursor->position = MEM_SIZE / cw->position * (i - 1);
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
}