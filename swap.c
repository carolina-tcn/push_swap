/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:57:12 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/24 22:54:02 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	move_swap(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	move_swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	move_swap(a);
	move_swap(b);
}

void	move_swap(t_stack *stack)
{
	t_element	*first;
	t_element	*second;

	if (stack->len < 2)
		return ;
	first = stack->first;
	second = stack->first->next;
	stack->first = second;
	first->next = second->next;
	second->next = first;
}
