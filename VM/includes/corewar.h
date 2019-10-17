/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:47:47 by tbratsla          #+#    #+#             */
/*   Updated: 2019/10/17 15:37:43 by nlavrine         ###   ########.fr       */
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
# define HEIGHT			(MEM_SIZE / 64 + 4)
# define WIDTH			(64 * 3 + 5)

typedef struct			s_vis
{
	WINDOW				*win;
	WINDOW				*info;
	WINDOW				*help;
	int					speed;
	int					cols;
	int					lines;
	int					map[MEM_SIZE];
	int					player;
}						t_vis;

typedef struct			s_cursor
{
	struct s_cursor	*next;
	int				id;
	int				carry;
	int				op;
	int				cycles_num;
	int				remaining_cycles;
	int				position;
	int				byte_count;
	int				reg[REG_NUMBER];
	int				player_nbr;
}					t_cursor;

typedef	struct			s_player
{
	int					id;
	char				*name;
	long				last_live;
	t_header			*head;
}						t_player;

typedef struct			s_corewar
{
	unsigned char		map[MEM_SIZE];
	int					player_nbr;
	int					check_cycle;
	int					cycle_to_die;
	int					flags;
	int					live_process;
	int					dump;
	t_cursor			*cursor;
	t_player			*players;
	t_vis				*vis;
}						t_cw;

typedef	struct			s_op
{
	char				*func_name;
	int					num_of_args;
	int					type_of_args[3];
	char				id;
	int					cycle_before_exec;
	char				*description;
	char				codage;
	char				t_dirsize;
}						t_op;

typedef union			u_type
{
	unsigned char	types;
	struct			s_tp
	{
		unsigned char	t4 : 2;
		unsigned char	t3 : 2;
		unsigned char	t2 : 2;
		unsigned char	t1 : 2;
	}					t_tp;
}						t_type;

/*
** print function
*/

void				print_error(char *error);
void				out_players(t_player *players);
void				out_cursor(t_cursor *cursor);
void				out_print_bytes(unsigned char *line, int count);
void				out_func_info(t_cw *corewar, t_cursor *cursor, t_op op);
void				dump(unsigned char *map);

/*
** parse function
*/

t_player			*parse_argv(t_cw *corewar, int argc, char **argv);
t_cw				*parse_file(t_cw *corewar, t_player *players);
int					check_uniq_id(t_player *players, int id);
void				check_uniq_name(t_player *players);
int					choose_flag(t_cw *corewar, char **argv, int *pos, int argc);

/*
** main cycle function
*/

int					check_cycle_to_die(t_cw *corewar);
void				engine(t_cw *corewar);
int					check_operation(t_cw *corewar, t_cursor *cursor, int op);
unsigned int		place_cur(int cur);
t_player			check_winner(t_player *players, int n);
int					do_op(t_cw *corewar, t_cursor *cursor);
void				check_dump_flag(t_cw *corewar, char c, int i);

/*
** grep value from map
*/

unsigned int		get_val_size(int type, char t_dirsize);
int					grep_args(unsigned char *map, int position, int size);
int					check_grep_args(unsigned char *map, int position,\
													int type, char t_dirsize);
int					*init_args(t_cw *corewar, t_cursor *cursor,\
														t_op op, t_type type);

/*
** cursor function
*/

void				copy_cursor(t_cursor *src, t_cursor *dist);
void				add_cursor(t_cw *cw, int i);
void				cursor(t_cw *cw);
int					del_cursor(t_cursor **cursor, t_cursor **prev,\
								t_cursor **main_cursor, t_cw *corewar);
/*
** visual function
*/

void				vis_init(t_cw *corewar);
void				draw_map(t_cw *corewar);
void				set_player_collor(int i, t_cw *corewar, WINDOW *win);
void				reset_player_collor(int i, t_cw *corewar);
void				draw_player(unsigned char *area, int i,\
							unsigned int prog_size, t_cw *corewar);
void				draw_cursor(int pos, t_cursor *start, t_cw *corewar,\
														t_cursor *cursor);
void				set_color_by_cursor(t_cw *corewar, t_cursor *cursor);
void				cursor_color_to_player(int pos, t_cw *corewar);
void				set_cursor_color_by_pos(t_cw *corewar, t_cursor *start);
void				ft_init_colors(void);
void				draw_box_and_words(t_cw *corewar);
void				draw_box_and_words2(t_cw *corewar);
void				draw_box(t_cw *corewar);
void				draw_player_name(char *prog_name, t_cw *corewar);
void				after_game(t_cw *corewar, t_player player, char c);
void				draw_cursor_count(t_cw *corewar, int count, int i);
void				add_speed_pause(t_cw *corewar, char c, int i);
void				ft_check_size_win(t_cw *corewar, int *i);
void				reinit_win(t_cw *corewar, int *i);

/*
** implement func
*/

void				ft_and_xor_or(t_cw *corewar, t_cursor *cursor,\
										t_op op, int f(int, int));
void				ft_add_sub(t_cw *corewar, t_cursor *cursor,\
										t_op op, int f(int, int));
int					calc_pos(t_type	type, int n, t_op op);
void				free_corewar(t_cw *corewar);

extern			t_op	g_op_tab[17];
int				g_id;
int				g_i;
#endif
