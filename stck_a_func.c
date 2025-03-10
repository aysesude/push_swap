/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_a_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:22 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:21:09 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	other_number_index_in_a(t_stck *stck, int num)
{
	int	i;
	int	min_index;
	int	flag;

	i = 0;
	flag = 1;
	while (i < stck->len_a)
	{
		if ((stck->stck_a[i] > num) && flag == 1)
		{
			min_index = i;
			flag = 0;
		}
		else if ((stck->stck_a[i] > num)
			&& (stck->stck_a[i] < stck->stck_a[min_index]))
			min_index = i;
		i++;
	}
	if (flag == 1)
	{
		while (stck->stck_a[(stck->len_a - 1)] < stck->stck_a[0])
			ft_rra(stck);
		return (0);
	}
	return (min_index);
}

int	ft_smallest_number_index_in_a(t_stck *stck)
{
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	while (i < stck->len_a)
	{
		if (stck->stck_a[i] < stck->stck_a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	ft_last_sort(t_stck *stck)
{
	int	ra;
	int	rra;

	ra = 0;
	rra = 0;
	if (ft_smallest_number_index_in_a(stck) <= ((stck->len_a) / 2))
		ra = ft_smallest_number_index_in_a(stck);
	else
		rra = (stck->len_a - ft_smallest_number_index_in_a(stck));
	ft_repeat_function(ft_ra, ra, stck);
	ft_repeat_function(ft_rra, rra, stck);
}
