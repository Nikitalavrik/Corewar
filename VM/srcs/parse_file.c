/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:06:22 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/08 16:19:31 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_bytes(unsigned char *line, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_printf("%x ", line[i]);
		i++;
	}
	ft_printf("\n");
}

unsigned int	reverse_num(unsigned int num)
{
	unsigned int	reversed;

	reversed = 0;
	reversed += num >> 24;
	reversed += num << 8 >> 24 << 8;
	reversed += num << 16 >> 24 << 16;
	return (reversed);
}

header_t	*read_file(char *filename, unsigned char *area, int i)
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
	print_bytes((unsigned char *)head->prog_name, PROG_NAME_LENGTH);
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("Bad file");
	read(fd, &head->prog_size, 4);
	head->prog_size = reverse_num(head->prog_size);
	read(fd, &head->comment, COMMENT_LENGTH);
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("Bad file");
	read(fd, &area[i], head->prog_size);
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

t_cw	*parse_file(t_player *players)
{
	t_cw	*corewar;
	int		i;
	int		place;
	int		diff;

	i = 0;
	place = 0;
	corewar = ft_memalloc(sizeof(t_cw));
	corewar->player_nbr = count_players(players);
	corewar->players = players;
	diff = MEM_SIZE / corewar->player_nbr;
	ft_bzero(corewar->map, MEM_SIZE);
	while (i < corewar->player_nbr)
	{
		players[i].head = read_file(players[i].name, corewar->map, place);
		place += (diff + 1);
		i++;
	}
	print_bytes(corewar->map, MEM_SIZE);
	return (corewar);
}