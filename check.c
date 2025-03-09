/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:03:22 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/09 22:12:50 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_check_full_space(char **argv, int i, int j)
{
	int count;
	count = 0;
	while(argv[i][j])
	{
		if(argv[i][j] == 32)
		{
			count++;
		}
		j++;
	}
	if(count == j)
		ft_exit();
}

void	ft_check_input(int argc,char **argv)
{
	int	i;
	int	j;
	i = 1;
	j = 0;
	while(i < argc)
	{
		ft_check_full_space(argv, i, j);
		while(argv[i][j])
		{
			if(!((argv[i][j] <= '9' && argv[i][j] >= '0') || argv[i][j] == 32))
			{
				if((argv[i][j] == '+' || argv[i][j] == '-') && (j != 0))
				{
					if(!((argv[i][j-1] == 32) && (argv[i][j+1] <= '9' && argv[i][j+1] >= '0')))
						ft_exit();
				}
				else if(!(argv[i][j] == '+' || argv[i][j] == '-') || !(argv[i][j+1] <= '9' && argv[i][j+1] >= '0'))
					ft_exit();
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_same_number(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < (stack->len_a - 1))
	{
		j = i + 1;
		while(j < stack->len_a)
		{
			if(stack->stack_a[i] == stack->stack_a[j])
			{
				ft_exit();
			}
			j++;
		}
		i++;
	}
}

void	ft_is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while(stack->stack_a[i] > stack->stack_a[i - 1] && i < stack->len_a)
		i++;
	if(i == stack->len_a)
		exit(0);
}
