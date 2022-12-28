/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:19 by fleduc            #+#    #+#             */
/*   Updated: 2022/12/16 13:23:36 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printer(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->all->lock_print.mutex));
	philo->start_current_action = gettime();
	if (!(check_death(philo->all)) || !ft_strcmp(action, DIE))
		printf("%u %i %s\n", philo->start_current_action - philo->all->start,
			philo->nbr, action);
	pthread_mutex_unlock(&(philo->all->lock_print.mutex));
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left->mutex));
	printer(philo, FORK);
	pthread_mutex_lock(&(philo->right->mutex));
	printer(philo, FORK);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->right->mutex));
	pthread_mutex_unlock(&(philo->left->mutex));
}

void	do_eat(t_philo *philo)
{
	bool	sated;

	if (philo->all->time_eat == 0)
		return ;
	take_forks(philo);
	printer(philo, EAT);
	set_status(philo, EATING);
	set_last_eat(philo, philo->start_current_action);
	sated = (++philo->eats == philo->all->max_eat);
	usleep_eat(philo);
	leave_forks(philo);
	if (sated && philo->all->max_eat != -1)
		increment_sated(philo->all);
}

void	do_sleep(t_philo *philo)
{
	printer(philo, SLEEP);
	set_status(philo, OTHER);
	usleep_check(philo, philo->all->time_sleep);
}
