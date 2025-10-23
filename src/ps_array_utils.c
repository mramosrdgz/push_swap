/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:46:56 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/07 14:04:25 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*create_array(t_list **stack, int size)
{
	int		*array;
	t_list	*current;
	int		i;

	array = malloc (sizeof(int) * size);
	if (!array)
		return (NULL);
	current = *stack;
	i = 0;
	while (i < size && current)
	{
		array[i] = current -> content -> value;
		current = current -> next;
		i++;
	}
	return (array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	get_value_pos(int *array, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	load_sorted_positions(t_list **stack, int size)
{
	int		*array;
	int		pos;
	t_list	*current;

	array = create_array(stack, size);
	if (!array)
		return (0);
	sort_array (array, size);
	current = *stack;
	while (current)
	{
		pos = get_value_pos(array, current -> content -> value, size);
		if (pos == -1)
			return (free(array), 0);
		current -> content -> sorted_pos = pos;
		current = current -> next;
	}
	free (array);
	return (1);
}
