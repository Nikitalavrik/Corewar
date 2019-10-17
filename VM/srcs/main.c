/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 15:31:54 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 11:36:09 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
<<<<<<< HEAD
	t_cw		*corewar;
	t_player	*players;
=======
	t_cw		*cw;
	t_player	*players;
	int			flags;
>>>>>>> master

	g_id = 1;
	if (argc < 2)
		print_error("Please put champions!");
<<<<<<< HEAD
	corewar = ft_memalloc(sizeof(t_cw));
	corewar->cycle_to_die = CYCLE_TO_DIE;
	players = parse_argv(corewar, argc, argv);
	parse_file(corewar, players);
	cursor(corewar);
	engine(corewar);
	free_corewar(corewar);
=======
	flags = 0;
	players = parse_argv(argc, argv, &flags);
	cw = parse_file(players, flags);
	cursor(cw);
	engine(cw);
>>>>>>> master
	return (0);
}
