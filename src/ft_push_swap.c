/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:10:23 by samymone          #+#    #+#             */
/*   Updated: 2019/10/03 18:10:25 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
	int					i;
	int					j;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		i = 0;
		input = ft_strsplit(av[1], ' ');
		while (input[i])
			i++;
		if (i == 0)
			return (0);
		i++;
		av = (char**)malloc(sizeof(char*) * i);
		j = 1;
		while (j++ < i)
			av[j] = input[j - 1];
		ac = i;
	}
	ft_bzero(&ps, sizeof(t_push_swap));
	ps.a = ft_init_stack_a(ac, av);
	if (ps.is_sorted == 0)
	{
		prep_sort(&ps);
		//printf("y\n");
	}

}
