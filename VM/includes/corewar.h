/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:47:47 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/27 13:41:26 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <fcntl.h>
# include "op.h"
# include <sys/stat.h>
# include <ncurses.h>

typedef struct		s_vis
{
	WINDOW			*win;
	WINDOW			*info;
	WINDOW			*help;
	int				speed;
	int				cols;
	int				lines;
	int				map[MEM_SIZE];
	int				player;
}					t_vis;

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

typedef	struct		s_player
{
	int				id;
	char			*name;
	long			last_live;
	header_t		*head;
}					t_player;

typedef struct		s_corewar
{
	unsigned char	map[MEM_SIZE];
	int				player_nbr;
	int				check_cycle;
	int				cycle_to_die;
	int				flags;
	t_cursor		*cursor;
	t_player		*players;
	t_vis			*vis;
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

typedef union		u_type
{
	unsigned char 	types;
	struct			s_tp
	{
		unsigned char	t4 : 2;
		unsigned char	t3 : 2;
		unsigned char	t2 : 2;
		unsigned char	t1 : 2;
	}				t_tp;
}					t_type;

/**
 ** print function
 */
void			print_error(char *error);
void			out_players(t_player *players);
void			out_cursor(t_cursor *cursor);
void			out_print_bytes(unsigned char *line, int count);
void			out_func_info(t_cw *corewar, t_cursor *cursor, t_op op);
void			dump(t_cursor *cursor);

/**
 ** parse function
 */
t_player		*parse_argv(int argc, char ** argv, int *flags);
t_cw			*parse_file(t_player *players, int flags);
int				check_uniq_id(t_player *players, int id);
void			check_uniq_name(t_player *players);

/**
 ** main cycle function
 */
void			engine(t_cw *corewar);
int				check_operation(t_cw *corewar, t_cursor *cursor, int op);
unsigned int 	place_cur(int cur);
t_player 		check_winner(t_player *players, int n);

/**
 ** grep value from map
 */
unsigned int	get_val_size(int type, char t_dirsize);
int				grep_args(unsigned char *map, int position, int size);
int				check_grep_args(unsigned char *map, int position,\
													int type, char t_dirsize);
int				*init_args(t_cw *corewar, t_cursor *cursor,\
														t_op op, t_type type);

/**
 ** cursor function
 */
void			copy_cursor(t_cursor *src, t_cursor *dist);
void			add_cursor(t_cw *cw, int i);
void			cursor(t_cw *cw);
int				del_cursor(t_cursor **cursor, t_cursor **prev,\
													t_cursor **main_cursor);
/**
 ** visual function
 */
void			vis_init(t_cw *corewar);
void			draw_map(t_cw *corewar);
void  			set_player_collor(int i, t_cw *corewar);
void  			reset_player_collor(int i, t_cw *corewar);
void 			draw_player(unsigned char *area, int i,\
				unsigned int prog_size,	t_cw *corewar);
void  			draw_cursor(int pos, t_cursor *start, t_cw *corewar,\
													t_cursor *cursor);
void    		set_color_by_cursor(t_cw *corewar, t_cursor *cursor);
void    		cursor_color_to_player(int pos, t_cw *corewar);
void   			set_cursor_color_by_pos(t_cw *corewar, t_cursor *start);
void    		ft_init_colors(void);
void    		draw_box_and_words(t_cw *corewar);
void    		draw_player_name(char *prog_name, t_cw *corewar);

/**
 ** implement func
 */

void			ft_and_xor_or(t_cw *corewar, t_cursor *cursor,\
										t_op op, int f(int, int));
void			ft_add_sub(t_cw *corewar, t_cursor *cursor,\
										t_op op, int f(int, int));
int				calc_pos(t_type	type, int n, t_op op);

extern			t_op	g_op_tab[17];
int		g_id;
int		g_i;
#endif