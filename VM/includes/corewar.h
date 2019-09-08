/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:47:47 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/08 20:10:25 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <fcntl.h>
# include "op.h"
# include <sys/stat.h> 

typedef struct		s_cursor
{
	struct s_cursor	*next;
	int				id;
	int				carry;				// флаг, который могут менять некоторые операции, значения 1 или 0. Изначально 0
	int				cycles_num;			// переменная для цикла, в котором последний раз была замечена операция live
	int				remaining_cycles; 	// количество циклов, оставшиеся до исполнения операции, на которой стоит каретка
	int				position;   		// текущая позиция каретки либо х у
	int				byte_count; 		//количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции
	unsigned int	reg[REG_NUMBER];    //регистры, количество которых задано в константе REG_NUMBER
	int				player_nbr;			//номер игрока породившего каретку
}					t_cursor;

typedef	struct	s_player
{
	int			id;
	char		*name;
	header_t	*head;
}				t_player;

typedef struct		s_corewar
{
	unsigned char	map[MEM_SIZE];
	int				player_nbr;
	int				check_cycle;
	int				cycle_to_die;
	t_cursor		*cursor;
	t_player		*players;
}					t_cw;


void			out_players(t_player *players);
void			out_cursor(t_cursor *cursor);

t_player		*parse_argv(int argc, char ** argv);
t_cw			*parse_file(t_player *players);

void			engine(t_cw *corewar);

void			print_error(char *error);

void			cursor(t_cw *cw);
void			del_cursor(t_cursor **cursor, t_cursor **prev,\
													t_cursor **main_cursor);

#endif