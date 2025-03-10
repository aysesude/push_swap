/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:17:02 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:17:39 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_stck *stck, t_moves *moves)
{
	ft_repeat_function(ft_rr, moves->rr, stck);
	ft_repeat_function(ft_rrr, moves->rrr, stck);
	ft_repeat_function(ft_ra, moves->ra, stck);
	ft_repeat_function(ft_rb, moves->rb, stck);
	ft_repeat_function(ft_rra, moves->rra, stck);
	ft_repeat_function(ft_rrb, moves->rrb, stck);
	ft_pb(stck);
}

void	ft_push_to_a(t_stck *stck)
{
	int		target_index;
	t_moves	moves;

	while (stck->len_b > 0)
	{
		target_index = other_number_index_in_a(stck, stck->stck_b[0]);
		moves.ra = 0;
		moves.rra = 0;
		if (target_index <= (stck->len_a / 2))
			moves.ra = target_index;
		else
			moves.rra = stck->len_a - target_index;
		ft_repeat_function(ft_ra, moves.ra, stck);
		ft_repeat_function(ft_rra, moves.rra, stck);
		ft_pa(stck);
	}
	ft_is_stck_sorted(stck);
	ft_last_sort(stck);
}
