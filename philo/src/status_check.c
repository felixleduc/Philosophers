/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:23:10 by fleduc            #+#    #+#             */
/*   Updated: 2023/01/04 12:26:59 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_died(t_all *all, t_philo *philo)
{
	t_ms	last_ate;

	if (check_status(philo) == EATING)
		return (false);
	last_ate = last_eat(philo);
	if (gettime() - last_ate > all->time_die)
	{
		set_death(all);
		printer(philo, DIE);
		return (true);
	}
	return (false);
}

bool	check_alone(t_all *all)
{
	if (all->nb_philo > 1)
		return (false);
	set_death(all);
	printf("%u 1 %s\n", gettime() - all->start, FORK);
	while (gettime() - all->start < all->time_die)
		usleep(500);
	printf("%u 1 %s\n", gettime() - all->start, DIE);
	return (true);
}

void	status_check(t_all *all, int threads_created)
{
	int		i;

	if (threads_created != all->nb_philo)
		return ;
	if (check_alone(all))
		return ;
	while (1)
	{
		i = -1;
		while (++i < all->nb_philo)
		{
			if (check_died(all, all->philos + i))
				return ;
		}
		if (check_sated(all))
		{
			set_death(all);
			return ;
		}
	}
}
