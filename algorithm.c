/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:56:50 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:21:53 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_moves(t_stck *stck)
{
	if ((stck->len_a == 2) && stck->stck_a[0] > stck->stck_a[1])
		ft_ra(stck);
	else if (stck->len_a == 3)
		ft_moves_for_three_number(stck);
	else if (stck->len_a == 4)
	{
		ft_pb(stck);
		ft_moves_for_three_number(stck);
		ft_push_to_a(stck);
	}
	else if (stck->len_a >= 4)
	{
		ft_pb(stck);
		ft_pb(stck);
		ft_moves_for_more_than_three_number(stck);
		ft_push_to_a(stck);
	}
}

void	ft_moves_for_three_number(t_stck *stck)
{
	if ((stck->stck_a[0] > stck->stck_a[1])
		&& (stck->stck_a[1] > stck->stck_a[2]))
	{
		ft_sa(stck);
		ft_rra(stck);
	}
	if ((stck->stck_a[0] > stck->stck_a[2])
		&& (stck->stck_a[2] > stck->stck_a[1]))
		ft_ra(stck);
	if ((stck->stck_a[1] > stck->stck_a[0])
		&& (stck->stck_a[0] > stck->stck_a[2]))
		ft_rra(stck);
	if ((stck->stck_a[1] > stck->stck_a[2])
		&& (stck->stck_a[2] > stck->stck_a[0]))
	{
		ft_rra(stck);
		ft_sa(stck);
	}
	if ((stck->stck_a[2] > stck->stck_a[0])
		&& (stck->stck_a[0] > stck->stck_a[1]))
		ft_sa(stck);
}

void	ft_moves_for_more_than_three_number(t_stck *stck)
{
	int		i;
	int		tmp;
	t_moves	moves;

	while (stck->len_a > 3)
	{
		i = 1;
		tmp = 0;
		while (i < stck->len_a)
		{
			if (ft_calculate_cost(stck, i).cost
				< ft_calculate_cost(stck, tmp).cost)
				tmp = i;
			i++;
		}
		moves = ft_calculate_cost(stck, tmp);
		ft_push_to_b(stck, &moves);
	}
	ft_moves_for_three_number(stck);
}

void	ft_repeat_function(void (*func)(t_stck *), int count, t_stck *stck)
{
	int	i;

	i = 0;
	while (i < count)
	{
		func(stck);
		i++;
	}
}
