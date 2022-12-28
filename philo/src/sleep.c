/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:23:01 by fleduc            #+#    #+#             */
/*   Updated: 2022/12/16 13:25:21 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	usleep_check(t_philo *philo, t_ms time)
{
	t_ms	stop;

	stop = philo->start_current_action + time;
	while ((gettime() < stop))
	{
		if (check_death(philo->all))
			break ;
		usleep (200);
	}
}

void	usleep_eat(t_philo *philo)
{
	t_ms	stop;

	stop = philo->start_current_action + philo->all->time_eat;
	while ((gettime() < stop))
		usleep (200);
}
