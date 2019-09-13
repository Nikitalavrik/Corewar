/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:07:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 15:38:38 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

// unsigned	char check_type(unsigned type)

int		check_operation(t_cw *corewar, t_cursor *cursor, int op)
{
	g_func[op - 1](corewar, cursor, g_op_tab[op - 1]);
	// exit(0);
	// sleep(1);
	return (op);
}

int		check_uniq_id(t_player *players, int id)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (players[i].id == id)
			return (1);
		i++;
	}
	return (0);
}

void	check_uniq_name(t_player *players)
{
	int	i;

	i = MAX_PLAYERS - 1;
	while (i > 0 && !players[i].id)
		i--;
	while (i >= 0)
	{
		if (!players[i].name)
			print_error("Bad player number");
		if (ft_strcmp(players[i].name + ft_get_index(players[i].name, '.'), "cor"))
			print_error("Bad filename");
		i--;
	}
}
