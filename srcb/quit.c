/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:49 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 11:05:32 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

static void	ft_putchar(int exit, char c)
{
	write(exit, &c, 1);
}

void	ft_putstr(int exit, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(exit, str[i++]);
}

void	quit(char *msg, t_stack *stack_a, t_stack *stack_b)
{
	int	show_error;

	show_error = 0;
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (ft_strlen(msg) > 0)
	{
		if (show_error)
			ft_putstr(2, msg);
		else
			ft_putstr(2, "Error\n");
	}
	exit(0);
}
