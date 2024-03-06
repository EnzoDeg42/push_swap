/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:02:29 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 15:26:54 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_without_firsts_zeros(char *str)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		total++;
	}
	return (total);
}
