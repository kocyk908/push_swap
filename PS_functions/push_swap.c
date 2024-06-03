/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:02 by lkoc              #+#    #+#             */
/*   Updated: 2024/06/03 16:40:42 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (av == 2)
		av = split(av[1], ' ');
	init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (list_size(a) == 2)
			sa(&a, false);
		else if (list_size(a) == 3)
			sort_three(&a);
		else
			sort_more(&a, &b);
	}
}
