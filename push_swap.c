/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:25:36 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:32:21 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	**ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

void	ft_numbers(int argc, char **argv, t_stck *stck)
{
	int		i;
	char	*joint_numbers;
	char	**split_numbers;
	char	*temp;

	if (argc < 2)
		return ;
	joint_numbers = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(joint_numbers, argv[i]);
		free(joint_numbers);
		joint_numbers = temp;
		temp = ft_strjoin(joint_numbers, " ");
		free(joint_numbers);
		joint_numbers = temp;
		i++;
	}
	split_numbers = ft_split(joint_numbers, ' ');
	free(joint_numbers);
	if (!split_numbers)
		exit(0);
	ft_numbers2(split_numbers, stck);
}

void	ft_numbers2(char **split_numbers, t_stck *stck)
{
	int	count;
	int	i;

	count = 0;
	while (split_numbers[count])
		count++;
	stck->len_a = count;
	stck->len_b = 0;
	stck->stck_a = (int *)malloc(count * sizeof(int));
	stck->stck_b = (int *)malloc(count * sizeof(int));
	if (!stck->stck_a)
	{
		ft_free(split_numbers);
		exit(0);
	}
	i = 0;
	while (i < count)
	{
		(stck->stck_a)[i] = ft_new_atoi(split_numbers, split_numbers[i]);
		i++;
	}
	ft_free(split_numbers);
}

int	main(int argc, char **argv)
{
	t_stck	stck;

	stck.ss_flag = 0;
	stck.rr_flag = 0;
	stck.rrr_flag = 0;
	if (argc > 1)
	{
		if (!argv[1][0])
		{
			ft_exit();
		}
		ft_check_input(argc, argv);
		ft_numbers(argc, argv, &stck);
		ft_check_same_number(&stck);
		ft_is_stck_sorted(&stck);
		ft_first_moves(&stck);
		free(stck.stck_a);
		free(stck.stck_b);
	}
}
