/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:22:38 by fleduc            #+#    #+#             */
/*   Updated: 2023/01/04 12:13:55 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	init_mutex(t_mutex *fork, t_all *all)
{
	if (pthread_mutex_init(&(fork->mutex), NULL))
	{
		all->init_err = 1;
		printf("mutex init error");
		fork->init = false;
		return (false);
	}
	fork->init = true;
	return (true);
}

void	init_mutexes_all_struct(t_all *all)
{
	int	i;
	int	nb_forks;

	i = -1;
	nb_forks = all->nb_philo;
	while (++i < nb_forks)
		init_mutex(all->forks + i, all);
	init_mutex(&(all->lock_print), all);
	init_mutex(&(all->lock_death), all);
	init_mutex(&(all->lock_sated), all);
}

void	init_philos(t_all *all)
{
	int	i;
	int	nb_philo;

	i = -1;
	nb_philo = all->nb_philo;
	while (++i < nb_philo)
	{
		all->philos[i].nbr = i + 1;
		all->philos[i].eats = 0;
		all->philos[i].status = EATING;
		all->philos[i].left = all->forks + i;
		all->philos[i].right = all->forks + ((i + 1) % all->nb_philo);
		init_mutex(&(all->philos[i].lock_eat), all);
		init_mutex(&(all->philos[i].lock_status), all);
		all->philos[i].all = all;
	}
}

void	fill_params(int argc, char **argv, t_all *all)
{
	all->nb_philo = ft_atoi(argv[1]);
	all->time_die = ft_atoi(argv[2]);
	all->time_eat = ft_atoi(argv[3]);
	all->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->max_eat = ft_atoi(argv[5]);
	else
		all->max_eat = -1;
}

t_all	*init(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *) malloc(sizeof(t_all));
	if (all == NULL)
		return (NULL);
	all->init_err = 0;
	fill_params(argc, argv, all);
	all->threads = malloc(all->nb_philo * sizeof(pthread_t));
	all->forks = malloc(all->nb_philo * sizeof(t_mutex));
	all->philos = malloc(all->nb_philo * sizeof(t_philo));
	if (all->philos == NULL || all->threads == NULL
		|| all->forks == NULL)
	{
		all->init_err = 1;
		printf("malloc error\n");
		return (all);
	}
	init_mutexes_all_struct(all);
	init_philos(all);
	all->death = false;
	all->nb_sated = 0;
	if (all->max_eat == -1)
		all->nb_sated = -1;
	return (all);
}
