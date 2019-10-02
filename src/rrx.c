/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:44:05 by samymone          #+#    #+#             */
/*   Updated: 2019/09/22 19:44:08 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void		ft_rrx(t_stack *stack)
{
	if (!stack || !stack->head)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void			ft_rra(t_push_swap *ps)
{
	ft_rrx(ps->a);
}

void			ft_rrb(t_push_swap *ps)
{
	ft_rrx(ps->b);
}

void			ft_rrr(t_push_swap *ps)
{
	ft_rrx(ps->a);
	ft_rrx(ps->b);
}
