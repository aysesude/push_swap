/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:56:50 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/05 07:49:58 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_moves(t_stack *stack)
{
	if(stack->len_a == 2)
		ft_ra(stack);
	else if(stack->len_a == 3)
		moves_for_three_number(stack);
	else if(stack->len_a >= 4)
	{
		ft_pb(stack);
		ft_pb(stack);
		moves_for_more_than_three_number(stack);
	}
}

void	moves_for_three_number(t_stack *stack)
{
	if((stack->stack_a[0] > stack->stack_a[1]) && (stack->stack_a[1] > stack->stack_a[2]))
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	if((stack->stack_a[0] > stack->stack_a[2]) && (stack->stack_a[2] > stack->stack_a[1]))
		ft_ra(stack);
	if((stack->stack_a[1] > stack->stack_a[0]) && (stack->stack_a[0] > stack->stack_a[2]))
		ft_rra(stack);
	if((stack->stack_a[1] > stack->stack_a[2]) && (stack->stack_a[2] > stack->stack_a[0]))
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	if((stack->stack_a[2] > stack->stack_a[0]) && (stack->stack_a[0]  > stack->stack_a[1]))
		ft_sa(stack);
}

void	moves_for_more_than_three_number(t_stack *stack)
{
	while(stack->len_a > 3)
	{
		ft_find_move();
	}
}

//void	ft_find_move()
//{
//	while()
//	{

//	}
//}

int	ft_calculate_cost(t_stack *stack, int index)
{
	int	i;
	int	tmp;
	int	cost;

	i = 0;
	tmp = 0;
	cost = ft_calculate_rotate_cost(index, stack->len_a, stack->stack_a) + 1;
	if((stack->stack_a[index] > largest_number_in_b(stack)) || (stack->stack_a[index] < smallest_number_in_b(stack)))
		cost += ft_calculate_rotate_cost(stack->largest_number_index_b , stack->len_b, stack->stack_b);
	else
	{
		while(i < stack->len_b)
		{
			if((stack->stack_b[i] < stack->stack_a[index]) && (stack->stack_b[i] > stack->stack_b[tmp]))
				tmp = i;
			i++;
		}
		cost += ft_calculate_rotate_cost(tmp , stack->len_b, stack->stack_b);
	}
	return cost;
}

int	largest_number_in_b(t_stack *stack)
{
	int	i;
	int	number;

	i = 1;
	number = stack->stack_b[0];
	while(i < stack->len_b)
	{
		if(stack->stack_b[i] > number)
		{
			number = stack->stack_b[i];
			stack->largest_number_index_b = i;
		}
		i++;
	}
	return number;
}

int	smallest_number_in_b(t_stack *stack)
{
	int	i;
	int	number;

	i = 1;
	number = stack->stack_b[0];
	while(i < stack->len_b)
	{
		if(stack->stack_b[i] < number)
		{
			number = stack->stack_b[i];
			stack->largest_number_index_b = i;
		}
		i++;
	}
	return number;
}

int	ft_calculate_rotate_cost(int index, int len, int *stack)
{
	int	cost;

	if(index <= (len/2))
		cost = index;
	else
		cost = (len - index);
	return cost;
}

//void	push_to_b(int len, int *stack)
//{
//	int	i;
//	return i;
//}
