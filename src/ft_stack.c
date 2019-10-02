/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:25:46 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 21:44:21 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_elem					*ft_newelem(int num)
{
	t_elem				*elem;

	if (!(elem = ft_memalloc(sizeof(t_elem))))
		return (NULL);
	elem->next = elem;
	elem->prev = elem;
	elem->num = num;
	return (elem);
}

t_stack					*ft_newstack(void)
{
	t_stack				*stack;

	if (!(stack = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
//	printf("size of stzck %zu\n", stack->size);
	return (stack);
}

void					ft_cleanelem(t_elem **elem)
{
	if (!elem)
		return ;
	(*elem)->num = 0;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	free(*elem);
	*elem = NULL;
}

void					ft_cleanstack(t_stack **stack)
{
	t_elem				*cur;
	t_elem				*next;

	cur = (*stack)->head;
	next = cur->next;
	while (cur)
	{
		ft_cleanelem(&cur);
		cur = next;
		next = cur->next;
	}
	(*stack)->size = 0;
	free(*stack);
	*stack = NULL;
}

void					ft_addstack(t_elem *elem, t_stack **stack)
{
	if (!elem || !stack)
		ft_error();
	if (!(*stack))
		if (!(*stack = ft_newstack()))
			ft_error();
		
	if (!(*stack)->size)
	{
		(*stack)->head = elem;
		(*stack)->tail = elem;
		(*stack)->size = 1;
		(*stack)->head->next = (*stack)->tail;
		(*stack)->head->prev = (*stack)->tail;
		(*stack)->tail->next = (*stack)->head;
		(*stack)->tail->prev = (*stack)->head;
	}
	else
	{
		elem->prev = (*stack)->tail;
		elem->next = (*stack)->head;
		(*stack)->head->prev = elem;
		(*stack)->tail->next = elem;
		(*stack)->tail = elem;
		(*stack)->size += 1;
	}
}
