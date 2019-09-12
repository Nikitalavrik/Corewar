/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:55:15 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/11 10:55:16 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define HEIGHT					(MEM_SIZE / 64 + 4)
# define WIDTH					(64 * 3 + 5)
#include "corewar.h"

void	vis_init(t_cw *corewar)
{
	initscr();
    curs_set(0);
    refresh();
	corewar->vis = ft_memalloc(sizeof(t_vis));
	corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);

}