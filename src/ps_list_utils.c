/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:25:31 by mariramo          #+#    #+#             */
/*   Updated: 2025/07/31 13:40:18 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*create_node(int value)
{
	t_content	*new_content;
	t_list		*new_node;

	new_content = malloc (sizeof(t_content));
	if (!new_content)
		return (NULL);
	new_content -> value = value;
	new_content -> sorted_pos = -1;
	new_node = malloc (sizeof(t_list));
	if (!new_node)
	{
		free (new_content);
		return (NULL);
	}
	new_node -> content = new_content;
	new_node -> next = NULL;
	return (new_node);
}

void	add_node_back(t_list **stack, t_list *new_node)
{
	t_list	*temp;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new_node;
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack)-> next;
		free ((*stack)-> content);
		free (*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack -> next)
	{
		if (stack -> content -> value > stack -> next -> content -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
