/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:51:51 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/09 20:17:23 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	if(stack->ss_flag == 0)
	{
		write(1,"sa\n",3);
	}
}

void ft_sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	if(stack->ss_flag == 0)
	{
		write(1,"sb\n",3);
	}
}

void ft_ss(t_stack *stack)
{
	stack->ss_flag=1;
	ft_sa(stack);
	ft_sb(stack);
	write(1, "ss\n", 3);
	stack->ss_flag=0;
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
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
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
	if(stack->rr_flag == 0)
	{
		write(1,"ra\n", 3);
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
	if(stack->rr_flag == 0)
	{
		write(1,"rb\n", 3);
	}
}

void	ft_rr(t_stack *stack)
{
	stack->rr_flag = 1;
	ft_rb(stack);
	ft_ra(stack);
	write(1, "rr\n", 3);

	stack->rr_flag = 0;
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
	if(stack->rrr_flag == 0)
	{
		write(1,"rra\n", 4);
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
	if(stack->rrr_flag == 0)
	{
		write(1,"rrb\n", 4);
	}
}

void	ft_rrr(t_stack *stack)
{
	stack->rrr_flag = 1;
	ft_rra(stack);
	ft_rrb(stack);
	write(1, "rrr\n", 4);
	stack->rrr_flag = 0;
}
