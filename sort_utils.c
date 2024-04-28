/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:38 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 16:20:01 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_best_rotation_dir(int idx, t_stack *a)
{
	int			i;
	t_element	*tmp;

	i = 1;
	tmp = a->first;
	while (tmp->index != idx)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= (a->len / 2))
		return (1);
	else
		return (2);
}

void	move_index_x_to_top_of_b(int idx, t_stack *b, t_stack *a)
{
	int	direction;

	direction = search_best_rotation_dir(idx, b);
	if (direction == 1)
	{
		while (b->first->index != idx)
		{
			if (b->first->index == idx - 1)
				pa(b, a);
			else
				rb(b);
		}
	}
	else
	{
		while (b->first->index != idx)
		{
			if (b->first->index == idx - 1)
				pa(b, a);
			else
				rrb(b);
		}
	}
	return ;
}

void	move_index_x_to_top_of_a(int idx, t_stack *a)
{
	int	direction;

	direction = search_best_rotation_dir(idx, a);
	if (direction == 1)
	{
		while (a->first->index != idx)
			ra(a);
	}
	else
	{
		while (a->first->index != idx)
			rra(a);
	}
	return ;
}

int	which_chunk_part(t_stack *b, int chunk_size, int chunk_idx_limit)
{
	if (b->first->index > (chunk_idx_limit - (chunk_size / 2)))
	{
		return (1);
	}
	else
		return (0);
}
