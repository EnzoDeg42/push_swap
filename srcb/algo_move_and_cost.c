/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_and_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:47:21 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/28 09:58:50 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mc_ra_rb(t_data *d, int *move, int *cost)
{
	if (d->ra > d->rb)
	{
		if (d->ra < *cost)
		{
			*cost = d->ra;
			*move = 1;
		}
	}
	else
	{
		if (d->rb < *cost)
		{
			*cost = d->rb;
			*move = 1;
		}
	}
}

static void	mc_rra_rrb(t_data *d, int *move, int *cost)
{
	if (d->rra > d->rrb)
	{
		if (d->rra < *cost)
		{
			*cost = d->rra;
			*move = 2;
		}
	}
	else
	{
		if (d->rrb < *cost)
		{
			*cost = d->rrb;
			*move = 2;
		}
	}
}

int	algo_move_and_cost(t_data *d, int *move, int *cost)
{
	if (!cost || !move)
		return (0);
	*move = 0;
	*cost = d->ra + d->rb + d->rra + d->rrb;
	if (d->ra == 0 && d->rb == 0 && d->rra == 0 && d->rrb == 0)
		return (0);
	mc_ra_rb(d, move, cost);
	mc_rra_rrb(d, move, cost);
	if (d->ra + d->rrb < *cost)
	{
		*cost = d->ra + d->rrb;
		*move = 3;
	}
	if (d->rra + d->rb < *cost)
	{
		*cost = d->rra + d->rb;
		*move = 4;
	}
	if (d->ra + d->rb + d->rra + d->rrb == *cost)
		return (0);
	else
		return (1);
}
