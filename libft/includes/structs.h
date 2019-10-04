/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:25 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/04 18:06:03 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "../../includes/ft_push_swap.h"

typedef struct			s_flags
{
	char				zero;
	char				space;
	char				grid;
	char				plus;
	char				minus;
}						t_flags;

typedef struct			s_format
{
	t_flags				flags;
	int					width;
	int					prec;
	int					type_flag;
	int					type;
	int					i;
}						t_format;

typedef struct			s_printf
{
	t_list				*buf;
	va_list				ap;
}						t_printf;

union					u_ld
{
	long double			ld_tmp;
	__int128_t			int_tmp;
};

typedef struct			s_ld
{
	union u_ld			ld;
	char				*str;
	int					exp;
	int					negative;
}						t_ld;

#endif
