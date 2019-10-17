/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:05:43 by nlavrine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 18:26:46 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/13 18:05:35 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
t_player	*save_player(int *player_id, t_player *players, char *name)
{
	players[*player_id].id = *player_id + 1;
	players[*player_id].last_live = -1;
	players[*player_id].name = name;
	*player_id += 1;
	return (players);
=======
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
		else if (param[i] == 'o')
			flag |= 8;
		else
			print_error("Unexpected flag");
		i++;
	}
	return (flag);
>>>>>>> master
}

t_player	*fill_n_flag(int argc, char **argv, t_player *players)
{
<<<<<<< HEAD
	int	i;
	int	player_id;
=======
	int 		i;
	int			player_id;
>>>>>>> master

	i = 0;
	while (argv[i] && i < argc)
	{
<<<<<<< HEAD
		if (!ft_strcmp(argv[i], "-n"))
		{
			if (argv[i + 1])
			{
				player_id = ft_atoi(argv[++i]);
				if (player_id > MAX_PLAYERS || player_id <= 0\
				|| check_uniq_id(players, player_id))
					print_error("Bad player number");
				player_id--;
				players = save_player(&player_id, players, argv[++i]);
			}
			else
				print_error("Enter number of player");
=======
		if (!ft_strcmp(argv[i], "-n") && argv[i + 1])
		{
			player_id = ft_atoi(argv[++i]);
			if (player_id > MAX_PLAYERS || player_id <= 0\
			|| check_uniq_id(players, player_id))
				print_error("Bad player number");
			players[player_id - 1].id = player_id;
			players[player_id - 1].name = argv[++i];
>>>>>>> master
		}
		i++;
	}
	return (players);
}

<<<<<<< HEAD
t_player	*fill_other_players(t_cw *corewar, int argc, char **argv,
														t_player *players)
=======
t_player	*fill_other_players(int argc, char **argv, t_player *players, int *flags)
>>>>>>> master
{
	int i;
	int	player_id;

	i = 1;
	player_id = 0;
	while (argv[i] && i < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
<<<<<<< HEAD
			choose_flag(corewar, argv, &i, argc);
		while (i < argc && !ft_strcmp(argv[i], "-n"))
			i += 3;
		if (argv[i] && argv[i][0] == '-' && ft_strcmp(argv[i], "-n"))
			choose_flag(corewar, argv, &i, argc);
=======
			*flags |= choose_flag(argv[i]);
		while (i < argc && !ft_strcmp(argv[i], "-n"))
			i += 3;
		if (argv[i] && argv[i][0] == '-' && argv[i][1] != 'n')
			*flags |= choose_flag(argv[i]);
>>>>>>> master
		if (i >= argc)
			break ;
		if (argv[i] && argv[i][0] != '-')
		{
			while (players[player_id].id)
				player_id++;
<<<<<<< HEAD
			players = save_player(&player_id, players, argv[i]);
=======
			players[player_id].id = player_id + 1;
			players[player_id].name = argv[i];
			player_id++;
>>>>>>> master
		}
		i++;
	}
	return (players);
}

<<<<<<< HEAD
t_player	*parse_argv(t_cw *corewar, int argc, char **argv)
=======
t_player	*parse_argv(int argc, char ** argv, int *flags)
>>>>>>> master
{
	t_player	*players;

	players = ft_memalloc(sizeof(t_player) * MAX_PLAYERS);
	players = fill_n_flag(argc, argv, players);
<<<<<<< HEAD
	players = fill_other_players(corewar, argc, argv, players);
	check_uniq_name(players);
=======
	players = fill_other_players(argc, argv, players, flags);
	check_uniq_name(players);
	// out_players(players);
>>>>>>> master
	return (players);
}
