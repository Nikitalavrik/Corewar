/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:00 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/02 16:49:06 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corerwar.h"

int		parse_champ(char *param)
{
	ft_printf("%s\n", param);
	return (1);
}

int		parse_argv(int argc, char ** argv)
{
	int i;

	i = 1;
	while (argv[i] && i < argc)
	{
		parse_champ(argv[i]);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("Please put champions!\n");
	parse_argv(argc, argv);
	return (0);
}
