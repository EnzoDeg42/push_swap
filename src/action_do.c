/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:59:28 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 11:53:08 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	single_actions(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "sa") == 0)
		action_swap(stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		action_swap(stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		action_swap_both(stack_a, stack_b);
	else if (ft_strcmp(str, "pa") == 0)
		action_push(stack_b, stack_a);
	else if (ft_strcmp(str, "pb") == 0)
		action_push(stack_a, stack_b);
	else if (ft_strcmp(str, "ra") == 0)
		action_rotate(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		action_rotate(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		action_rotate_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	double_actions(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(str, "rra") == 0)
		action_reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		action_reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		action_reverse_rotate_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	action_do(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (single_actions(str, stack_a, stack_b))
	{
		ft_putstr(1, str);
		ft_putstr(1, "\n");
		return (1);
	}
	else if (double_actions(str, stack_a, stack_b))
	{
		ft_putstr(1, str);
		ft_putstr(1, "\n");
		return (1);
	}
	else
	{
		quit("Error action\n", stack_a, stack_b);
		return (0);
	}
}
