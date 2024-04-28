/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:11 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 16:27:54 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	write(1, "ra\n", 3);
	move_rotate(a);
}

void	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	move_rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	write(1, "rr\n", 3);
	move_rotate(a);
	move_rotate(b);
}

void	move_rotate(t_stack *stack)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (stack->len < 2)
		return ;
	if (stack->len < 3)
	{
		move_swap(stack);
		return ;
	}
	tmp = stack->first;
	tmp2 = stack->first;
	stack->first = stack->first->next;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = tmp2;
	tmp2->next = NULL;
}
