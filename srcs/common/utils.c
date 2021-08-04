/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:52:33 by rgilles           #+#    #+#             */
/*   Updated: 2021/07/30 15:52:35 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

void	do_nothing(void *ptr)
{
	(void)ptr;
}

void	sanitize_input(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
	{
		ft_error("Stack A has to be provided as args, as a list of integers\n");
		exit(0);
	}
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(ft_isdigit(argv[i][j])
				|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
			{
				ft_error("Arguments should be a list of integers only\n");
				exit(-1);
			}
		}
	}
}

t_list	*put_on_list(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (++i < argc)
		ft_lstadd_back(&stack, ft_lstnew(argv[i]));
	return (stack);
}