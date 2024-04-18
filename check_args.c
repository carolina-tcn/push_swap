/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:51:06 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/18 18:51:09 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1  si hay - tiene que estar en la primera posicion
//2  Si hay un - si o si tiene que seguirle un digito
//3  solo pueden haber digitos o un simbolo -
//4  Almenos tiene que haber un digito no puede ser un string vacio
int	check_int_format(char *str)
{
	int	i;

	i = 0;

	printf("Entro a chequear el parametro |%s|\n", str);
	if (str[i] == '\0')
		return (0);
	//paso 1 si hay - tiene que estar en la primera posicion
	//Si hay un - si o si tiene que seguirle un digito
	if (str[0] == '-' && !is_digit(str[1]))
		return (0);
	if (str[0] == '-')
		i++;
	//solo pueden haber digitos o un simbolo -
	while (str[i])
	{
		//printf("%c\n", str[i]);
		if(!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//"21474836470"
//Maximum Integer Value: 2147483647
//Minimum Integer Value: -2147483648
// int check_max_min_int(char *str)
// {
// 	int len;

// 	printf("En check_max_min_int evaluando a |%s|\n", str);
// 	// adelantar el puntero comiendome los espacios absurdos
// 	len = ft_strlen(str);
// 	// Si es negativo i tiene mas de 11 malo, si tiene menos de 10 bueno i sino hago strcmpp si es negativo es que es malo
// 	if (str[0] == '-')
// 	{
// 		if (len > 11)
// 			return (0);
// 		if (len < 11)
// 			return (1);
// 		if (ft_strncmp("-2147483648", str, len) < 0)
// 			return (0);
// 	}
// 	else
// 	{
// 		if (len > 10)
// 			return (0);
// 		if (len < 10)
// 			return (1);
// 		if (ft_strncmp("2147483647", str, len) < 0)
// 			return (0);
// 	}
// 	return (1);
// }

int check_max_min_int(char *str)
{
	int len;
	char *str_to_check;

	str_to_check = str;
	if (str_to_check[0] == '-')
		str_to_check++;
	while (*str_to_check == '0' && *(str_to_check + 1) == '0')
		str_to_check++;
	len = ft_strlen(str_to_check);
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	if (str[0] == '-')
	{
		if (ft_strncmp("2147483648", str, len) < 0)
			return (0);
	}
	else
	{
		if (ft_strncmp("2147483647", str, len) < 0)
			return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;
	i = 1;
	while (i < argc)
	{
		//Chequeo 1 si hay algun cracter no valido es que esta mal
	 	if (!check_int_format(argv[i]))
	 		return (0);
	 	//Chequeo 2
	 	if (!check_max_min_int(argv[i]))
	 		return (0);
	 	i++;
	}
	// while (argv[i])
	// {
	// 	if (!check_int(argv[i]))
	// 		return (0);
	// 	i++;
	// }
	//Argumentos que no sean enteros
	
	//que no pasen de MAX INT MIN INT
	return (1);
}
