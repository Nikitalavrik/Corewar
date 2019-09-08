/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:06:22 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/08 15:45:46 by nlavrine         ###   ########.fr       */
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

void	read_file(char *filename, unsigned char *area, int i)
{
	int fd;
	unsigned int null_byte;
	header_t		*head;


	null_byte = 0;
	fd = open(filename, O_RDONLY);
	head = ft_memalloc(sizeof(header_t));
	read(fd, &head->magic, 4);
	head->magic = reverse_num(head->magic);
	ft_printf("magic head = %x\n", head->magic);
	if (head->magic != COREWAR_EXEC_MAGIC)
		print_error("Bad magic head");
	
	read(fd, &head->prog_name, PROG_NAME_LENGTH);
	ft_printf("prog_name ");
	print_bytes((unsigned char *)head->prog_name, PROG_NAME_LENGTH);
	
	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("Bad file");

	read(fd, &head->prog_size, 4);
	head->prog_size = reverse_num(head->prog_size);
	ft_printf("prog_size = %x\n", head->prog_size);
	
	read(fd, &head->comment, COMMENT_LENGTH);
	ft_printf("Comment ");
	print_bytes((unsigned char *)head->comment, COMMENT_LENGTH);

	read(fd, &null_byte, 4);
	if (null_byte)
		print_error("Bad file");
	read(fd, &area[i], head->prog_size);
	ft_printf("Execute code:\n");
	print_bytes(area, head->prog_size);
}

void	parse_file(t_player *players)
{
	t_cw	*corewar;

	corewar = ft_memalloc(sizeof(t_cw));
	ft_bzero(corewar->map, MEM_SIZE);
	read_file(players[0].name, corewar->map, 0);
	// int i;

	// i = 0;
	// while (i < MAX_PLAYERS && players[i].id)
	// {
	// 	read_file(players[i].name);
	// 	i++;
	// }
}