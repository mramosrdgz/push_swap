/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:41:23 by mariramo          #+#    #+#             */
/*   Updated: 2025/08/02 11:07:56 by mariramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static const char	*parse_number(const char *str, int sign, int *result)
{
	long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (NULL);
		str++;
	}
	*result = (int)(num * sign);
	return (str);
}

int	atoi_safe(const char *str, int *result)
{
	int		sign;

	sign = 1;
	*result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	str = parse_number(str, sign, result);
	if (!str || *str != '\0')
		return (0);
	return (1);
}

int	has_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*checker;

	current = stack;
	while (current)
	{
		checker = current -> next;
		while (checker)
		{
			if (checker -> content -> value == current -> content -> value)
				return (1);
			checker = checker -> next;
		}
		current = current -> next;
	}
	return (0);
}

t_list	*load_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*new_node;
	int		i;
	int		value;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (free_stack(&stack), NULL);
		if (!atoi_safe(argv[i], &value))
			return (free_stack(&stack), NULL);
		new_node = create_node(value);
		if (!new_node)
			return (free_stack(&stack), NULL);
		add_node_back (&stack, new_node);
		i++;
	}
	if (has_duplicates(stack))
		return (free_stack(&stack), NULL);
	return (stack);
}
