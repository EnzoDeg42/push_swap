/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:35:30 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 14:31:17 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whtspc(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number_format(char *str)
{
	int	i;
	int	digit_present;

	i = 0;
	digit_present = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (is_whtspc(str[i]))
		{
			i++;
			break ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		digit_present = 1;
		i++;
	}
	if (!digit_present)
		return (0);
	return (1);
}
