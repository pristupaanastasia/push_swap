/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:26:24 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 17:17:45 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*static void				ft_print_stack(t_stack *stack)
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
*/
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

static void				ft_make_command(t_push_swap *ps, char *line)
{
	if (ft_strequ(line, "sa"))
		ft_sa(ps);
	else if (ft_strequ(line, "sb"))
		ft_sb(ps);
	else if (ft_strequ(line, "ss"))
		ft_ss(ps);
	else if (ft_strequ(line, "pa"))
		ft_pa(ps);
	else if (ft_strequ(line, "pb"))
		ft_pb(ps);
	else if (ft_strequ(line, "ra"))
		ft_ra(ps);
	else if (ft_strequ(line, "rb"))
		ft_rb(ps);
	else if (ft_strequ(line, "rr"))
		ft_rr(ps);
	else if (ft_strequ(line, "rra"))
		ft_rra(ps);
	else if (ft_strequ(line, "rrb"))
		ft_rrb(ps);
	else if (ft_strequ(line, "rrr"))
		ft_rrr(ps);
	else
		ft_error();
}

/*int						main(int ac, char **av)
{
	t_push_swap			ps;
	char				*line;
	char				**input;
	int					ret;
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
	ft_printf("STACK A: %p\n", ps.a);
	ps.a = ft_init_stack_a(ac, av);
	ft_printf("[STACK A]\n");
	ft_print_stack(ps.a);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			ft_error();
		ft_printf("\e[33mPerforming command %s...\e[0m\n", line);
		ft_make_command(&ps, line);
		ft_printf("\e[32m%s command done!\e[0m\n", line);
		ft_printf("[STACK A]\n");
		ft_print_stack(ps.a);
		ft_printf("[STACK B]\n");
		ft_print_stack(ps.b);
		ps.is_sorted = ft_is_sorted(&ps);
		(ps.is_sorted == 1) ? ft_printf("\e[32mOK\e[0m\n") : ft_printf("\e[33mKO\e[0m\n");
	}
	return (0);
}
*/