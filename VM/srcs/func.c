/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:37:40 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 16:29:42 by nlavrine         ###   ########.fr       */
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

unsigned	int	grep_args(unsigned char *map, int position, int size)
{
	int				i;
	unsigned int	val;

	i = 0;
	val = 0;
	while (i < size)
	{
		val = (val << 16) + map[position + i];
		i++;
	}
	if (size == 1)
		val = (unsigned char)val;
	else if (size == 2)
		val = (unsigned short int)val;
	else if (size == 4)
		val = (unsigned int)val;
	return (val);
}
