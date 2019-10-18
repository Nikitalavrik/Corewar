/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:06:22 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 16:24:08 by nlavrine         ###   ########.fr       */
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

void			read_program(t_header *head, int fd, unsigned char *area, int i)
{
	int		null_byte;

	null_byte = 0;
	read(fd, &head->magic, 4);
	head->magic = reverse_num(head->magic);
	if (head->magic != COREWAR_EXEC_MAGIC)
		print_error("Bad magic head\n");
	read(fd, &head->prog_name, PROG_NAME_LENGTH);
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("After PROG_NAME_LENGTH no null byte\n");
	read(fd, &head->prog_size, 4);
	head->prog_size = reverse_num(head->prog_size);
	if (head->prog_size > CHAMP_MAX_SIZE)
		print_error("Big champion size\n");
	read(fd, &head->comment, COMMENT_LENGTH);
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("After COMMENT_LENGTH no null byte\n");
	read(fd, &area[i], head->prog_size);
}

t_header		*read_file(char *filename, unsigned char *area,
														int i, t_cw *corewar)
{
	int				fd;
	t_header		*head;

	head = NULL;
	fd = init_file(filename, &head);
	read_program(head, fd, area, i);
	if (corewar->flags & 2)
	{
		draw_player(area, i, head->prog_size, corewar);
		draw_player_name(head->prog_name, corewar);
	}
	return (head);
}

t_cw			*parse_file(t_cw *corewar, t_player *players)
{
	int		i;
	int		place;
	int		diff;

	i = 0;
	place = 0;
	init_corewar(corewar, players);
	diff = MEM_SIZE / corewar->player_nbr;
	while (i < corewar->player_nbr)
	{
		if (corewar->flags & 2)
			set_player_collor(i, corewar, corewar->vis->win);
		players[i].head = read_file(players[i].name,
										corewar->map, place, corewar);
		if (corewar->flags & 2)
			reset_player_collor(i, corewar);
		else
			ft_printf("* Player %i, weighing %2i bytes, \"%s\" (\"%s\") !\n",
			i + 1, players[i].head->prog_size, players[i].head->prog_name,\
												players[i].head->comment);
		place += diff;
		i++;
	}
	return (corewar);
}
