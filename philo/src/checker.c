/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:32 by fleduc            #+#    #+#             */
/*   Updated: 2022/12/14 22:24:10 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_death(t_all *all)
{
	bool	ret;

	pthread_mutex_lock(&(all->lock_death.mutex));
	ret = all->death;
	pthread_mutex_unlock(&(all->lock_death.mutex));
	return (ret);
}

bool	check_sated(t_all *all)
{
	bool	ret;

	pthread_mutex_lock(&(all->lock_sated.mutex));
	ret = (all->nb_sated == all->nb_philo);
	pthread_mutex_unlock(&(all->lock_sated.mutex));
	return (ret);
}

bool	check_status(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(&(philo->lock_status.mutex));
	ret = philo->status;
	pthread_mutex_unlock(&(philo->lock_status.mutex));
	return (ret);
}

t_ms	last_eat(t_philo *philo)
{
	t_ms	time;

	pthread_mutex_lock(&(philo->lock_eat.mutex));
	time = philo->last_eat;
	pthread_mutex_unlock(&(philo->lock_eat.mutex));
	return (time);
}
