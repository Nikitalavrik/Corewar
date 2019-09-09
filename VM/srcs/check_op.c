/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:07:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 16:34:03 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

// unsigned	char check_type(unsigned type)

int		check_operation(t_cw *corewar, t_cursor *cursor, int op)
{
	g_func[op - 1](corewar, cursor, g_op_tab[op - 1]);
	// ft_printf("pos = %i next op = %i\n", cursor->position, corewar->map[cursor->position]);
	// exit(0); // for testing
	return (op);
}
