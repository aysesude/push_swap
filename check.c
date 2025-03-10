/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:03:22 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:32:30 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_full_space(char **argv, int i, int j)
{
	int	count;

	count = 0;
	while (argv[i][j])
	{
		if (argv[i][j] == 32)
		{
			count++;
		}
		j++;
	}
	if (count == j)
		ft_exit();
}

void	ft_check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		ft_check_full_space(argv, i, j);
		while (argv[i][j])
		{
			ft_check_input_control(argv, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_input_control(char **argv, int i, int j)
{
	if (!((argv[i][j] <= '9' && argv[i][j] >= '0') || argv[i][j] == 32))
	{
		if ((argv[i][j] == '+' || argv[i][j] == '-') && (j != 0))
		{
			if (!((argv[i][j - 1] == 32) && (argv[i][j + 1] <= '9'
				&& argv[i][j + 1] >= '0')))
				ft_exit();
		}
		else if (!(argv[i][j] == '+' || argv[i][j] == '-')
			|| !(argv[i][j + 1] <= '9' && argv[i][j + 1] >= '0'))
			ft_exit();
	}
}

void	ft_check_same_number(t_stck *stck)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (stck->len_a - 1))
	{
		j = i + 1;
		while (j < stck->len_a)
		{
			if (stck->stck_a[i] == stck->stck_a[j])
			{
				free(stck->stck_a);
				free(stck->stck_b);
				ft_exit();
			}
			j++;
		}
		i++;
	}
}

void	ft_is_stck_sorted(t_stck *stck)
{
	int	i;

	i = 1;
	while (i < stck->len_a && stck->stck_a[i] > stck->stck_a[i - 1])
		i++;
	if (i == stck->len_a)
	{
		free(stck->stck_a);
		free(stck->stck_b);
		exit(0);
	}
}
