/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:06:04 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/05 17:40:55 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

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

int			check_uniq_name(t_player *players)
{
	int	i;
	int	j;

	i = MAX_PLAYERS - 1;
	while (i > 0 && !players[i].id)
		i--;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (!players[i].name || !ft_strcmp(players[i].name, players[j].name))
				return (1);
			j--;
		}
		i--;
	}
	return (0);
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
	if (check_uniq_name(players))
	{
		ft_printf("Bad filename\n");
		exit(0);
	}
	out_players(players);
	return (players);
}
