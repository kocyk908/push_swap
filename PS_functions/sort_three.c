/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:31:53 by lkoc              #+#    #+#             */
/*   Updated: 2024/06/03 16:34:49 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*max;
	
	max = find_max(*stack);
	if (max == *stack)
		ra(stack, false);
	else if ((*stack)->next == max)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}