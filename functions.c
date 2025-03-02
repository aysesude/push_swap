/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:51:51 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/02 17:51:40 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
}

void ft_sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
}

void ft_ss(t_stack *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}

void	ft_pa(t_stack *stack)
{
	int	i;

	if (stack->len_b > 0)
	{
		i = stack->len_a;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = stack->stack_b[0];
		while (i < stack->len_b - 1)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->len_a++;
		stack->len_b--;
	}
}

void	ft_pb(t_stack *stack)
{
	int	i;

	if (stack->len_a > 0)
	{
		i = stack->len_b;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = stack->stack_a[0];
		while (i < stack->len_a - 1)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->len_b++;
		stack->len_a--;
	}
}

void	ft_ra(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->stack_a[0];
	if(stack->len_a > 1)
	{
		while(i < stack->len_a)
		{
			stack->stack_a[i] = stack->stack_a[i+1];
			i++;
		}
		stack->stack_a[stack->len_a - 1] = tmp;
	}
}

void	ft_rb(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->stack_b[0];
	if(stack->len_b > 1)
	{
		while(i < stack->len_b)
		{
			stack->stack_b[i] = stack->stack_b[i+1];
			i++;
		}
		stack->stack_b[stack->len_b - 1] = tmp;
	}
}

void	ft_rr(t_stack *stack)
{
	ft_rb(stack);
	ft_ra(stack);
}

void	ft_rra(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stack->stack_a[stack->len_a - 1];
	if(stack->len_a > 1)
	{
		while(i < stack->len_a)
		{
			stack->stack_a[stack->len_a - i] = stack->stack_a[stack->len_a - 1 - i];
			i++;
		}
		stack->stack_a[0] = tmp;
	}
}

void	ft_rrb(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stack->stack_b[stack->len_b - 1];
	if(stack->len_b > 1)
	{
		while(i < stack->len_b)
		{
			stack->stack_b[stack->len_b - i] = stack->stack_b[stack->len_b - i - 1];
			i++;
		}
		stack->stack_b[0] = tmp;
	}
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}
