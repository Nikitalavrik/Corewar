/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:05:43 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/05 16:32:35 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		choose_flag(t_cw *corewar, char **argv, int *pos, int argc)
{
	int 	i;
	int		flag;
	char	*param;

	i = 1;
	flag = 0;
	param = argv[*pos];
	while (param[i])
	{
		if (param[i] == 'a')
			flag |= 1;
		else if (param[i] == 'v')
			flag |= 2;
		else if (param[i] == 'n')
			flag |= 4;
		else if (param[i] == 'o')
			flag |= 8;
		else if (param[i] == 'd')
		{
			flag |= 16;
			if (*pos + 1 == argc)
				print_error("Enter number of cycles");
			corewar->dump = ft_atoi(argv[*pos + 1]);
			(*pos) += 2;
		}
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
			players[player_id - 1].last_live = -1;
			players[player_id - 1].name = argv[++i];
		}
		i++;
	}
	return (players);
}

t_player	*fill_other_players(t_cw *corewar, int argc, char **argv, t_player *players)
{
	int i;
	int	player_id;

	i = 1;
	player_id = 0;
	while (argv[i] && i < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
			corewar->flags |= choose_flag(corewar, argv, &i, argc);
		if (i >= argc)
			break ;
		while (i < argc && !ft_strcmp(argv[i], "-n"))
			i += 3;
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
			corewar->flags |= choose_flag(corewar, argv, &i, argc);
		if (i >= argc)
			break ;
		if (argv[i] && argv[i][0] != '-')
		{
			while (players[player_id].id)
				player_id++;
			players[player_id].id = player_id + 1;
			players[player_id].last_live = -1;
			players[player_id].name = argv[i];
			player_id++;
		}
		i++;
	}
	return (players);
}

t_player	*parse_argv(t_cw *corewar, int argc, char ** argv)
{
	t_player	*players;

	players = ft_memalloc(sizeof(t_player) * MAX_PLAYERS);
	players = fill_n_flag(argc, argv, players);
	players = fill_other_players(corewar, argc, argv, players);
	check_uniq_name(players);
	return (players);
}
