/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:39:34 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/12 17:56:42 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			put_flag(char c)
{
	if (c == 'a')
		return (1);
	else if (c == 'v')
		return (2);
	else if (c == 'n')
		return (4);
	else if (c == 'o')
		return (8);
	else if (c == 'd')
		return (16);
	else
		print_error("Unexpected flag");
	return (0);
}

int			choose_flag(t_cw *corewar, char **argv, int *pos, int argc)
{
	int		i;
	int		flag;
	char	*param;

	i = 1;
	flag = 0;
	param = argv[*pos];
	while (param[i])
	{
		flag |= put_flag(param[i]);
		if (flag & 16)
		{
			if (*pos + 1 == argc)
				print_error("Enter number of cycles");
			corewar->dump = ft_atoi(argv[*pos + 1]);
			(*pos) += 2;
		}
		i++;
	}
	return (flag);
}
