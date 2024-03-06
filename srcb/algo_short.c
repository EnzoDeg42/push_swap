/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:36 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 13:33:50 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->value > stack_a->top->next->value)
		action_do("sa", stack_a, stack_b);
}

static void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && b < c && a < c)
		action_do("sa", stack_a, stack_b);
	else if (a > b && b > c && a > c)
	{
		action_do("sa", stack_a, stack_b);
		action_do("rra", stack_a, stack_b);
	}
	else if (a > b && b < c && a > c)
		action_do("ra", stack_a, stack_b);
	else if (a < b && b > c && a < c)
	{
		action_do("sa", stack_a, stack_b);
		action_do("ra", stack_a, stack_b);
	}
	else if (a < b && b > c && a > c)
		action_do("rra", stack_a, stack_b);
}

int	short_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	n;

	n = get_stack_size(stack_a);
	if (n == 1)
		return (1);
	else if (n == 2)
		sort_two(stack_a, stack_b);
	else if (n == 3)
		sort_three(stack_a, stack_b);
	else
		return (0);
	return (1);
}
