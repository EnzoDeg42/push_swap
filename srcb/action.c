/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:13:48 by edegraev          #+#    #+#             */
/*   Updated: 2024/03/03 10:54:46 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_swap(t_stack *stack)
{
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	ft_swap(&stack->top->value, &stack->top->next->value);
	ft_swap(&stack->top->position, &stack->top->next->position);
	ft_swap(&stack->top->cost, &stack->top->next->cost);
	ft_swap(&stack->top->ra, &stack->top->next->ra);
	ft_swap(&stack->top->rb, &stack->top->next->rb);
	ft_swap(&stack->top->rra, &stack->top->next->rra);
	ft_swap(&stack->top->rrb, &stack->top->next->rrb);
}

void	action_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	if (stack_a->top == NULL)
		return ;
	current = stack_a->top;
	stack_a->top = stack_a->top->next;
	current->next = stack_b->top;
	stack_b->top = current;
}

void	action_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	current = stack->top;
	tmp = stack->top;
	while (current->next != NULL)
		current = current->next;
	stack->top = stack->top->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	action_reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	current = stack->top;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}
