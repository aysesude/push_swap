/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_b_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:18:10 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:19:48 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_large_in_b(t_stck *stck)
{
	int	i;
	int	max_index;

	if (stck->len_b == 0)
		return ;
	i = 1;
	max_index = 0;
	while (i < stck->len_b)
	{
		if (stck->stck_b[i] > stck->stck_b[max_index])
			max_index = i;
		i++;
	}
	stck->largest_number_index_b = max_index;
}

int	ft_lab(t_stck *stck)
{
	int	i;
	int	number;

	i = 1;
	number = stck->stck_b[0];
	while (i < stck->len_b)
	{
		if (stck->stck_b[i] > number)
		{
			number = stck->stck_b[i];
		}
		i++;
	}
	return (number);
}

int	ft_smb(t_stck *stck)
{
	int	i;
	int	number;

	i = 1;
	number = stck->stck_b[0];
	while (i < stck->len_b)
	{
		if (stck->stck_b[i] < number)
		{
			number = stck->stck_b[i];
		}
		i++;
	}
	return (number);
}

int	ft_sl_in_b(t_stck *stck, int num)
{
	int	i;
	int	max_index;
	int	flag;

	i = 0;
	flag = 1;
	while (i < stck->len_b)
	{
		if ((stck->stck_b[i] < num) && flag == 1)
		{
			max_index = i;
			flag = 0;
		}
		else if ((stck->stck_b[i] < num)
			&& (stck->stck_b[i] > stck->stck_b[max_index]))
			max_index = i;
		i++;
	}
	return (max_index);
}
