/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 16:12:31 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(void)
{
	ft_printf("./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_cw		*corewar;
	t_player	*players;

	g_id = 1;
	if (argc < 2)
		print_usage();
	corewar = ft_memalloc(sizeof(t_cw));
	corewar->cycle_to_die = CYCLE_TO_DIE;
	players = parse_argv(corewar, argc, argv);
	parse_file(corewar, players);
	cursor(corewar);
	engine(corewar);
	free_corewar(corewar);
	return (0);
}
