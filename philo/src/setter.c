/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:48 by fleduc            #+#    #+#             */
/*   Updated: 2023/01/04 12:14:02 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_death(t_all *all)
{
	pthread_mutex_lock(&(all->lock_death.mutex));
	all->death = true;
	pthread_mutex_unlock(&(all->lock_death.mutex));
}

void	increment_sated(t_all *all)
{
	pthread_mutex_lock(&(all->lock_sated.mutex));
	all->nb_sated++;
	pthread_mutex_unlock(&(all->lock_sated.mutex));
}

void	set_status(t_philo *philo, bool status)
{
	pthread_mutex_lock(&(philo->lock_status.mutex));
	philo->status = status;
	pthread_mutex_unlock(&(philo->lock_status.mutex));
}

void	set_last_eat(t_philo *philo, t_ms time)
{
	pthread_mutex_lock(&(philo->lock_eat.mutex));
	philo->last_eat = time;
	pthread_mutex_unlock(&(philo->lock_eat.mutex));
}
