/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:13:14 by samymone          #+#    #+#             */
/*   Updated: 2019/10/03 18:13:16 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int			min_elem_sort(t_push_swap *ps, int curr_min)
{
	t_elem		*tmp;
	int			new_min;

	new_min = max_elem(ps->a);
	tmp = ps->a->head;
	while (tmp->next != ps->a->head)
	{
		if (tmp->num >= curr_min && tmp->num < new_min)
			new_min = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num >= curr_min && tmp->num < new_min)
		new_min = tmp->num;
	return (new_min);
}

int			max_elem(t_stack *stack)
{
	t_elem	*tmp;
	int		max;
	int		i;

	tmp = stack->head;
	max = stack->head->num;
	i = stack->size;
	while (i-- > 0)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int			min_elem(t_stack *stack)
{
	t_elem	*tmp;
	int		min;
	int		i;

	tmp = stack->head;
	min = stack->head->num;
	i = stack->size;
	while (i-- > 0)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

void		rotate_b(int st, int fh, t_push_swap *ps, int max)
{
	if (st <= fh)
		while (max != ps->b->head->num)
			ft_rb(ps);
	else if (fh < st)
		while (max != ps->b->head->num)
			ft_rrb(ps);
}

int			max_on_the_top_b(t_push_swap *ps)
{
	int		max;
	int		st;
	int		fh;
	t_elem	*tmp;

	max = max_elem(ps->b);
	st = 0;
	fh = 0;
	tmp = ps->b->head;
	while (tmp->num != max)
	{
		st++;
		tmp = tmp->next;
	}
	tmp = ps->b->tail;
	while (tmp->num != max)
	{
		fh++;
		tmp = tmp->prev;
	}
	rotate_b(st, fh, ps, max);
	return (ps->b->size > 0 ? 0 : 1);
}
