/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:03:22 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/05 17:33:50 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit()
{
	ft_printf("Check Error\n");
	exit(0);
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
			printf("deneme1\n");
			if(!((argv[i][j] <= '9' && argv[i][j] >= '0') || argv[i][j] == 32))
			{
				printf("deneme2\n");
				if((argv[i][j] == '+' || argv[i][j] == '-') && (j != 0))
				{
					if(!(argv[i][j-1] == 32))
						ft_exit();
				}
				else if(!(argv[i][j] == '+' || argv[i][j] == '-'))
					ft_exit();
			}
			j++;
		}
		j = 0;
		i++;
	}
}
