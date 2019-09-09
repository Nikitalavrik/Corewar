/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:07:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 18:16:13 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

// unsigned	char check_type(unsigned type)

int		check_operation(t_cw *corewar, t_cursor *cursor, int op)
{
	g_func[op - 1](corewar, cursor, g_op_tab[op - 1]);
	// exit(0);
	return (op);
}
