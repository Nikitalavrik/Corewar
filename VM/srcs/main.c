/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/08 15:43:49 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	map_init(t_cw *cw)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		cw->map[i] = 0;
		i++;
	}
}

int		parse_champ(char *param)
{
	ft_printf("%s\n", param);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cw		*cw;

	if (argc < 2)
		print_error("Please put champions!");
	cw = ft_memalloc(sizeof(t_cw));
	cw->players = parse_argv(argc, argv);
	parse_file(cw->players);
	map_init(cw);
	return (0);
}
