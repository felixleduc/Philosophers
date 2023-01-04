/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:15:30 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/04 12:26:43 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

//usage message
# define USAGE "\033[32;1mUsage: ./philo <nbr_of_philosophers> <time_to_die>\
<time_to_eat> <time_to_sleep> [max_eat]\033[0;m\n\
<nbr_of_philosophers>\ttotal number of philosophers\n\
<time_to_die>\t\tmaximum of time (ms) a philosophers can live without eating\n\
<time_to_eat>\t\tthe time (ms) a philosopher need to finish eating\n\
<time_to_sleep>\t\tthe time (ms) a philosopher need to be sleeping\n\
[max_eat]\t\tthe number of times each philosopher must eat"

//log messages
# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DIE	"died"

//philo status
# define EATING	0
# define OTHER	1

typedef unsigned int	t_ms;

typedef struct s_philo	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	bool			init;
}					t_mutex;

typedef struct s_all
{
	int				init_err;
	int				nb_philo;
	int				max_eat;
	int				nb_sated;
	bool			death;
	t_ms			start;
	t_ms			time_eat;
	t_ms			time_sleep;
	t_ms			time_die;
	t_mutex			*forks;
	t_mutex			lock_death;
	t_mutex			lock_sated;
	t_mutex			lock_print;
	pthread_t		*threads;
	t_philo			*philos;
}					t_all;

typedef struct s_philo
{
	int				nbr;
	int				eats;
	bool			status;
	t_ms			start_current_action;
	t_ms			last_eat;
	t_mutex			*left;
	t_mutex			*right;
	t_mutex			lock_eat;
	t_mutex			lock_status;
	t_all			*all;
}					t_philo;

//utils.c
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
t_ms			gettime(void);

//init.c
t_all			*init(int argc, char **argv);

//routine.c
void			init_threads(t_all *all);

//status_check.c
void			status_check(t_all *all, int threads_created);

//do_action.c
void			printer(t_philo *philo, char *action);
void			do_eat(t_philo *philo);
void			do_sleep(t_philo *philo);

//setter.c
void			set_death(t_all *all);
void			increment_sated(t_all *all);
void			set_status(t_philo *philo, bool status);
void			set_last_eat(t_philo *philo, t_ms time);

//checker.c
bool			check_death(t_all *all);
bool			check_sated(t_all *all);
bool			check_status(t_philo *philo);
t_ms			last_eat(t_philo *philo);

//sleep.c
void			usleep_eat(t_philo *philo);
void			usleep_check(t_philo *philo, t_ms time);

//cleaner.c
int				cleaner(t_all *all);

#endif
