/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:38 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/19 20:46:36 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Recorremos la lista hasta que encontremos el index que queremos (pero sin mover la lista i sin hacer movimientos)
// En ese while contamos las iteraciones que hacemos
// cuando se rompa el while comparao las iteracion con la mitad del len
// Si es < es una direccion
// Sino es la otra
int search_best_rotation_dir(int idx, t_stack *a)
{
	int 		i;
	t_element	*tmp;

	i = 1;
	tmp = a->first;
	while (tmp->index != idx)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < (a->len / 2))
	{
		//printf("len vale: %i", a->len);
		return (1);
	}
	else
		return (2);
}

void	move_index_x_to_top(int idx, t_stack *a)
{
	int direction;

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


