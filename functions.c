/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:51:51 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 13:34:44 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stck *stck)
{
	int	tmp;

	tmp = stck->stck_a[0];
	stck->stck_a[0] = stck->stck_a[1];
	stck->stck_a[1] = tmp;
	if (stck->ss_flag == 0)
	{
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stck *stck)
{
	int	tmp;

	tmp = stck->stck_b[0];
	stck->stck_b[0] = stck->stck_b[1];
	stck->stck_b[1] = tmp;
	if (stck->ss_flag == 0)
	{
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stck *stck)
{
	stck->ss_flag = 1;
	ft_sa(stck);
	ft_sb(stck);
	write(1, "ss\n", 3);
	stck->ss_flag = 0;
}

void	ft_pa(t_stck *stck)
{
	int	i;

	if (stck->len_b > 0)
	{
		i = stck->len_a;
		while (i > 0)
		{
			stck->stck_a[i] = stck->stck_a[i - 1];
			i--;
		}
		stck->stck_a[0] = stck->stck_b[0];
		while (i < stck->len_b - 1)
		{
			stck->stck_b[i] = stck->stck_b[i + 1];
			i++;
		}
		stck->len_a++;
		stck->len_b--;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stck *stck)
{
	int	i;

	if (stck->len_a > 0)
	{
		i = stck->len_b;
		while (i > 0)
		{
			stck->stck_b[i] = stck->stck_b[i - 1];
			i--;
		}
		stck->stck_b[0] = stck->stck_a[0];
		while (i < stck->len_a - 1)
		{
			stck->stck_a[i] = stck->stck_a[i + 1];
			i++;
		}
		stck->len_b++;
		stck->len_a--;
	}
	write(1, "pb\n", 3);
}
