/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:08 by samymone          #+#    #+#             */
/*   Updated: 2019/10/03 18:14:13 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include <stdio.h>

int				mid_sorting(t_stack *stack)
{
	t_elem		*elem;

	elem = stack->head;
	while (elem != stack->tail)
	{
		if (elem->num > elem->next->num)
			return (0);
		else
			elem = elem->next;
	}
	return (1);
}

void			min_num_of_operations(t_stack *stack, t_push_swap *ps)
{
	if (stack->size == 3)
	{
		while (mid_sorting(stack) != 1)
		{
			if (stack->head->num > stack->head->next->num &&
				stack->head->num > stack->tail->num)
			{
				ft_ra(ps);
				ft_putendl_fd("ra", 1);
			}
			if (stack->head->num > stack->head->next->num)
			{
				ft_sa(ps);
				ft_putendl_fd("sa", 1);
			}
			if (stack->tail->num < stack->tail->prev->num)
			{
				ft_rra(ps);
				ft_putendl_fd("rra", 1);
			}
		}
	}
}

int				min_mid_a(t_push_swap *ps, int min, int curr_mid)
{
	t_elem		*s;

	s = ps->a->head;
	while (s->next != ps->a->head)
	{
		if (s->num >= min && s->num <= curr_mid)
			return (1);
		s = s->next;
	}
	if (s->num >= min && s->num <= curr_mid)
		return (1);
	return (0);
}

void			small_stack(t_stack *stack, t_push_swap *ps)
{
	if (stack->size == 2)
	{
		if (mid_sorting(stack) == 0)
		{
			ft_sa(ps);
			ft_putendl_fd("sa", 1);
		}
	}
	else
		min_num_of_operations(stack, ps);
}

void			prep_sort(t_push_swap *ps)
{
	if (ps->a->size == 2)
	{
		if (mid_sorting(ps->a) == 0)
		{
			ft_sa(ps);
			ft_putendl_fd("sa", 1);
		}
		return ;
	}
	if (ps->a->size == 3)
	{
		min_num_of_operations(ps->a, ps);
		return ;
	}
	else
	{
		while (!ft_is_sorted(ps))
		{
			quick_sort_a(ps);
			if (ps->b && ps->b->head != NULL && !ft_is_sorted(ps))
				quick_sort_b(ps);
		}
	}
}
