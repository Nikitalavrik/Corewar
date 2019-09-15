/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:55:15 by tbratsla          #+#    #+#             */
/*   Updated: 2019/09/11 10:55:16 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
# define HEIGHT                 (MEM_SIZE / 64 + 4)
# define WIDTH                  (64 * 3 + 5)

void	vis_init(t_cw *corewar)
{
    initscr();
    curs_set(0);
    refresh();
    corewar->vis = ft_memalloc(sizeof(t_vis));
    corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
    ft_bzero(corewar->vis->map, MEM_SIZE);
    corewar->vis->player = 0;
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
    int           f;

    if (corewar->vis->player == 1)
        f = 1;
    if (corewar->vis->player == 2)
        f = 2;
    if (corewar->vis->player == 3)
        f = 3;
    if (corewar->vis->player == 4)
        f = 4;
    k = 0;
    j = i % 64;
    i = i / 64;
    wmove(corewar->vis->win, i + 2, (5 + j * 3));
    while (i < 64)
    {
        while (j < 64 && k < prog_size)
        {
            wprintw(corewar->vis->win, "%.2x ", area[i * 64 + j]);
            corewar->vis->map[i * 64 + j] = f;
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
   			wprintw(corewar->vis->win, "%.2x ", corewar->map[k * 64 + j]);
   			j++;
 		}
 		wprintw(corewar->vis->win, "\n");
 		k++;
   	}
    wattron(corewar->vis->win, COLOR_PAIR(14));
    box(corewar->vis->win, 0, 0);
    wattroff(corewar->vis->win, COLOR_PAIR(14));
   	wrefresh(corewar->vis->win);
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
    usleep(1000);
}

