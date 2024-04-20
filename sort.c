/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:23 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/19 20:46:50 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	sa(a);
}

void	sort_three(t_stack *a)
{
	if (a->first->index == 2 && a->first->next->index == 1 && a->first->next->next->index == 3)
		sa(a);
	else if (a->first->index == 3 && a->first->next->index == 2 && a->first->next->next->index == 1)
	{
		sa(a);
		rra(a);
	}
	else if (a->first->index == 3 && a->first->next->index == 1 && a->first->next->next->index == 2)
		ra(a);
	else if (a->first->index == 1 && a->first->next->index == 3 && a->first->next->next->index == 2)
	{
		sa(a);
		ra(a);
	}
	else if (a->first->index == 2 && a->first->next->index == 3 && a->first->next->next->index == 1)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	move_index_x_to_top(1, a);
	pb(a, b);
	assign_index(a);
	sort_three(a);
	pa(b, a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	move_index_x_to_top(1, a);
	pb(a, b);
	move_index_x_to_top(2, a);
	pb(a, b);
	assign_index(a);
	sort_three(a);
	pa(b, a);
	pa(b, a);
}
