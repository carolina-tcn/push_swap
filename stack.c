/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:56:56 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/18 18:56:58 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *a)
{
	t_element	*tmp;
	tmp = a->first;

	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}

void	print_index(t_stack *a)
{
	t_element	*tmp;
	tmp = a->first;

	while (tmp)
	{
		printf("%d\n", tmp->index);
		tmp = tmp->next;
	}
}

int create_elements_stack_a(t_stack *a, int argc, char **argv)
{
	//Primero voy a hacer esto para solo la ficha en posicion argv[1]
	// la pondre en stack a, y luego cuando vuelva al main mirare que
	// la haya puesto bien
	t_element	*new_element;
	t_element   *tmp;
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
		new_element->num = ft_atoi(argv[i]);
		tmp = a->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_element;
		new_element->next = NULL;
		i++;
		a->len++;
	}
	// Cuando me funcione intentare hacerlo pero con dos fichas poniendolas correctamente
	// Y si me sale , significa que lo que he hecho con la SEGUNDA ficha, si lo pongo bien en un while vale para todo
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
		while (tmp2 && tmp2->next) //IMP tmp!!
		{
			tmp2 = tmp2->next;
			if (tmp->num == tmp2->num)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	assign_index(t_stack *a)
{
	t_element	*tmp;
	t_element	*tmp2;
	int index; 

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
