/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:51:06 by ctacconi          #+#    #+#             */
/*   Updated: 2024/04/25 16:32:43 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[0] == '-' && !is_digit(str[1]))
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_max_min_int(char *str)
{
	int		len;
	char	*str_to_check;

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
		if (ft_strncmp("2147483648", str_to_check, len) < 0)
			return (0);
	}
	else
	{
		if (ft_strncmp("2147483647", str_to_check, len) < 0)
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
		if (!check_int_format(argv[i]))
			return (0);
		if (!check_max_min_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
