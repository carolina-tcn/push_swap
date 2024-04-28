/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:51:27 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 18:15:39 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a.len = 0;
	b.len = 0;
	b.first = NULL;
	a.first = NULL;
	if (!create_elements_stack_a(&a, argc, argv))
		return (write(2, "Error\n", 6), 1);
	if (duplicate_elements_stack_a(&a))
		return (write(2, "Error\n", 6), 1);
	assign_index(&a);
	if (!stack_is_ordered(&a))
		sort_algorithm(&a, &b);
	clear_elements(&a);
	clear_elements(&b);
	return (0);
}

void	clear_elements(t_stack *a)
{
	t_element	*tmp;

	tmp = a->first;
	if (!a)
		return ;
	free (a->first);
	while (tmp)
	{
		tmp = tmp->next;
		free (tmp);
	}
}
