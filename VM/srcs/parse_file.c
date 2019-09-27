/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:06:22 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/27 16:46:10 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	reverse_num(unsigned int num)
{
	unsigned int	reversed;

	reversed = 0;
	reversed += num >> 24;
	reversed += num << 8 >> 24 << 8;
	reversed += num << 16 >> 24 << 16;
	return (reversed);
}

header_t	*read_file(char *filename, unsigned char *area, int i, t_cw *corewar)
{
	int fd;
	unsigned int null_byte;
	header_t		*head;


	null_byte = 0;
	fd = open(filename, O_RDONLY);
	head = ft_memalloc(sizeof(header_t));
	read(fd, &head->magic, 4);
	head->magic = reverse_num(head->magic);
	if (head->magic != COREWAR_EXEC_MAGIC)
		print_error("Bad magic head");
	read(fd, &head->prog_name, PROG_NAME_LENGTH);
	// if (!head->prog_name)
	// 	print_error("Noname champion");
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("Bad file");
	read(fd, &head->prog_size, 4);
	head->prog_size = reverse_num(head->prog_size);
	if (head->prog_size > CHAMP_MAX_SIZE)
		print_error("Big size");
	read(fd, &head->comment, COMMENT_LENGTH);
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("Bad file");
	read(fd, &area[i], head->prog_size);
	if (corewar->flags == 2)
	{
		draw_player(area, i, head->prog_size, corewar);
		draw_player_name(head->prog_name, corewar);
	}
	return (head);
}


int		count_players(t_player *players)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS && players[i].id)
		i++;
	return (i);
}

t_cw	*parse_file(t_player *players, int flags)
{
	t_cw	*corewar;
	int		i;
	int		place;
	int		diff;

	i = 0;
	place = 0;
	corewar = ft_memalloc(sizeof(t_cw));
	corewar->flags = flags;
	corewar->player_nbr = count_players(players);
	corewar->players = players;
	diff = MEM_SIZE / corewar->player_nbr;
	ft_bzero(corewar->map, MEM_SIZE);
	if (corewar->flags == 2)
	{
		vis_init(corewar);
		draw_map(corewar);
	}
	while (i < corewar->player_nbr)
	{
		if (corewar->flags == 2)
			set_player_collor(i, corewar, corewar->vis->win);
		players[i].head = read_file(players[i].name, corewar->map, place, corewar);
		if (corewar->flags == 2)
			reset_player_collor(i, corewar);
		else
			ft_printf("* Player %i, weight %2i bytes, %10s, %s\n", i + 1,\
		players[i].head->prog_size, players[i].head->prog_name,\
		players[i].head->comment);
		place += diff;
		i++;
	}
	return (corewar);
}