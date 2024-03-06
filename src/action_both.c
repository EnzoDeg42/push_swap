/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:13:51 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/27 13:30:07 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	action_swap(stack_a);
	action_swap(stack_b);
}

void	action_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	action_rotate(stack_a);
	action_rotate(stack_b);
}

void	action_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	action_reverse_rotate(stack_a);
	action_reverse_rotate(stack_b);
}
