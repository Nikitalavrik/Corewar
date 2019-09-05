/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:06:22 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/05 20:37:20 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

void	print_bytes(char *line, int count)
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

void	read_file(char *filename)
{
	int fd;
	header_t		*head;


	fd = open(filename, O_RDONLY);
	head = ft_memalloc(sizeof(header_t));
	read(fd, &head->magic, 4);
	head->magic = reverse_num(head->magic);
	ft_printf("magic head = %x\n", head->magic);
	if (head->magic != COREWAR_EXEC_MAGIC)
		print_error("Bad magic head");
	
	read(fd, &head->prog_name, PROG_NAME_LENGTH);
	ft_printf("prog_name ");
	print_bytes(head->prog_name, PROG_NAME_LENGTH);
	
	read(fd, &head->prog_size, 4);
	read(fd, &head->prog_size, 4);
	head->prog_size = reverse_num(head->prog_size);
	ft_printf("prog_size = %x\n", head->prog_size);
	
	read(fd, &head->comment, COMMENT_LENGTH);
	ft_printf("Comment ");
	print_bytes(head->comment, COMMENT_LENGTH);
}

void	parse_file(t_player *players)
{
	read_file(players[0].name);
	// int i;

	// i = 0;
	// while (i < MAX_PLAYERS && players[i].id)
	// {
	// 	read_file(players[i].name);
	// 	i++;
	// }
}