/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:38 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/18 18:56:40 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int min_index(t_stack *a)
{
	t_element	tmp;
	int   		i;
}

int max_index(t_stack *a)
{

}*/

void	move_index_x_to_top(int idx, t_stack *a)
{
	while (a->first->index != idx)
		ra(a);
	return ;
	//mientras no quede arriba lo que busco roto
}

/*int search_best_rotation_dir(int idx, t_stack *a)
{
	//si mejor ra (hacia arriba)
		return (1);
	//si mejor rra (hacia abajo)
		return (2);
}*/
