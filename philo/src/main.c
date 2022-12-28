/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:43 by fleduc            #+#    #+#             */
/*   Updated: 2022/12/13 21:11:12 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	help_message(void)
{
	printf("%s\n", USAGE);
	return (1);
}

int	validate(int count, char *arg[])
{
	int	i;
	int	j;

	if (count == 4 || count == 5)
	{
		i = 0;
		while (arg[++i])
		{
			j = -1;
			while (arg[i][++j])
				if (!(arg[i][j] >= '0' || arg[i][j] <= '9'))
					return (0);
			if (ft_strlen(arg[i]) > 10 || ft_atoi(arg[i]) <= 0)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (!validate(argc - 1, argv))
		return (help_message());
	all = init(argc, argv);
	if (all->init_err)
		return (cleaner(all));
	init_threads(all);
	return (cleaner(all));
}
