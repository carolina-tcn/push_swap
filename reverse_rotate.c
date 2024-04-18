/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:55:59 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/18 18:56:01 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	write(1, "rra\n", 4);
	move_rev_rotate(a);
}

void	rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	move_rev_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	move_rev_rotate(a);
	move_rev_rotate(b);
}

void	move_rev_rotate(t_stack *stack)
{
	t_element	*tmp;

	if (stack->len < 2)
		return ;
	if (stack->len < 3)
		move_swap(stack);
	tmp = stack->first;
	while (tmp && tmp->next->next) //sino seria un seg
		tmp = tmp->next;
	tmp->next->next = stack->first; 
	stack->first = tmp->next;
	tmp->next = NULL;
}
