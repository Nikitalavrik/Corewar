/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:17 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/05 18:43:14 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR
# define COREWAR

# include "../libft/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <fcntl.h>
# include <sys/stat.h> 

typedef	struct	s_player
{
	int			id;
	char		*name;
}				t_player;

void			out_players(t_player *players);

t_player		*parse_argv(int argc, char ** argv);
void			parse_file(t_player *players);

void			print_error(char *error);

#endif