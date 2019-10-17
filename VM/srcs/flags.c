/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:39:34 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:21 by nlavrine         ###   ########.fr       */
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

int			check_num(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void		choose_flag(t_cw *corewar, char **argv, int *pos, int argc)
{
	int		i;
	char	*param;

	i = 1;
	param = argv[*pos];
	if (!ft_strcmp("-dump", param))
	{
		if (*pos + 1 >= argc)
			print_error("Enter number of cycles");
		if (!check_num(argv[*pos + 1]))
			print_error("Bad number of cycles");
		corewar->dump = ft_atoi(argv[*pos + 1]);
		corewar->flags |= 16;
		(*pos) += 2;
	}
	else
	{
		while (param[i])
		{
			corewar->flags |= put_flag(param[i]);
			i++;
		}
	}
}
