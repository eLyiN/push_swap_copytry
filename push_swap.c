/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:37:57 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/01 12:48:47 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

int	main(int argc, char *argv[])
{
	t_program prg;

	if (--argc < 1 || (!ft_strcmp(argv[1], "-v") && argc == 1))
		return (0);
	prg.debug = 0;
	if (!ft_strcmp(argv[1], "-v"))
	{
		prg.debug = 1;
		if (init_stacks(--argc, &argv[2], &prg.stack_a, &prg.stack_b))
			return (1);
	}
}