/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:31:27 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/09 22:04:52 by aysesudecam      ###   ########.fr       */
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
	int		ss_flag;
	int		rr_flag;
	int		rrr_flag;
	int		largest_number_index_b;
	int		other_number_index_b;
}			t_stack;

typedef struct s_moves
{
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		cost;
}			t_moves;

void	ft_check_input(int argc, char **argv);
void	ft_check_same_number(t_stack *stack);
void	ft_is_stack_sorted(t_stack *stack);
void	write_stacks(t_stack *stack);

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
t_moves	ft_calculate_cost(t_stack *stack, int index);
void	ft_calculate_moves_cost(t_moves *moves);
int		ft_largest_number_in_b(t_stack *stack);
int		ft_smallest_number_in_b(t_stack *stack);
void	ft_update_largest_number_in_b(t_stack *stack);
void	ft_push_to_b(t_stack *stack, t_moves *moves);
void	ft_repeat_function(void (*func)(t_stack *), int count, t_stack *stack);
int		other_number_index_in_b(t_stack *stack, int num);
void	ft_push_to_a(t_stack *stack);
int		other_number_index_in_a(t_stack *stack, int num);
int		ft_new_atoi(char **split_numbers, const char *str);
char	**ft_free(char **result);
void	ft_exit();
int	ft_smallest_number_index_in_a(t_stack *stack);
void	ft_last_sort(t_stack *stack);


#endif
