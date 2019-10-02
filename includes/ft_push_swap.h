/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:10:51 by samymone          #+#    #+#             */
/*   Updated: 2019/10/02 21:45:35 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

# define WHILE while (ps->a->head->num == mid->num || ps->a->head->num == min->num \
			|| ps->a->head->num == max->num)

/*
**	------------------------------------------------------------------------  **
**		INCLUDES     -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

/*
**	------------------------------------------------------------------------  **
**		TYPES        -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

typedef struct			s_elem
{
	int					num;
	struct s_elem		*next;
	struct s_elem		*prev;
}						t_elem;

typedef struct			s_stack
{
	struct s_elem		*head;
	struct s_elem		*tail;
	size_t				size;
}						t_stack;

typedef struct			s_push_swap
{
	struct s_stack		*a;
	struct s_stack		*b;
	unsigned char		is_sorted;
	size_t				num_operations;
	int                 next;
	int                 mid;
	int                 sort;
	int					sort_nub;
}						t_push_swap;

/*
**	------------------------------------------------------------------------  **
**		FUNCTIONS    -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

/*
**	----------------------------------------------------  **
**		MISC         -----------------------------------  **
**	----------------------------------------------------  **
*/

/*
**	Prints "Error\n" on STDOUT and exits with EXIT_FAILURE exitcode 
*/

void					ft_error(void);

/*
**	----------------------------------------------------  **
**		VALIDATION   -----------------------------------  **
**	----------------------------------------------------  **
*/

/*
**	Returns 1 if all args are int and there are no duplicates in input;
**	Returns 0 if there are duplicates or any non-int symbols
*/

unsigned char			ft_input_validation(int ac, char **av);

/*
**	----------------------------------------------------  **
**		STACKS       -----------------------------------  **
**	----------------------------------------------------  **
*/

/*
**	Creates new element with desired (num),
**	sets it's next and prev pointers to itself;
**	Returns pointer to newly created elem or NULL if error occured
*/

t_elem					*ft_newelem(int num);

/*
**	Creates new stack with 0 size,
**	sets it's head and prev pointers to NULL;
**	Returns ponter to newly created stack or NULL if error occured
*/

t_stack					*ft_newstack(void);

/*
**	Frees elem;
**	sets num and pointers of elem to 0 (NULL for pointers)
*/

void					ft_cleanelem(t_elem **elem);

/*
**	Frees all elements of the stack;
**	frees stack itself;
**	sets size and pounters to 0 (NULL for pointers)
*/

void					ft_cleanstack(t_stack **stack);

/*
**	Adds element (elem) to the end to the (stack);
**	if there is no stack - creates it;
**	Reassigns head and tail pointers of (stack);
**	Reassigns next and prev pounters of (elem)
*/

void					ft_addstack(t_elem *elem, t_stack **stack);
void				ft_print_stack(t_stack *stack);
/*
**	----------------------------------------------------  **
**		RULES        -----------------------------------  **
**	----------------------------------------------------  **
*/

/*
**	swap a - swap the first 2 elements at the top of stack a;
**	does nothing if there is only one or no elements
*/

void					ft_sa(t_push_swap *ps);

/*
**	swap b - swap the first 2 elements at the top of stack b;
**	does nothing if there is only one or no elements
*/

void					ft_sb(t_push_swap *ps);

/*
**	sa and sb at the same time
*/

void					ft_ss(t_push_swap *ps);

/*
**	push a - take the first element at the top of b and put it at the top of a;
**	does nothing if b is empty
*/

void					ft_pa(t_push_swap *ps);

/*
**	push b - take the first element at the top of a and put it at the top of b;
**	does nothing if a is empty
*/

void					ft_pb(t_push_swap *ps);

/*
**	rotate a - shift up all elements of stack a by 1;
**	the first element becomes the last one
*/

void					ft_ra(t_push_swap *ps);

/*
**	rotate b - shift up all elements of stack b by 1;
**	the first element becomes the last one
*/

void					ft_rb(t_push_swap *ps);

/*
**	ra and rb at the same time
*/

void					ft_rr(t_push_swap *ps);

/*
**	reverse rotate a - shift down all elements of stack a by 1;
**	the last element becomes the first one
*/

void					ft_rra(t_push_swap *ps);

/*
**	reverse rotate b - shift down all elements of stack b by 1;
**	the last element becomes the first one
*/

void					ft_rrb(t_push_swap *ps);

/*
**	rra and rrb at the same time
*/

void					ft_rrr(t_push_swap *ps);

/*
**	is_sorted shows whether stack_a is sorted at the same time as stack_b
**	is empty
*/

unsigned char			ft_is_sorted(t_push_swap *ps);

/*
**	in case of an error output corresponding message
*/
void					ft_error(void);

/*
**	preparations for Merge sorting algorythm
*/

void					prep_sort(t_push_swap *ps);

/*
**	returns 1 in case of sorted stack, in other cases returns 0
*/

int						mid_sorting(t_stack *stack);

/*
**	divides initial stack into two different ones before application of sorting algorythm
*/
void				preparations(t_push_swap *ps);

void					sorting(t_push_swap *ps, t_elem *max, t_elem *min);

void	create_second_stack(t_push_swap *ps, t_elem *max, t_elem *min, t_elem *mid);

void		final_sorting(t_push_swap *ps, t_elem *max, t_elem *min);

void		next_step(t_push_swap *ps);
void            min_num_of_operations(t_push_swap *ps);
void        quick_sort_a(t_push_swap *ps);
int			max_on_the_top_b(t_push_swap *ps);
int			max_elem(t_stack *stack);
int			min_elem(t_stack *stack);
void        quick_sort_b(t_push_swap *ps);

/*
**	rotates stack b in the fastest way
*/
void		rotate_b(int st, int fh, t_push_swap *ps, int max);

#endif
