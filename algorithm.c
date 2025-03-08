/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:56:50 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/08 13:07:21 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_moves(t_stack *stack)
{
	if(stack->len_a == 2)
		ft_ra(stack);
	else if(stack->len_a == 3)
		ft_moves_for_three_number(stack);
	else if(stack->len_a >= 4)
	{
		ft_pb(stack);
		ft_pb(stack);
		ft_moves_for_more_than_three_number(stack);
	}
}

void	ft_moves_for_three_number(t_stack *stack)
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

void	ft_moves_for_more_than_three_number(t_stack *stack)
{
	int	i;
	int	tmp;
	t_moves moves;

	while(stack->len_a > 3)
	{
		i = 1;
		tmp = 0;
		while(i < stack->len_a)
		{
			if(ft_calculate_cost(stack, i).cost < ft_calculate_cost(stack, tmp).cost)
				tmp = i;
			i++;
		}
		moves = ft_calculate_cost(stack, tmp);
		printf("En ucuz hamlelinin indexi: %d \n", tmp);
		ft_push_to_b(stack, &moves);
	}
}

void ft_yazma(t_moves *moves)
{
	printf("cost = %d \n", moves->cost);
	printf("ra = %d \n", moves->ra);
	printf("rb = %d \n", moves->rb);
	printf("rr = %d \n", moves->rr);
	printf("rra = %d \n", moves->rra);
	printf("rrb = %d \n", moves->rrb);
	printf("rrr = %d \n", moves->rrr);
}

t_moves	ft_calculate_cost(t_stack *stack, int index)
{
	t_moves moves;
	ft_update_largest_number_in_b(stack);

	moves.cost = 0;
	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;

	if(index <= ((stack->len_a)/2))
		moves.ra = index;
	else
		moves.rra = (stack->len_a - index);
	if((stack->stack_a[index] > ft_largest_number_in_b(stack)) || (stack->stack_a[index] < ft_smallest_number_in_b(stack))) //en büyük veya en küçük olma durumu
	{
		if(stack->largest_number_index_b <= ((stack->len_b)/2))
			moves.rb = stack->largest_number_index_b;
		else
			moves.rrb = (stack->len_b - stack->largest_number_index_b);
	}
	else //diğer durum (kendisinden küçük en büyük sayıyı buluyorum.)
	{
		if(other_number_index_in_b(stack, stack->stack_a[index]) <= ((stack->len_b)/2))
			moves.rb = other_number_index_in_b(stack, stack->stack_a[index]);
		else
			moves.rrb = (stack->len_b - other_number_index_in_b(stack, stack->stack_a[index]));
	}
	ft_calculate_moves_cost(&moves);
	printf("%d. INDEX CALCULATE EDİLDİ\n", index);
	printf("bdeki en büyük sayının indexi: %d", stack->largest_number_index_b);
	ft_yazma(&moves);
	return moves;
}

void	ft_calculate_moves_cost(t_moves *moves)
{
	moves->rr = 0;
	moves->rrr = 0;
	while((moves->ra > 0) && (moves->rb > 0))
	{
		moves->rr++;
		moves->ra--;
		moves->rb--;
	}
	while((moves->rra > 0) && (moves->rrb > 0))
	{
		moves->rrr++;
		moves->rra--;
		moves->rrb--;
	}
	moves->cost = moves->ra + moves->rb + moves->rr + moves->rra + moves->rrb + moves->rrr + 1;
}

void	ft_update_largest_number_in_b(t_stack *stack)
{
	int	i;
	int	max_index;

	if (stack->len_b == 0)
		return ;
	i = 1;
	max_index = 0;
	while (i < stack->len_b)
	{
		if (stack->stack_b[i] > stack->stack_b[max_index])
			max_index = i;
		i++;
	}
	stack->largest_number_index_b = max_index;
}

int	ft_largest_number_in_b(t_stack *stack)
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
		}
		i++;
	}
	return number;
}

int	ft_smallest_number_in_b(t_stack *stack)
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
		}
		i++;
	}
	return number;
}

void	ft_push_to_b(t_stack *stack, t_moves *moves)
{
	ft_repeat_function(ft_rr, moves->rr, stack);
	ft_repeat_function(ft_rrr, moves->rrr, stack);
	ft_repeat_function(ft_ra, moves->ra, stack);
	ft_repeat_function(ft_rb, moves->rb, stack);
	ft_repeat_function(ft_rra, moves->rra, stack);
	ft_repeat_function(ft_rrb, moves->rrb, stack);
	ft_pb(stack);
}

void ft_repeat_function(void (*func)(t_stack *), int count, t_stack *stack)
{
	int i;

	i = 0;
	while (i < count)
	{
		func(stack);
		i++;
	}
}

int	other_number_index_in_b(t_stack *stack, int num) //kendisinden küçük en büyük sayıyı buluyor.
{
	int i = 1;
	int max_index;

	max_index = 0;
	while (i < stack->len_b)
	{
		if ((stack->stack_b[i] < num) && (stack->stack_b[i] > stack->stack_b[max_index]))
			max_index = i;
		i++;
	}
	return max_index;
}
