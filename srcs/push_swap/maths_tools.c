/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:12:28 by rgilles           #+#    #+#             */
/*   Updated: 2021/08/04 12:12:29 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_move(int move, t_list **sa, t_list **sb, t_list **moves)
{
	t_ops	ops[11];

	ops[SA] = &do_sa;
	ops[SB] = &do_sb;
	ops[SS] = &do_ss;
	ops[PA] = &do_pa;
	ops[PB] = &do_pb;
	ops[RA] = &do_ra;
	ops[RB] = &do_rb;
	ops[RR] = &do_rr;
	ops[RRA] = &do_rra;
	ops[RRB] = &do_rrb;
	ops[RRR] = &do_rrr;
	ops[move](sa, sb);
	ft_lstadd_back(moves, ft_lstnew(ft_itoa(move)));
}

void	roll_stack(t_list **stack, int to_insert, t_list **moves)
{
	int	i;

	i = -1;
	while (++i && ft_atoi((*stack)->content) <= to_insert)
		;
	if (i <= ft_lstsize(*stack) / 2)
		while (i-- > 0)
			add_move(RA, stack, NULL, moves);
	else
		while (i-- > 0)
			add_move(RRA, stack, NULL, moves);
}

int		get_value(t_list *stack, int pos)
{
	int	i;

	i = -1;
	if (ft_lstsize(stack) >= pos)
	{
		while (++i < pos)
			stack = stack->next;
		return (ft_atoi(stack->content));
	}
	ft_error("Stack index out of bounds !\n");
	exit(-1);
}
