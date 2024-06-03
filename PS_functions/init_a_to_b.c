/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:32 by lkoc              #+#    #+#             */
/*   Updated: 2024/06/03 17:11:22 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = list_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b_node;
	t_stack_node	*target_node;
	long			best_match_index;
	
	while (a)
	{
		best_match_index = LONG_MIN;
		curr_b_node = b;
		while (curr_b_node)
		{
			if (curr_b_node->nbr < a->nbr
				&& curr_b_node->nbr > best_match_index)
			{
				best_match_index = curr_b_node->nbr;
				target_node = curr_b_node;
			}
			curr_b_node = curr_b_node->next;
		}
		if (best_match_index == LONG_MIN)
			a->curr = find_max(b);
		else
			a->curr = target_node;
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}