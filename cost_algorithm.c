/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:21:29 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:21:59 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_moves(t_moves *moves)
{
	moves->cost = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
}

t_moves	ft_calculate_cost(t_stck *stck, int i)
{
	t_moves	moves;

	reset_moves(&moves);
	ft_update_large_in_b(stck);
	if (i <= ((stck->len_a) / 2))
		moves.ra = i;
	else
		moves.rra = (stck->len_a - i);
	if ((stck->stck_a[i] > ft_lab(stck)) || (stck->stck_a[i] < ft_smb(stck)))
	{
		if (stck->largest_number_index_b <= ((stck->len_b) / 2))
			moves.rb = stck->largest_number_index_b;
		else
			moves.rrb = (stck->len_b - stck->largest_number_index_b);
	}
	else
	{
		if (ft_sl_in_b(stck, stck->stck_a[i]) <= ((stck->len_b) / 2))
			moves.rb = ft_sl_in_b(stck, stck->stck_a[i]);
		else
			moves.rrb = (stck->len_b - ft_sl_in_b(stck, stck->stck_a[i]));
	}
	ft_calculate_moves_cost(&moves);
	return (moves);
}

void	ft_calculate_moves_cost(t_moves *moves)
{
	moves->rr = 0;
	moves->rrr = 0;
	while ((moves->ra > 0) && (moves->rb > 0))
	{
		moves->rr++;
		moves->ra--;
		moves->rb--;
	}
	while ((moves->rra > 0) && (moves->rrb > 0))
	{
		moves->rrr++;
		moves->rra--;
		moves->rrb--;
	}
	moves->cost = moves->ra + moves->rb + moves->rr
		+ moves->rra + moves->rrb + moves->rrr + 1;
}
