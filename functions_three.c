/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:32:21 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 13:34:44 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stck *stck)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stck->stck_a[stck->len_a - 1];
	if (stck->len_a > 1)
	{
		while (i < stck->len_a)
		{
			stck->stck_a[stck->len_a - i] = stck->stck_a[stck->len_a - 1 - i];
			i++;
		}
		stck->stck_a[0] = tmp;
	}
	if (stck->rrr_flag == 0)
	{
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stck *stck)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stck->stck_b[stck->len_b - 1];
	if (stck->len_b > 1)
	{
		while (i < stck->len_b)
		{
			stck->stck_b[stck->len_b - i] = stck->stck_b[stck->len_b - i - 1];
			i++;
		}
		stck->stck_b[0] = tmp;
	}
	if (stck->rrr_flag == 0)
	{
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stck *stck)
{
	stck->rrr_flag = 1;
	ft_rra(stck);
	ft_rrb(stck);
	write(1, "rrr\n", 4);
	stck->rrr_flag = 0;
}
