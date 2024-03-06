/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:33:32 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/08 17:50:47 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	display_stack_data(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("value: %d, position: %d, ", current->value, current->position);
		printf("cost: %d\n", current->cost);
		current = current->next;
	}
}

void	display_stack_data_variation(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("value: %d, cost: %d, ", current->value, current->cost);
		printf("ra: %d, rb: %d, ", current->ra, current->rb);
		printf("rra: %d, rrb: %d\n", current->rra, current->rrb);
		current = current->next;
	}
}

void	display_vertical_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a->top;
	current_b = stack_b->top;
	printf("a b\n- -\n");
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			printf("%d ", current_a->value);
			current_a = current_a->next;
		}
		else
			printf("  ");
		if (current_b != NULL)
		{
			printf("%d", current_b->value);
			current_b = current_b->next;
		}
		printf("\n");
	}
	printf("- -\n\n");
}
