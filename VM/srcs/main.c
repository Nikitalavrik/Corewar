/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/05 18:07:25 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		parse_champ(char *param)
{
	ft_printf("%s\n", param);
	return (1);
}

int		main(int argc, char **argv)
{
	t_player	*players;

	if (argc < 2)
		print_error("Please put champions!");
	players = parse_argv(argc, argv);
	parse_file(players);
	return (0);
}
