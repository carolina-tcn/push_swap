/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:51:27 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/19 21:03:20 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	//PRIMERO COMPROBAR ARGS (enteros//ningun caracter)
	printf("Pasa los chequeos, seguimos!!!\n");

	// VAMOS A CREAR NUESTRO TABLERO DE JUEGO (stacks y piezas)
	// opcion 1 (pero cuando lo mande a una funcion que pueda cambiar quien es first
	// tendre que mandarlos como &a, &b, para que alli sean dobles punteros **a, **b)
	// t_ficha *stack_a;
	// t_ficha *stack b;
	// a = NULL;
	// b = NULL;
	//opcion 2;
	// t_stack *a = malloc(sizeof(t_stack));
	// t_stack *b = malloc(sizeof(t_stack));
	// opcion 3:
	a.len = 0;
	b.len = 0;
	b.first = NULL;
	a.first = NULL;

	if (!create_elements_stack_a(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	print_stack(&a);
	// VAMOS A MIRAR SI HAY FICHAS REPETIDAS (num)
	if (duplicate_elements_stack_a(&a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	// VAMOS A ASIGNAR EL INDEX A LAS FICHAS
	assign_index(&a);
	printf("Printo los index\n");
	print_index(&a);

	//CREO LOS MOVIMIENTOS DEL JUEGO Y LOS PRUEBO
	/*printf("After print index I print the stack again\n");
	print_stack(&a);
	printf("testing pb()\n");
	pb(&a, &b);
	printf("result after pb() of stack a\n");
	print_stack(&a);
	printf("stack b\n");
	print_stack(&b);
	printf("testing pa()\n");
	pa(&b, &a);
	printf("result after pa() of stack a\n");
	print_stack(&a);
	printf("stack b\n");
	print_stack(&b);
	
	printf("\n\n");
	printf("Prueba rotate\n");
	printf("stack a\n");
	print_stack(&a);
	ra(&a);
	print_stack(&a);

	printf("\n");
	printf("prueba rev rotate");
	rra(&a);
	print_stack(&a);
	*/
	//(manana antes de que llegue marc)
	
	if (!stack_is_ordered(&a))
	{
		printf("El stack no esta ordenado e intentaremos resolverlo\n");
		if (a.len == 2)
			sort_two(&a);
		else if (a.len == 3)
			sort_three(&a);
		else if (a.len == 4)
			sort_four(&a, &b);
		else if (a.len == 5)
			sort_five(&a, &b);
		else if (a.len > 5 && a.len <= 100)
			sort_bigs(&a, &b, 4);
		else if (a.len > 100)
			sort_bigs(&a, &b, 8);
		//search_best_rotation_dir(6, &a);
	}
	else
		printf("El stack esta ordenado y no hago nada\n");
	
	// ANTES DE IRME LIBERAR LAS FICHAS CREADAS
/*void	clear_elements(t_stack *a)
{
	t_element	*tmp;

	tmp = a->first;

	if (!a)
		return ;
	while (tmp)
	{
		tmp = tmp->next;
		free (tmp);
	}
		me estoy sasltando la primera!!!!

}*/
	return (0);
}
