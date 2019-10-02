/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:35:01 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 20:50:32 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

unsigned char		ft_is_sorted(t_push_swap *ps)
{
	t_elem	*elem;	

	if (ps->b != NULL && ps->b->head != NULL)
		return (0);
	if (ps->a->head != NULL)
	{
		elem = ps->a->head;
		while (elem->next != ps->a->head)
		{
			if (elem->num > elem->next->num)
				return (0);
			else
				elem = elem->next;
		}
		return (1);
	}
	return(1);
}
