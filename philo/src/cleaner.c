/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:26 by fleduc            #+#    #+#             */
/*   Updated: 2023/01/04 12:13:34 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroyer(t_mutex *mutex)
{
	if (mutex->init)
		pthread_mutex_destroy(&(mutex->mutex));
}

void	kill_mutexes(t_all *all)
{
	int		i;

	if (all->forks != NULL)
	{
		i = -1;
		while (++i < all->nb_philo)
			destroyer(all->forks + i);
	}
	if (all->philos != NULL)
	{
		i = -1;
		while (++i < all->nb_philo)
		{
			destroyer(&(all->philos[i].lock_eat));
			destroyer(&(all->philos[i].lock_status));
		}
	}
	destroyer(&(all->lock_death));
	destroyer(&(all->lock_sated));
	destroyer(&(all->lock_print));
}

int	cleaner(t_all *all)
{
	if (all == NULL)
		return (1);
	kill_mutexes(all);
	if (all->threads != NULL)
		free(all->threads);
	if (all->forks != NULL)
		free(all->forks);
	if (all->philos != NULL)
		free(all->philos);
	free(all);
	return (0);
}
