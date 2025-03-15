/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:21:57 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 13:27:21 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max_min_int_check(char **split_numbers, t_stck *stck, int count, long long result)
{
	if (result > 2147483647 || result < -2147483648 || count > 10)
	{
		free(stck->stck_a);
		free(stck->stck_b);
		ft_free(split_numbers);
		ft_exit();
	}
}

static int	ft_white_space(int i, const char *str)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_new_atoi(char **split_numbers, t_stck *stck, const char *str)
{
	int			i;
	long long	result;
	int			sign;
	int			count;

	count = 0;
	i = 0;
	result = 0;
	sign = 1;
	i += ft_white_space(i, str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = ((result * 10) + (str[i++] - 48));
		ft_max_min_int_check(split_numbers, stck, count, (result * sign));
	}
	return ((int)(result * sign));
}
