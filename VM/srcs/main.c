/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 14:02:56 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_cw		*cw;
	t_player	*players;
	int			flags;

	if (argc < 2)
		print_error("Please put champions!");
	flags = 0;
	players = parse_argv(argc, argv, &flags);
	cw = parse_file(players);
	cw->flags = flags;
	cursor(cw);
	engine(cw);
	return (0);
}
