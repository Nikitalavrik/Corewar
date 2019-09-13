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

# define HEIGHT					(MEM_SIZE / 64 + 4)
# define WIDTH					(64 * 3 + 5)
#include "corewar.h"

void	vis_init(t_cw *corewar)
{
  initscr();
  curs_set(0);
  refresh();
	corewar->vis = ft_memalloc(sizeof(t_vis));
	corewar->vis->win = newwin(HEIGHT, WIDTH + 4, 1, 2);
	start_color();
	has_colors();
	init_pair(1,  COLOR_RED,     COLOR_BLACK);
  init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
  init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
  init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
  init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
  init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
  init_pair(8,  COLOR_WHITE,   COLOR_RED);
  init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
  init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
  init_pair(11, COLOR_WHITE,   COLOR_BLUE);
  init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
  init_pair(13, COLOR_BLACK,   COLOR_CYAN);
  init_pair(14, COLOR_WHITE,   COLOR_BLACK);
}

void  set_player_collor(int i, t_cw *corewar)
{
    if (i == 0)
      wattron(corewar->vis->win, COLOR_PAIR(COLOR_GREEN));
    else if (i == 1)
      wattron(corewar->vis->win, COLOR_PAIR(COLOR_BLUE));
    else if (i == 2)
      wattron(corewar->vis->win, COLOR_PAIR(COLOR_RED));
    else if (i == 3)
      wattron(corewar->vis->win, COLOR_PAIR(COLOR_YELLOW));
}

void  draw_player(unsigned char *area, int i, header_t *head, t_cw *corewar)
{
    int j;

    j = i % 64;
    i = i / 64;
    while (i < 64 && i * 64 + j < (int)head->prog_size)
    {
      wmove(corewar->vis->win, i + 2, 5);
      j = 0;
      while (j < 64 && i * 64 + j < (int)head->prog_size)
      {
        wprintw(corewar->vis->win, "%.2x ", area[i * 64 + j]);
        j++;
      }
      wprintw(corewar->vis->win, "\n");
      i++;
    }
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
   		// wrefresh(corewar->vis->win);
   		k++;
   	}
    wattron(corewar->vis->win, COLOR_PAIR(COLOR_WHITE));
    box(corewar->vis->win, 0, 0);
    wattroff(corewar->vis->win, COLOR_PAIR(COLOR_WHITE));
	// if (!check_cycle_to_die(corewar))
	// 	clear();
   	wrefresh(corewar->vis->win);
   	usleep (10000);
}