/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_k_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:13:09 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/15 14:28:56 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	send_chunks(t_list **stack_a, t_list **stack_b, int start, int end)
{
	int	i;
	int	size;
	int	pos;

	if (!stack_a || !(*stack_a))
		return ;
	size = stack_size(*stack_a);
	i = 0;
	while (i < size && *stack_a)
	{
		pos = (*stack_a)->content->sorted_pos;
		if (pos >= start && pos < end)
		{
			push_b(stack_a, stack_b);
			size--;
		}
		else
		{
			rotate_a(stack_a);
			i++;
		}
	}
}

static void	reinsert_sorted(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;
	int	cost;

	while (*stack_b)
	{
		max_pos = get_max_value_pos(*stack_b);
		cost = get_rotate_cost(stack_b, max_pos);
		while (max_pos != 0)
		{
			if (cost > 0)
				rotate_b(stack_b);
			else
				rev_rotate_b(stack_b);
			max_pos = get_max_value_pos(*stack_b);
			cost = get_rotate_cost(stack_b, max_pos);
		}
		push_a(stack_b, stack_a);
	}
}

void	k_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;
	int	start;
	int	end;

	if (!stack_a || !(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	start = 0;
	end = chunk_size;
	while (*stack_a)
	{
		send_chunks(stack_a, stack_b, start, end);
		start = end;
		end = end + chunk_size;
		if (end > size)
			end = size;
	}
	reinsert_sorted(stack_a, stack_b);
}
