/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:55:15 by tbratsla          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 14:55:05 by nlavrine         ###   ########.fr       */
=======
/*   Updated: 2019/09/19 14:15:36 by nlavrine         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
<<<<<<< HEAD

void			vis_init(t_cw *corewar)
{
	system("printf '\033[8;76;362t' && printf '\e[3;0;0t' && sleep 1");
	initscr();
	curs_set(0);
	refresh();
	noecho();
	corewar->vis = ft_memalloc(sizeof(t_vis));
	corewar->vis->speed = 11000;
	corewar->vis->cols = 362;
	corewar->vis->lines = 76;
	corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
	corewar->vis->info = newwin(HEIGHT / 2, 64, 1, WIDTH + 5);
	corewar->vis->help = newwin(HEIGHT / 2 + 1, 64, HEIGHT / 2, WIDTH + 5);
	ft_bzero(corewar->vis->map, MEM_SIZE);
	corewar->vis->player = 0;
	ft_init_colors();
	// system("afplay music/sound.mp3&");
}

void			ft_init_colors(void)
{
	start_color();
	has_colors();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLUE, COLOR_YELLOW);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
	init_pair(12, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_WHITE, COLOR_WHITE);
}

void			ft_check_size_win(t_cw *corewar, int *i)
{
	if (COLS != corewar->vis->cols || LINES != corewar->vis->lines)
	{
		delwin(corewar->vis->win);
		delwin(corewar->vis->help);
		delwin(corewar->vis->info);
		endwin();
		system("sleep 1");
		system("reset");
		system("clear");
		system("printf '\033[8;76;362t'");
		system("printf '\e[3;0;0t'");
		system("sleep 2");
		reinit_win(corewar, i);
	}
}

void			reinit_win(t_cw *corewar, int *i)
{
	initscr();
	curs_set(0);
	refresh();
	noecho();
	corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
	corewar->vis->info = newwin(HEIGHT / 2, 64, 1, WIDTH + 5);
	corewar->vis->help = newwin(HEIGHT / 2 + 1, 64, HEIGHT / 2, WIDTH + 5);
	ft_init_colors();
	draw_map(corewar);
	draw_box_and_words(corewar);
	while (*i < corewar->player_nbr)
	{
		corewar->vis->player = (*i) + 1;
		draw_player_name(corewar->players[*i].head->prog_name, corewar);
		(*i)++;
	}
	corewar->vis->player = 0;
	wrefresh(corewar->vis->win);
	wrefresh(corewar->vis->help);
	wrefresh(corewar->vis->info);
}

void			draw_cursor_count(t_cw *corewar, int count, int i)
{
	if (corewar->flags & 2)
	{
		mvwprintw(corewar->vis->info, 14, 21, "%i  ", count);
		i = 0;
		while (i < corewar->player_nbr)
		{
			mvwprintw(corewar->vis->info, 15 + corewar->vis->player * 3\
				+ (i + 1) * 3, 16, "%i", corewar->players[i].last_live);
			i++;
		}
		wrefresh(corewar->vis->info);
	}
}
=======
# define HEIGHT                 (MEM_SIZE / 64 + 4)
# define WIDTH                  (64 * 3 + 5)

void	vis_init(t_cw *corewar)
{
    system("printf '\033[8;100;1000t' && printf '\e[3;0;0t' && sleep 1");
    initscr();
    curs_set(0);
    refresh();
    noecho();
    corewar->vis = ft_memalloc(sizeof(t_vis));
    corewar->vis->cols = COLS;
    corewar->vis->lines = LINES;
    corewar->vis->speed = 1000;
    corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
    corewar->vis->info = newwin(HEIGHT / 2, 64, 1, WIDTH + 5);
    corewar->vis->help = newwin(HEIGHT / 2 + 1, 64, HEIGHT / 2, WIDTH + 5);   
    ft_bzero(corewar->vis->map, MEM_SIZE);
    corewar->vis->player = 0;
    ft_init_colors();
}

void    ft_init_colors(void)
{
    start_color();
    has_colors();
    init_pair(1,  COLOR_RED,     COLOR_BLACK);
    init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
    init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
    init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
    init_pair(5,  COLOR_BLACK,   COLOR_RED);
    init_pair(6,  COLOR_BLACK,   COLOR_GREEN);
    init_pair(7,  COLOR_BLACK,   COLOR_YELLOW);
    init_pair(8,  COLOR_BLACK,   COLOR_BLUE);
    init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
    init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
    init_pair(11, COLOR_WHITE,   COLOR_BLACK);
    init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
    init_pair(13, COLOR_BLACK,   COLOR_CYAN);
    init_pair(14, COLOR_WHITE,   COLOR_WHITE);
}


void  draw_player(unsigned char *area, int i, unsigned int prog_size, t_cw *corewar)
{
    int           j;
    unsigned int  k;

    k = 0;
    j = i % 64;
    i = i / 64;
    wmove(corewar->vis->win, i + 2, (5 + j * 3));
    while (i < 64)
    {
        while (j < 64 && k < prog_size)
        {
            wprintw(corewar->vis->win, "%.2x ", area[i * 64 + j]);
            corewar->vis->map[i * 64 + j] = corewar->vis->player;
            j++;
            k++;
        }
        if (k < prog_size)
            wprintw(corewar->vis->win, "\n");
        else
            break ;
        i++;
        wmove(corewar->vis->win, i + 2, 5);
        j = 0;
    }
    wattron(corewar->vis->win, COLOR_PAIR(14));
    box(corewar->vis->win, 0, 0);
    wattroff(corewar->vis->win, COLOR_PAIR(14));
    wrefresh(corewar->vis->win);
}

void	draw_map(t_cw *corewar)
{
  	int		k;
  	int		j;

  	wattron(corewar->vis->win, COLOR_PAIR(COLOR_BLACK));
    k = 0;
   	while (k < 64)
   	{
 		wmove(corewar->vis->win, k + 2, 5);
 		j = 0;
 		while (j < 64)
 		{
            cursor_color_to_player(k * 64 + j, corewar);
   			wprintw(corewar->vis->win, "%.2x ", corewar->map[k * 64 + j]);
   			j++;
 		}
 		wprintw(corewar->vis->win, "\n");
 		k++;
   	}
    draw_box_and_words(corewar);
}

void    draw_player_name(char *prog_name, t_cw *corewar)
{
    int i;
    int n;

    i = 0;
    n = 0;
    mvwprintw(corewar->vis->info, 12 + corewar->vis->player * 3, 5, "Player %i:", corewar->vis->player);
    while (prog_name[i])
    {
        mvwprintw(corewar->vis->info, 12 + corewar->vis->player * 3 + n, 15 + i % 47, "%c", prog_name[i]);
        if (i % 47 == 0 && i != 0)
            n++;
        i++;
    }
    wrefresh(corewar->vis->info);
}

void    draw_box_and_words(t_cw *corewar)
{
    wattron(corewar->vis->info, COLOR_PAIR(1));
    mvwprintw(corewar->vis->info, 2, 28, "STATUS");
    wattroff(corewar->vis->info, COLOR_PAIR(1));
    mvwprintw(corewar->vis->info, 4, 5, "Cycles: ");
    mvwprintw(corewar->vis->info, 6, 5, "Cycles to die: ");
    mvwprintw(corewar->vis->info, 8, 5, "Cycle delta: ");
    mvwprintw(corewar->vis->info, 8, 21, "%i", CYCLE_DELTA);
    mvwprintw(corewar->vis->info, 10, 5, "Nbr LIVE: ");
    mvwprintw(corewar->vis->info, 10, 21, "%i", NBR_LIVE);
    mvwprintw(corewar->vis->info, 12, 5, "Max cheks: ");
    mvwprintw(corewar->vis->info, 12, 21, "%i", MAX_CHECKS);
    wattron(corewar->vis->win, COLOR_PAIR(14));
    box(corewar->vis->win, 0, 0);
    wattroff(corewar->vis->win, COLOR_PAIR(14));
    wrefresh(corewar->vis->win);
    wattron(corewar->vis->info, COLOR_PAIR(14));
    box(corewar->vis->info, 0, 0);
    wattroff(corewar->vis->info, COLOR_PAIR(14));
    wrefresh(corewar->vis->info);
    wattron(corewar->vis->help, COLOR_PAIR(14));
    box(corewar->vis->help, 0, 0);
    wattroff(corewar->vis->help, COLOR_PAIR(14));
    wattron(corewar->vis->help, COLOR_PAIR(1));
    mvwprintw(corewar->vis->help, 2, 25, "INFORMATION");
    wattroff(corewar->vis->help, COLOR_PAIR(1));
    mvwprintw(corewar->vis->help, 4, 5, "Press spase to start or to pause.");
    
    mvwprintw(corewar->vis->help, 8, 5, "Press '+' to increase speed");
    mvwprintw(corewar->vis->help, 10, 5, "Press '-' to decrease speed");
    wrefresh(corewar->vis->help);
}

void    draw_cursor(int pos, t_cursor *start, t_cw *corewar, t_cursor *cursor)
{
    t_cursor    *begin;
    int         i;
    int         j;

    i = start->position / 64;
    j = start->position % 64;
    set_cursor_color_by_pos(corewar, start);
    mvwprintw(corewar->vis->win, i + 2, 3 * j + 5, "%.2x", corewar->map[i * 64 + j]);
    begin = cursor;
    while (begin)
    {
        if (begin->position == pos)
            break ;
        begin = begin->next;
    }   
    if (!begin)
    {
        cursor_color_to_player(pos, corewar);
        i = pos / 64;
        j = pos % 64;
        mvwprintw(corewar->vis->win, i + 2, 3 * j + 5, "%.2x", corewar->map[i * 64 + j]);
    }
    wrefresh(corewar->vis->win);
    usleep(corewar->vis->speed);
}

>>>>>>> master
