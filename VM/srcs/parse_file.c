/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:06:22 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/05 20:14:05 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

void	print_bytes(unsigned int *line, int count)
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
	unsigned int	head;
	unsigned int	magic;

	fd = open(filename, O_RDONLY);
	read(fd, &head, 4);
	ft_printf("hex = %x\n", head);
	magic = reverse_num(head);
	if (magic == COREWAR_EXEC_MAGIC)
		ft_printf("YES\n");
	ft_printf("hex = %x\n", magic);
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