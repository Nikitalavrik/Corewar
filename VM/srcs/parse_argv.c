/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:05:43 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 16:50:31 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*save_player(int *player_id, t_player *players, char *name)
{
	players[*player_id].id = *player_id + 1;
	players[*player_id].last_live = -1;
	players[*player_id].name = name;
	*player_id += 1;
	return (players);
}

t_player	*fill_n_flag(int argc, char **argv, t_player *players)
{
	int	i;
	int	player_id;

	i = 0;
	while (argv[i] && i < argc)
	{
		if (!ft_strcmp(argv[i], "-n"))
		{
			if (argv[i + 1])
			{
				player_id = ft_atoi(argv[++i]);
				if (player_id > MAX_PLAYERS || player_id <= 0\
				|| check_uniq_id(players, player_id))
					print_error(ft_itoa(player_id), ": Bad player number\n");
				player_id--;
				players = save_player(&player_id, players, argv[++i]);
			}
			else
				print_error("", "Enter number of player\n");
		}
		i++;
	}
	return (players);
}

t_player	*fill_other_players(t_cw *corewar, int argc, char **argv,
														t_player *players)
{
	int i;
	int	player_id;

	i = 1;
	player_id = 0;
	while (argv[i] && i < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
			choose_flag(corewar, argv, &i, argc);
		while (i < argc && !ft_strcmp(argv[i], "-n"))
			i += 3;
		if (argv[i] && argv[i][0] == '-' && ft_strcmp(argv[i], "-n"))
			choose_flag(corewar, argv, &i, argc);
		if (i >= argc)
			break ;
		if (argv[i] && argv[i][0] != '-')
		{
			while (players[player_id].id)
				player_id++;
			players = save_player(&player_id, players, argv[i]);
		}
		i++;
	}
	return (players);
}

t_player	*parse_argv(t_cw *corewar, int argc, char **argv)
{
	t_player	*players;

	players = ft_memalloc(sizeof(t_player) * MAX_PLAYERS);
	players = fill_n_flag(argc, argv, players);
	players = fill_other_players(corewar, argc, argv, players);
	check_uniq_name(players);
	return (players);
}
