/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:23:01 by fleduc            #+#    #+#             */
/*   Updated: 2023/01/04 12:28:03 by fleduc           ###   ########.fr       */
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
		usleep (500);
	}
}

void	usleep_eat(t_philo *philo)
{
	t_ms	stop;

	stop = philo->start_current_action + philo->all->time_eat;
	while ((gettime() < stop))
		usleep (500);
}
