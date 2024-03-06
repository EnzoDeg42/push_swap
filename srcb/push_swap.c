/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:39:02 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 16:01:04 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	convert_and_add(t_stack *stack_a, t_stack *stack_b, char *str)
{
	long	n;

	if (ft_strlen_without_firsts_zeros(str) > 11)
		quit("Error: Integer too long\n", stack_a, stack_b);
	if (!is_valid_number_format(str))
		quit("Error: Invalid number\n", stack_a, stack_b);
	n = ft_atol(str);
	if (n < -2147483648 || n > 2147483647)
		quit("Error: Integer overflow\n", stack_a, stack_b);
	if (!add_to_stack(stack_a, n))
		quit("Error: Memory allocation failed\n", stack_a, stack_b);
	return (1);
}

static void	process_multiple_args(t_stack *s_a, t_stack *s_b, char **args)
{
	int	j;

	j = 0;
	while (args[j])
	{
		convert_and_add(s_a, s_b, args[j]);
		j++;
	}
}

static int	convert_and_do(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!action_do(str, stack_a, stack_b))
		quit("Error: Invalid operation\n", stack_a, stack_b);
	return (1);
}

static void	checker(t_stack *stack_a, t_stack *stack_b)
{
	int		fd;
	char	*line;

	if (has_duplicates(stack_a))
		quit("Error: Duplicates found\n", stack_a, stack_b);
	fd = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		convert_and_do(stack_a, stack_b, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (is_sorted(stack_a) && get_stack_size(stack_b) == 0)
		ft_putstr(1, "OK\n");
	else
		ft_putstr(1, "KO\n");
	quit("", stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;
	int		i;

	if (argc < 2)
		return (0);
	initialize_stack(&stack_a);
	initialize_stack(&stack_b);
	i = 1;
	while (i < argc)
	{
		if (ft_strfind(argv[i], ' ') == 0)
		{
			convert_and_add(stack_a, stack_b, argv[i++]);
			continue ;
		}
		array = ft_split(argv[i]);
		process_multiple_args(stack_a, stack_b, array);
		i++;
	}
	checker(stack_a, stack_b);
	return (0);
}
