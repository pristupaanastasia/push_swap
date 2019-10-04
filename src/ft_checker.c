/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:09:56 by samymone          #+#    #+#             */
/*   Updated: 2019/10/04 18:04:57 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void				ft_clean_av(int ac, char **av)
{
	int		i;

	i = 1;
	if (av)
	{
		while (i < ac && av[i])
		{
			ft_strdel(&av[i]);
			i++;
		}
		free(av);
	}
}

static void				ft_clean_input(int n, char **input)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_strdel(&input[i]);
		i++;
	}
	free(input);
}

static t_stack		*ft_init_stack(int ac, char **av)
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
	if (ac == 2)
		ft_clean_av(ac, av);
	return (stack);
}

void		ft_make_command(t_push_swap *ps, char *line)
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

void		reading_commands(t_push_swap *ps)
{
	int			ret;
	char		*line;

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		if (ret == 1)
		{
			ft_make_command(ps, line);
			ft_strdel(&line);
		}
		if (ret == 0)
		{
			ps->is_sorted = ft_is_sorted(ps);
			(ps->is_sorted == 1) ? ft_putendl_fd("OK", 1) :
			ft_putendl_fd("KO", 1);
		}
		if (ret == -1)
			ft_error();
	}
}

int			main(int ac, char **av)
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
		if (i++ == 0)
			return (0);
		av = (char**)malloc(sizeof(char*) * i);
		j = 0;
		while (j++ < i - 1)
			av[j] = ft_strdup(input[j - 1]);
		ac = i;
		ft_clean_input(j, input);
	}
	ft_bzero(&ps, sizeof(t_push_swap));
	ps.a = ft_init_stack(ac, av);
	reading_commands(&ps);
}
