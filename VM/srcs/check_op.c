/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:07:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 13:39:56 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		check_operation(t_cw *corewar, t_cursor *cursor, int op)
{
	g_func[op - 1](corewar, cursor, g_op_tab[op]);
	return (op);
}