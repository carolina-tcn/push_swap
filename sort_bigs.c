/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:46:55 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/19 21:03:06 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The first mision is mover el primer chunk
// si tengo 100 piezas y llamo a mover en 4 chunks, el primer chunk sera 
// hasta la pieza con index 25, y movere en este caso 25 piezas
void move_in_chunks_to_b(t_stack *a, t_stack *b, int num_chunks)
{
	int chunk_size;
	int chunk_idx_limit;
	int pieces_to_move;
	int i;

	chunk_size = a->len / num_chunks;
	chunk_idx_limit = chunk_size;
	pieces_to_move = chunk_size;
	i = 0;
	while(i < num_chunks)
	{
		printf("en el chunk %d:\n", i + 1);
		printf("en este chunk tengo que mover %d\n", pieces_to_move);
		printf("El indice limite de este chunk es: %d\n", chunk_idx_limit);
		while (pieces_to_move && a->len)
		{
			if (a->first->index <= chunk_idx_limit)
			{
				pb(a, b);
				pieces_to_move--;
			}
			ra(a);
		}
		//Tengo que actualizar cosas
		pieces_to_move = chunk_size;
		chunk_idx_limit += pieces_to_move;
		i++;
	}
	while(a->len)
	{
		printf("entro en el bucle del pico restante\n");
		pb(a, b);
	}
	//printf("A\n");
	//print_stack(a);
	//printf("B\n");
	//print_stack(b);
//??? realmente pieces to move no haria falta???
}

void sort_bigs(t_stack *a, t_stack *b, int num_chunks)
{
	int index_to_move;

	move_in_chunks_to_b(a, b, num_chunks);
	index_to_move = b->len;

	while (b->len)
	{
		move_index_x_to_top(index_to_move, b);
		pa(b, a);
		index_to_move--;
	}
//	printf("A\n");
//	print_stack(a);
//	printf("B\n");
//	print_stack(b);
}
