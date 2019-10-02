/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:53:51 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 21:49:12 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void				ft_print_stack(t_stack *stack)
{
	t_elem				*elem;

	if (!stack || !stack->head || !(elem = stack->head))
	{
		printf("\tNULL\n");
		return ;
	}
	if (stack->size == 1)
	{
		printf("HEAD & TAIL  [%3d <- {%3d} -> %3d]\n",
				  elem->prev->num, elem->num, elem->next->num);
		return ;
	}
	while (elem != stack->tail)
	{
		if (elem == stack->head)
			printf("\tHEAD");
		else
			printf("\t    ");
		printf(" [%3d <- {%3d} -> %3d]\n",
				  elem->prev->num, elem->num, elem->next->num);
		elem = elem->next;
	}
	printf("\tTAIL [%3d <- {%3d} -> %3d]\n",
			  elem->prev->num, elem->num, elem->next->num);
}

static t_stack			*ft_init_stack_a(int ac, char **av)
{
	t_elem				*elem;
	t_stack				*stack;
	int					arg_pos;

	if (!(ft_input_validation(ac, av)))
		ft_error();
	stack = NULL;
	arg_pos = 1;
	while (arg_pos < ac)
	{
		if (!(elem = ft_newelem(ft_atoi(av[arg_pos]))))
			ft_error();
		ft_addstack(elem, &stack);
		arg_pos++;
	}
	return (stack);
}

int						main(int ac, char **av)
{
	t_push_swap			ps;
	char				**input;
	int 				i;
	int					j;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		i = 0;
		input = ft_strsplit(av[1], ' ');
		while (input[i])
			i++;
		i++;
		av = (char**)malloc(sizeof(char*) * i);
		j = 1;
		while (j < i)
		{
			av[j] = input[j - 1];
			j++;
		}
		ac = i;
	}
	ft_bzero(&ps, sizeof(t_push_swap));
	ps.a = ft_init_stack_a(ac, av);
	ps.sort_nub = 0;
	if (!ps.is_sorted)
		prep_sort(&ps);
}
