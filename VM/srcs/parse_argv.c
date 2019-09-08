/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:05:43 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/08 17:17:56 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			check_uniq_id(t_player *players, int id)
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

void		check_uniq_name(t_player *players)
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
			if (player_id > MAX_PLAYERS || player_id <= 0\
			|| check_uniq_id(players, player_id))
				print_error("Bad player number");
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
	check_uniq_name(players);
	// out_players(players);
	return (players);
}
