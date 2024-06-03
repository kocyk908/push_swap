/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:27:53 by lkoc              #+#    #+#             */
/*   Updated: 2024/06/03 15:34:13 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

typedef	struct	s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node *next;
	struct	s_stack_node *prev;
	struct	s_stack_node *curr;
}	t_stack_node;

//Errors

//Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

#endif