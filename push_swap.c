/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:25:36 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/09 00:06:08 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **result)
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

void	ft_numbers(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		count;
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

	count = 0;
	while (split_numbers[count])
		count++;
	stack->len_a = count;
	stack->len_b = 0;
	stack->stack_a = (int *)malloc(count * sizeof(int));
	stack->stack_b = (int *)malloc(count * sizeof(int));
	if (!stack->stack_a)
	{
		ft_free(split_numbers);
		exit(0);
	}

	i = 0;
	while (i < count)
	{
		(stack->stack_a)[i] = ft_atoi(split_numbers[i]);
		printf("%d\n", (stack->stack_a)[i]);
		i++;
	}

	ft_free(split_numbers);
}

void	write_stacks(t_stack *stack)
{
	int	i;

	printf("--------------------------\n");
	printf("Stack A          Stack B\n");
	printf("--------------------------\n");

	i = 0;
	while (i < stack->len_a || i < stack->len_b)
	{
		if (i < stack->len_a)
			printf("%-15d", stack->stack_a[i]);
		else
			printf("%-15s", " ");

		if (i < stack->len_b)
			printf("%d", stack->stack_b[i]);

		printf("\n");
		i++;
	}
	printf("--------------------------\n");
}

int	main(int argc, char **argv)
{
	t_stack stack;

	stack.ss_flag = 0;
	stack.rr_flag = 0;
	stack.rrr_flag = 0;
	if (argc > 1)
	{
		ft_check_input(argc, argv);
		ft_numbers(argc, argv, &stack);
		write_stacks(&stack);
		ft_first_moves(&stack);
	}
}
