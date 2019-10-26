/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:14:08 by samymone          #+#    #+#             */
/*   Updated: 2019/10/26 19:24:19 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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

void			min_num_of_operations(t_stack *stack, t_push_swap *ps, char ch)
{
	if (stack->size == 3)
	{
		while (mid_sorting(stack) != 1)
		{
			if (ch == 'a')
				three_rotation_for_a(stack, ps);
			else if (ch == 'b')
				three_rotation_for_b(stack, ps);
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

int min_a_iter(t_push_swap *ps)
{
	t_elem		*tmp;
	int			new_min;
	int			iter;
	int 		iter_min;

	iter = 0;
	new_min = max_elem(ps->a);
	tmp = ps->a->head;
	while (tmp->next != ps->a->head)
	{
		if (tmp->num < new_min)
		{
			new_min = tmp->num;
			iter_min = iter;
		}
		tmp = tmp->next;
		iter++;
	}
	return(iter_min);
}
int min_a(t_push_swap *ps)
{
	t_elem		*tmp;
	int			new_min;

	new_min = max_elem(ps->a);
	tmp = ps->a->head;
	while (tmp->next != ps->a->head)
	{
		if (tmp->num < new_min)
		{
			new_min = tmp->num;
		}
		tmp = tmp->next;
	}
	return(new_min);
}
		
void			kostil(t_push_swap *ps)
{
	while (ps->b == NULL || ps->b->size != 2)
		{
			if ((unsigned long)min_a_iter(ps) < ps->a->size / 2)
			{
				while (ps->a->head->num != min_a(ps))
				{
					ft_ra(ps);
					ft_putendl_fd("ra", 1);
				}
				ft_pb(ps);
				ft_putendl_fd("pb", 1);
			}
			else
			{
				while (ps->a->head->num != min_a(ps))
				{
					ft_rra(ps);
					ft_putendl_fd("rra", 1);
				}
				ft_pb(ps);
				ft_putendl_fd("pb", 1);
			}
		}
		kostil_n2(ps);
}
void kostil_n2(t_push_swap *ps)
{
	if (ps->b->head->num < ps->b->tail->num)
		{
			ft_sb(ps);
			ft_putendl_fd("sb", 1);
		}
		if (ps->a->head->num == max_elem(ps->a))
		{
			ft_ra(ps);
			ft_putendl_fd("ra", 1);
		}
		while (ps->a->tail->num != max_elem(ps->a))
		{
			ft_rra(ps);
			ft_putendl_fd("rra", 1);
		}
		if (ps->a->head->num != min_a(ps))
		{
			ft_sa(ps);
			ft_putendl_fd("sa", 1);
		}
		ft_pa(ps);
		ft_pa(ps);	
		ft_putendl_fd("pa\npa", 1);
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
		min_num_of_operations(ps->a, ps, 'a');
		return ;
	}
	if (ps->a->size == 5)
		kostil(ps);
	else
	{
		while (!ft_is_sorted(ps))
		{
			quick_sort_a(ps);
			if (ps->b && ps->b->head != NULL && !ft_is_sorted(ps))
				quick_sort_b(ps);
		}
		ps->is_sorted = 1;
	}
}
