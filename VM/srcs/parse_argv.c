/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:05:43 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/13 15:38:21 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		choose_flag(char *param)
{
	int i;
	int	flag;

	i = 1;
	flag = 0;
	while (param[i])
	{
		if (param[i] == 'a')
			flag |= 1;
		else if (param[i] == 'v')
			flag |= 2;
		else if (param[i] == 'n')
			flag |= 4;
		else
			print_error("Unexpected flag");
		i++;
	}
	return (flag);
}

t_player	*fill_n_flag(int argc, char **argv, t_player *players)
{
	int 		i;
	int			player_id;

	i = 0;
	while (argv[i] && i < argc)
	{
		if (!ft_strcmp(argv[i], "-n") && argv[i + 1])
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

t_player	*fill_other_players(int argc, char **argv, t_player *players, int *flags)
{
	int i;
	int	player_id;

	i = 1;
	player_id = 0;
	while (argv[i] && i < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
			*flags |= choose_flag(argv[i]);
		while (i < argc && !ft_strcmp(argv[i], "-n"))
			i += 3;
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
			*flags |= choose_flag(argv[i]);
		if (i >= argc)
			break ;
		if (argv[i] && argv[i][0] != '-')
		{
			while (players[player_id].id)
				player_id++;
			players[player_id].id = player_id + 1;
			players[player_id].name = argv[i];
			player_id++;
		}
		i++;
	}
	return (players);
}

t_player	*parse_argv(int argc, char ** argv, int *flags)
{
	t_player	*players;

	players = ft_memalloc(sizeof(t_player) * MAX_PLAYERS);
	players = fill_n_flag(argc, argv, players);
	players = fill_other_players(argc, argv, players, flags);
	check_uniq_name(players);
	// out_players(players);
	return (players);
}
