/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:39:34 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/17 17:34:30 by nlavrine         ###   ########.fr       */
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
	if (!ft_strcmp("-dump", param))
	{
		if (*pos + 1 == argc)
			print_error("Enter number of cycles");
		corewar->dump = ft_atoi(argv[*pos + 1]);
		corewar->flags |= 16;
		(*pos) += 2;
	}
	else
	{
		while (param[i])
		{	
			flag |= put_flag(param[i]);
			i++;
		}
	}
	return (flag);
}
