/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:08:35 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/08 18:38:57 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	three_sort(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)-> content -> value;
	b = (*stack)-> next -> content -> value;
	c = (*stack)-> next -> next -> content -> value;
	if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a > b && b > c)
	{
		swap_a(stack);
		rev_rotate_a(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(stack);
}

static void	minis_two_three(t_list **stack_a, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->content->value > (*stack_a)->next->content->value)
			swap_a(stack_a);
	}
	else if (size == 3)
		three_sort(stack_a);
}

static void	minis_four_five(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	cost;

	while (stack_size(*stack_a) > 3)
	{
		min_pos = get_min_value_pos(*stack_a);
		cost = get_rotate_cost(stack_a, min_pos);
		while (min_pos != 0)
		{
			if (cost > 0)
				rotate_a(stack_a);
			else
				rev_rotate_a(stack_a);
			min_pos = get_min_value_pos(*stack_a);
			cost = get_rotate_cost(stack_a, min_pos);
		}
		push_b(stack_a, stack_b);
	}
	three_sort(stack_a);
	while (*stack_b)
		push_a(stack_b, stack_a);
}

void	mini_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size < 2 || size > 5)
		return ;
	if (size <= 3)
		minis_two_three(stack_a, size);
	else
		minis_four_five(stack_a, stack_b);
}
