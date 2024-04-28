/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:51:41 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 16:33:11 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *src, t_stack *dst)
{
	write(1, "pa\n", 3);
	move_push(src, dst);
}

void	pb(t_stack *src, t_stack *dst)
{
	write(1, "pb\n", 3);
	move_push(src, dst);
}

void	move_push(t_stack *src, t_stack *dst)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (src->len < 1)
		return ;
	if (dst->first == NULL)
	{
		tmp = src->first;
		src->first = src->first->next;
		dst->first = tmp;
		dst->first->next = NULL;
		src->len--;
		dst->len++;
	}
	else
	{
		tmp2 = dst->first;
		tmp = src->first;
		src->first = src->first->next;
		dst->first = tmp;
		dst->first->next = tmp2;
		src->len--;
		dst->len++;
	}
}
