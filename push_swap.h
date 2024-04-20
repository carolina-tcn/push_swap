/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:55:46 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/19 20:59:45 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> 

//Elements
typedef struct s_element
{
	int 	num;
	int 	index;
	struct s_element	*next;
}	t_element;

//Stack
typedef struct s_stack
{
	t_element *first;
	int len;
} t_stack;

//Check args, utils, stack
int	check_args(int argc, char **argv);
int	check_int_format(char *str);
int	is_digit(char c);
int check_max_min_int(char *str);
int	ft_strlen(const char *str);
int	ft_strncmp(char *s1, char *s2, int n);
int	create_elements_stack_a(t_stack *a, int argc, char **argv);
int	ft_atoi(const char *str);
int	duplicate_elements_stack_a(t_stack *a);
void	print_stack(t_stack *a);
void	assign_index(t_stack *a);
void	print_index(t_stack *a);

//Movimientos swap
void	sa(t_stack *a);
void	move_swap(t_stack *stack);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

//Movimientos push
void	pa(t_stack *src, t_stack *dst);
void	pb(t_stack *src, t_stack *dst);
void	move_push(t_stack *src, t_stack *dst);

//Moviemientos rotate
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	move_rotate(t_stack *stack);

//Movimientos rev_rotate
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	move_rev_rotate(t_stack *stack);

//algoritmo
int	stack_is_ordered(t_stack *a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	move_index_x_to_top(int idx, t_stack *a);
int search_best_rotation_dir(int idx, t_stack *a);
void	move_in_chunks_to_b(t_stack *a, t_stack *b, int num_chunks);
void	sort_bigs(t_stack *a, t_stack *b, int num_chunks);

#endif
