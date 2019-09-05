/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:06:04 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/05 17:07:09 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

t_player	*fill_n_flag(int argc, char **argv, t_player *players)
{
	int 		i;
	int			player_id;

	i = 0;
	while (argv[i] && i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			player_id = ft_atoi(argv[++i]);
			if (player_id > MAX_PLAYERS || player_id <= 0)
			{
				ft_printf("Bad player id %i\n", player_id);
				exit(0);
			}
			players[player_id - 1].id = player_id;
			players[player_id - 1].name = argv[++i];
		}
		i++;
	}
	return (players);
}

t_player	*fill_other_players(int argc, char **argv, t_player *players)
{
	int i;
	int	player_id;

	i = 1;
	player_id = 0;
	while (argv[i] && i < argc)
	{
		while (i < argc && !ft_strcmp(argv[i], "-n"))
			i += 3;
		if (i >= argc)
			break ;
		while (players[player_id].id)
			player_id++;
		players[player_id].id = player_id + 1;
		players[player_id].name = argv[i];
		player_id++;
		i++;
	}
	return (players);
}

t_player	*parse_argv(int argc, char ** argv)
{
	t_player	*players;

	players = ft_memalloc(sizeof(t_player) * MAX_PLAYERS);
	players = fill_n_flag(argc, argv, players);
	players = fill_other_players(argc, argv, players);
	
	out_players(players);
	return (players);
}
