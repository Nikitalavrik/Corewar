/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:37:40 by nlavrine          #+#    #+#             */
/*   Updated: 2019/09/09 13:22:25 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "func.h"

void	*g_func[17] =
{
	&ft_live,
	&ft_ld,
	&ft_st,
	&ft_add,
	&ft_sub,
	&ft_and,
	&ft_or,
	&ft_xor,
	&ft_zjmp,
	&ft_ldi,
	&ft_sti,
	&ft_fork,
	&ft_lld,
	&ft_lldi,
	&ft_lfork,
	&ft_aff
};
