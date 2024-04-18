/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:23 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/18 18:56:27 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
	sa(a);

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

void	sort_four(t_stack *a)
{
	move_index_x_to_top(1, &a);
	pb(&a, &b);
	assign_index(&a);
	sort_three(&a);
	pa(&b, &a);
	pa(&b, &a);
}

void	sort_five(t_stack *a)
{
	move_index_x_to_top(1, &a);
	pb(&a, &b);
	move_index_x_to_top(2, &a);
	pb(&a, &b);
	assign_index(&a);
	sort_three(&a);
	pa(&b, &a);
	pa(&b, &a);
}

/*void	sort_hundred(t_stack *a)
{
	//mirar si en el stack a tengo numeros del chunk 1 (1 - 20) --> hold first
	//miro si hay un segundo numero --> hold second
	//miro el coste de movimientos para mandarlos arriba del todo (con ra o rra)
	//		divido en dos, hago la mitad de la lista
	//		miro la posicion en la que esta el hold first-->si esta entre 0 y 50 --> ra
	//		si esta entre 51 y 100 --> rra
}*/