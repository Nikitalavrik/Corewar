/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/20 10:00:14 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(char *name)
{
	ft_printf("%s [[-n number] champion.cor -dump N | -v | -o | -l | -a] ...\n\
	\t-a\t: show aff output\n\
	\t-dump N\t: dump memory after N cycles\n\
	\t-l\t: show lives\n\
	\t-o\t: show operation and number of cycle\n\
	\t-v\t: vizualization\n\
	\t-n N\t: num of player\n", name);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_cw		*corewar;
	t_player	*players;

	g_id = 1;
	if (argc < 2)
		print_usage(argv[0]);
	corewar = ft_memalloc(sizeof(t_cw));
	corewar->cycle_to_die = CYCLE_TO_DIE;
	players = parse_argv(corewar, argc, argv);
	parse_file(corewar, players);
	cursor(corewar);
	engine(corewar);
	free_corewar(corewar);
	return (0);
}
