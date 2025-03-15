/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:31:27 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/10 15:32:34 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# include <stdio.h>
# include <unistd.h>

typedef struct s_stck
{
	int		*stck_a;
	int		*stck_b;
	int		len_a;
	int		len_b;
	int		ss_flag;
	int		rr_flag;
	int		rrr_flag;
	int		largest_number_index_b;
	int		other_number_index_b;
}			t_stck;

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

void	ft_exit(void);
void	ft_check_full_space(char **argv, int i, int j);
void	ft_check_input(int argc, char **argv);
void	ft_check_input_control(char **argv, int i, int j);
void	ft_check_same_number(t_stck *stck);
void	ft_is_stck_sorted(t_stck *stck);
int		ft_new_atoi(char **split_numbers, t_stck *stck, const char *str);
char	**ft_free(char **result);
void	ft_numbers2(char **split_numbers, t_stck *stck);
void	ft_sa(t_stck *stck);
void	ft_sb(t_stck *stck);
void	ft_ss(t_stck *stck);
void	ft_pa(t_stck *stck);
void	ft_pb(t_stck *stck);
void	ft_ra(t_stck *stck);
void	ft_rb(t_stck *stck);
void	ft_rr(t_stck *stck);
void	ft_rra(t_stck *stck);
void	ft_rrb(t_stck *stck);
void	ft_rrr(t_stck *stck);
void	ft_first_moves(t_stck *stck);
void	ft_moves_for_three_number(t_stck *stck);
void	ft_moves_for_more_than_three_number(t_stck *stck);
t_moves	ft_calculate_cost(t_stck *stck, int i);
void	ft_calculate_moves_cost(t_moves *moves);
void	ft_update_large_in_b(t_stck *stck);
int		ft_lab(t_stck *stck);
int		ft_smb(t_stck *stck);
void	ft_push_to_b(t_stck *stck, t_moves *moves);
void	ft_repeat_function(void (*func)(t_stck *), int count, t_stck *stck);
int		ft_sl_in_b(t_stck *stck, int num);
void	ft_push_to_a(t_stck *stck);
void	ft_last_sort(t_stck *stck);
int		other_number_index_in_a(t_stck *stck, int num);
int		ft_smallest_number_index_in_a(t_stck *stck);

#endif
