/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:48:17 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/08 18:48:17 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_list	*init_stack(int argc, char **argv)
{
	t_list	*stack;

	stack = load_stack(argc, argv);
	if (!stack)
		return (NULL);
	if (!load_sorted_positions(&stack, stack_size(stack)))
	{
		free_stack(&stack);
		return (NULL);
	}
	return (stack);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		three_sort(stack_a);
	else if (size <= 5)
		mini_sort (stack_a, stack_b, size);
	else
		k_sort (stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = init_stack (argc, argv);
	if (!stack_a)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(stack_a))
	{
		free_stack (&stack_a);
		return (0);
	}
	size = stack_size(stack_a);
	sort_stack (&stack_a, &stack_b, size);
	free_stack (&stack_a);
	free_stack (&stack_b);
	return (0);
}
