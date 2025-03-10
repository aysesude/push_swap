/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:31:31 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 13:34:44 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stck *stck)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stck->stck_a[0];
	if (stck->len_a > 1)
	{
		while (i < stck->len_a)
		{
			stck->stck_a[i] = stck->stck_a[i + 1];
			i++;
		}
		stck->stck_a[stck->len_a - 1] = tmp;
	}
	if (stck->rr_flag == 0)
	{
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stck *stck)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stck->stck_b[0];
	if (stck->len_b > 1)
	{
		while (i < stck->len_b)
		{
			stck->stck_b[i] = stck->stck_b[i + 1];
			i++;
		}
		stck->stck_b[stck->len_b - 1] = tmp;
	}
	if (stck->rr_flag == 0)
	{
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stck *stck)
{
	stck->rr_flag = 1;
	ft_rb(stck);
	ft_ra(stck);
	write(1, "rr\n", 3);
	stck->rr_flag = 0;
}
