/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:46:55 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 18:39:13 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_a(t_stack *a, t_stack *b)
{
	while (a->len)
		pb(a, b);
}

void	move_in_chunks_to_b(t_stack *a, t_stack *b, int num_chunks)
{
	t_chunk	c_data;

	c_data.chunk_size = a->len / num_chunks;
	c_data.chunk_idx_limit = c_data.chunk_size;
	c_data.pieces_to_move = c_data.chunk_size;
	c_data.i = 0;
	while (c_data.i++ < num_chunks)
	{
		while (c_data.pieces_to_move && a->len)
		{
			if (a->first->index <= c_data.chunk_idx_limit)
			{
				pb(a, b);
				if (which_chunk_part(b, c_data.chunk_size,
						c_data.chunk_idx_limit) == 1)
					rb(b);
				c_data.pieces_to_move--;
			}
			else
				ra(a);
		}
		c_data.pieces_to_move = c_data.chunk_size;
		c_data.chunk_idx_limit += c_data.pieces_to_move;
	}
	while_a(a, b);
}

void	sort_bigs(t_stack *a, t_stack *b, int num_chunks)
{
	int	index_to_move;

	move_in_chunks_to_b(a, b, num_chunks);
	index_to_move = b->len;
	while (b->len)
	{
		move_index_x_to_top_of_b(index_to_move, b, a);
		pa(b, a);
		index_to_move--;
		if ((a->len >= 2) && a->first->next->index == index_to_move)
		{
			sa(a);
			index_to_move--;
		}
	}
}
