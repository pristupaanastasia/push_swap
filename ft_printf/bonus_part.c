/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 18:59:31 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/24 14:16:58 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					proverka(char *posle, char *zeloe)
{
	if (posle[0] >= '5' || posle[1] == '.')
	{
		if (zeloe[ft_strlen(zeloe) - 1] == '2'
			|| zeloe[ft_strlen(zeloe) - 1] == '4'
			|| zeloe[ft_strlen(zeloe) - 1] == '6'
			|| zeloe[ft_strlen(zeloe) - 1] == '8')
			return (1);
	}
	return (0);
}

void				ft_free(t_point p)
{
	free(p.mantissa);
	free(p.g);
	free(p.s);
	free(p.exp);
	free(p.zifra);
	free(p.toc);
}
