/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:31:27 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/05 07:25:10 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

#include <stdio.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;
	int		cost;
	int		largest_number_index_b;
	char	*moves;
}			t_stack;

void	ft_check_input(int argc, char **argv);

void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);

void	ft_first_moves(t_stack *stack);
void	ft_moves_for_three_number(t_stack *stack);
void	ft_moves_for_more_than_three_number(t_stack *stack);
int		ft_calculate_cost(t_stack *stack, int index);

#endif
