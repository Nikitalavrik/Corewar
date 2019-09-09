/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:30:11 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 13:30:24 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include "corewar.h"

void			ft_live(t_cw *corewar, t_cursor *cursor);
void			ft_ld(t_cw *corewar, t_cursor *cursor);
void			ft_st(t_cw *corewar, t_cursor *cursor);
void			ft_add(t_cw *corewar, t_cursor *cursor);
void			ft_sub(t_cw *corewar, t_cursor *cursor);
void			ft_and(t_cw *corewar, t_cursor *cursor);
void			ft_or(t_cw *corewar, t_cursor *cursor);
void			ft_xor(t_cw *corewar, t_cursor *cursor);
void			ft_zjmp(t_cw *corewar, t_cursor *cursor);
void			ft_ldi(t_cw *corewar, t_cursor *cursor);
void			ft_sti(t_cw *corewar, t_cursor *cursor);
void			ft_fork(t_cw *corewar, t_cursor *cursor);
void			ft_lld(t_cw *corewar, t_cursor *cursor);
void			ft_lldi(t_cw *corewar, t_cursor *cursor);
void			ft_lfork(t_cw *corewar, t_cursor *cursor);
void			ft_aff(t_cw *corewar, t_cursor *cursor);

typedef	void	func(t_cw *, t_cursor *);

extern	func	*g_func[17];

#endif