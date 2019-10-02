/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:12:06 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 21:34:36 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int			mid_sorting(t_stack *stack)
{
	t_elem	*elem;

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

void            min_num_of_operations(t_push_swap *ps)
{
	if (ps->a->size == 3)
	{
		while (mid_sorting(ps->a) != 1)
		{
			if (ps->a->head->num > ps->a->head->next->num &&
				ps->a->head->num > ps->a->tail->num)
			{
				ft_ra(ps);
				printf("ra\n");
				ps->num_operations++;
			}
			if (ps->a->head->num > ps->a->head->next->num)
			{
				ft_sa(ps);
				printf("sa\n");
				ps->num_operations++;
			}
			if (ps->a->tail->num < ps->a->tail->prev->num)
			{
				ft_rra(ps);
				printf("rra\n");
				ps->num_operations++;
			}
		}
	}
}

int min_del_a(t_push_swap *ps,int min, int del)
{
	t_elem *s;

	s = ps->a->head;
	while(s->next != ps->a->head)
	{
		if (s->num >= min && s->num <= del)
			return(1);
		s = s->next;
	}
	if (s->num >= min && s->num <= del)
			return(1);
	return(0);
}

int min_elem_sort(t_push_swap *ps,int min)
{
	t_elem *s;
	int min_elem;

	min_elem = max_elem(ps->a);
	s = ps->a->head;
	while(s->next != ps->a->head)
	{
		if (s->num >= min && s->num < min_elem)
			min_elem = s->num;
		s = s->next;
	}
	if (s->num >= min && s->num < min_elem)
			min_elem = s->num;
	return(min_elem);
}

void        quick_sort_a(t_push_swap *ps)
{
	int		max;
	int		min;
	int		mid;
	int		i;
	int		size;

	max = max_elem(ps->a);
	min = (ps->sort  == 0) ? min_elem(ps->a) : min_elem_sort(ps,ps->next);
	mid = (max - min) / 2 + min;
	mid = (max - mid < 3 || ps->a->size - ps->sort_nub < 3 ) ? max : mid;
	mid = (mid == ps->mid) ? mid + 2 : mid;
	if (ps->a->size < 4)
	{
		if (ps->a->size == 2)
		{
			if (mid_sorting(ps->a) == 0)
			{
				ft_sa(ps);
				printf("sa\n");
			}
		}
		else
			min_num_of_operations(ps);
	}
	else
	{
		i = 0;
		size = ps->a->size;
		while(i <  size && ps->a->head && ps->a->head->num >= min && min_del_a(ps,min,mid) == 1)
		{
			while (ps->a->head && ps->a->head->num <= mid && ps->a->head->num >= min)
			{
				ft_pb(ps);
				printf("pb\n");
				i++;
			}
			if (ps->a->head && ps->a->head->num >= min && min_del_a(ps,min,mid) == 1)
			{
				ft_ra(ps);
				printf("ra\n");
			}
			i++;
		}
	}
	i=0;
	while (ps->a && ps->a->tail && ps->a->tail->num >= min && ps->sort == 1 && !ft_is_sorted(ps))
	{
		ft_rra(ps);
		printf("rra\n");
	}
	ps->mid = mid;
	ps->sort = 1;
}

void        quick_sort_b(t_push_swap *ps)
{
	int     max;
	int     min;
	int     mid;
	int     i;

	max = max_elem(ps->b);
	min = min_elem(ps->b);
	mid = (max - min) / 2 + min;
	if (ps->b->size < 4)
	{
		if (ps->b->size == 2)
		{
			if (mid_sorting(ps->a) == 0)
			{
				ft_sb(ps);
				printf("sb\n");
			}
		}
		else
			min_num_of_operations(ps);
	}
	i = ps->b->size;
	while(ps->b->head && i-- > 0)
	{
		while (ps->b->head && ps->b->head->num > mid)
		{
			ft_pa(ps);
			printf("pa\n");
			i--;
		}
		ft_rb(ps);
		printf("rb\n");
	}
	i = 0;
	while (ps->b->head != NULL && max_on_the_top_b(ps) !=1)
	{
		ps->sort_nub = ps->sort_nub + 1;
		ft_pa(ps);
		printf("pa\n");
		i++;
	}
	while (i>0)
	{
		ft_ra(ps);
		printf("ra\n");
		i--;
	}
	ps->next = ps->a->tail->num + 1;
}

void            prep_sort(t_push_swap *ps)
{
	if (ps->a->size == 2)
	{
		if (mid_sorting(ps->a) == 0)
		{
			ft_sa(ps);
			printf("sa\n");
			ps->num_operations++;
		}
		return ;
	}
	if (ps->a->size == 3)
	{
		min_num_of_operations(ps);
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
