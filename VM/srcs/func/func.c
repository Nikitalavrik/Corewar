/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:37:40 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/19 13:15:53 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "func.h"

func	*g_func[17] =
{
	&ft_live,
	&ft_ld,
	&ft_st,
	&ft_add,
	&ft_sub,
	&ft_and,
	&ft_or,
	&ft_xor,
	&ft_zjmp,
	&ft_ldi,
	&ft_sti,
	&ft_fork,
	&ft_lld,
	&ft_lldi,
	&ft_lfork,
	&ft_aff
};

int	grep_args(unsigned char *map, int position, int size)
{
	int				i;
	int				val;
	char			sign;

	i = 0;
	val = 0;
	sign = map[position] & 0x80;
	if (!sign)
		while (i < size)
		{
			val = (val << 8) + map[position + i];
			i++;
		}
	else
		while (i < size)
		{
			val = (val << 8) + (map[position + i] ^ 0xff);
			i++;
		}
	if (sign)
		val = ~val;
	return (val);
}

int	check_grep_args(unsigned char *map, int position,\
											int type, char t_dirsize)
{
	int	arg;

	arg = 0;
	if (type == REG_CODE)
		arg = (unsigned char)grep_args(map, position, T_REG);
	else if (type == DIR_CODE)
		arg = grep_args(map, position, DIR_SIZE - t_dirsize * 2);
	else if (type == IND_CODE)
		arg = (short int)grep_args(map, position, IND_SIZE);
	return (arg);
}

unsigned	int get_val_size(int type, char t_dirsize)
{
	if (type == REG_CODE)
		return (T_REG);
	else if (type == DIR_CODE)
		return (DIR_SIZE - t_dirsize * 2);
	else if (type == IND_CODE)
		return (IND_SIZE);
	else
		return (0);
}

unsigned int place_cur(int cur)
{
	if (cur < 0)
		return (MEM_SIZE + cur % MEM_SIZE);
	return (cur % MEM_SIZE);
}
