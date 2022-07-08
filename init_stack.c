/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:33:50 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/08 10:43:57 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** copy a str until stop character or end of string str
*/

char	*ft_strdupchar(char *str, char stop)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	if (!(new_str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (str[i++] && str[i] != stop)
		new_str[i] = str[i];
	str[i] = '\0';
	return (str);
}

/*
** fill_array from 1 arg
*/

int	fill_stack_arg(char *arg, t_stack *stack, size_t *stack_nb)
{
	int		num;
	char	*str;

	while (*arg)
	{
		while (*arg && arg == ' ')
			arg++;
		if (!arg)
			break ;
		str = ft_strdupchar(arg, ' ');
		if (ft_atoi(str, &num))
		{
			free(str);
			return (1);
		}
		free(str);
		if (stack_contains(stack, num))
			return (1);
		stack->array[(*stack_nb)++] = num;
		stack->size++;
		while (*arg && *arg != ' ')
			*arg++;
	}
}

/*
** fill_array
*/

int	fill_stack(int argc, char **argv, t_stack *stack)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	while (i < (size_t)argc)
	{
		ptr = argv[i];
		if (fill_stack_arg(ptr, stack, &j))
			return (1);
		i++;
	}
	return (0);
}

/*
** count how many number/words there is in all arguments
*/

size_t	count_stack_size(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!j || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

/*
** Allocate arrays of stacks and initiate stack_a with args
*/

int	init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	size_t stack_size;

	stack_size = count_stack_size(argc, argv);
	stack_a->array = malloc(sizeof(int) * stack_size);
	if (!stack_a->array)
		return (write(STDERR_FILENO, "Error\n", 6));
}