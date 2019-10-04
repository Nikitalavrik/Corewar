/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:52:54 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/04 18:07:40 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump(unsigned char *map)
{
	int row;
	int	column;

	row = 0;
	while (row < 64)
	{
		column = 0;
		// ft_printf("0x");
		// if (row)
		// ft_printf("%#.4x: ", row * 64);
		row ? ft_printf("%#.4x : ", row * 64) : ft_printf("0x0000 : ");
		while (column < 64)
		{
			ft_printf("%.2x ", map[row * 64 + column]);
			column++;
		}
		ft_printf("\n");
		row++;
	}
}