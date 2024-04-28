/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:56 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 17:46:48 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_elements_stack_a(t_stack *a, int argc, char **argv)
{
	t_element	*new_element;
	t_element	*tmp;
	int			i;

	i = 1;
	new_element = malloc(sizeof(t_element));
	if (!new_element)
		return (0);
	new_element->num = ft_atoi(argv[i]);
	a->first = new_element;
	a->len++;
	i++;
	while (i < argc)
	{
		new_element = malloc(sizeof(t_element));
		if (!new_element)
			return (0);
		tmp = a->first;
		add_elements(new_element, tmp, argv, i);
		i++;
		a->len++;
	}
	return (1);
}

int	duplicate_elements_stack_a(t_stack *a)
{
	t_element	*tmp;
	t_element	*tmp2;

	tmp = a->first;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->num == tmp2->num)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	assign_index(t_stack *a)
{
	t_element	*tmp;
	t_element	*tmp2;
	int			index;

	tmp = a->first;
	while (tmp)
	{
		index = 0;
		tmp2 = a->first;
		while (tmp2)
		{
			if (tmp->num > tmp2->num)
				index++;
			tmp2 = tmp2->next;
		}
		tmp->index = index + 1;
		tmp = tmp->next;
	}
}

int	stack_is_ordered(t_stack *a)
{
	t_element	*tmp;

	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_algorithm(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		sort_two(a);
	else if (a->len == 3)
		sort_three(a);
	else if (a->len == 4)
		sort_four(a, b);
	else if (a->len == 5)
		sort_five(a, b);
	else if (a->len > 5 && a->len <= 100)
		sort_bigs(a, b, 4);
	else if (a->len > 100)
		sort_bigs(a, b, 8);
}
