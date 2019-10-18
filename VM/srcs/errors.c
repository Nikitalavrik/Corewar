/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:54:53 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/18 16:46:42 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_error(char *error)
{
	int i;

	i = 0;
	while (error[i])
	{
		write(2, &error[i], 1);
		i++;
	}
}

void	print_error(char *name, char *error)
{
	write_error(name);
	write_error(error);
	exit(1);
}
