/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:56 by fleduc            #+#    #+#             */
/*   Updated: 2023/01/04 12:26:49 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*run_philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->nbr % 2 == 0)
		usleep_check(philo, philo->all->time_eat);
	while ((check_death(philo->all) == false))
	{
		do_eat(philo);
		do_sleep(philo);
		if (check_death(philo->all) == false)
			printer(philo, THINK);
	}
	return (NULL);
}

void	join_threads(t_all *all, int nb_created)
{
	int	i;

	i = -1;
	while (++i < nb_created)
		pthread_join(all->threads[i], NULL);
}

void	init_threads(t_all *all)
{
	int	i;

	i = -1;
	all->start = gettime();
	while (++i < all->nb_philo)
	{
		all->philos[i].last_eat = all->start;
		all->philos[i].start_current_action = all->start;
		if (pthread_create(all->threads + i, NULL,
				run_philosophers, all->philos + i) != 0)
		{
			set_death(all);
			break ;
		}
	}
	status_check(all, i);
	join_threads(all, i);
}
