/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:47:47 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/10 15:06:12 by nlavrine         ###   ########.fr       */
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
	int				op;
	int				is_wait;
	int				cycles_num;			// переменная для цикла, в котором последний раз была замечена операция live
	int				remaining_cycles; 	// количество циклов, оставшиеся до исполнения операции, на которой стоит каретка
	int				position;   		// текущая позиция каретки либо х у
	int				byte_count; 		//количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции
	int				reg[REG_NUMBER];    //регистры, количество которых задано в константе REG_NUMBER
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

typedef	struct		s_op
{
	char			*func_name; 		// имя функции
	int				num_of_args;		// количество аргументов
	int				type_of_args[3]; 	// типы аргументов
	char			id;					// номер функции <= 16
	int				cycle_before_exec;	// количество циклов перед исполнением
	char			*description;		// описание функции
	char			codage;				// код типов аргументов
	char			t_dirsize;			// если 1 то Тдир = 2, если 0, то 4
}					t_op;

typedef struct		s_type_arg
{
	unsigned char	type;
	unsigned int	arg;
}					t_type_arg;

void			print_error(char *error);
void			out_players(t_player *players);
void			out_cursor(t_cursor *cursor);
void			out_print_bytes(unsigned char *line, int count);
void			out_func_info(t_cw *corewar, t_cursor *cursor, t_op op);
void			dump(t_cursor *cursor);

t_player		*parse_argv(int argc, char ** argv);
t_cw			*parse_file(t_player *players);

void			engine(t_cw *corewar);
int				check_operation(t_cw *corewar, t_cursor *cursor, int op);
int				grep_args(unsigned char *map, int position, int size);
int				check_grep_args(unsigned char *map, int position,\
													int type, char t_dirsize);
unsigned	int get_val_size(int type, char t_dirsize);

void			cursor(t_cw *cw);
void			del_cursor(t_cursor **cursor, t_cursor **prev,\
													t_cursor **main_cursor);
extern			t_op	g_op_tab[17];

#endif