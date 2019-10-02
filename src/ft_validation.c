/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:26:48 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 21:44:19 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static unsigned char	ft_all_int(int ac, char **av)
{
	int					pos;

	pos = 1;
	while (pos < ac)
	{
		if (!ft_strequ(av[pos], ft_itoa(ft_atoi(av[pos]))))
			return (0);
		pos++;
	}
	return (1);
}

static unsigned char	ft_no_duplicates(int ac, char **av)
{
	int					i;
	int					j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned char			ft_input_validation(int ac, char **av)
{
	return (ft_all_int(ac, av) && ft_no_duplicates(ac, av));
}
