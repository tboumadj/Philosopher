/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:41:35 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/07 18:15:12 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_data;

typedef struct s_philo
{
	int					n;
	unsigned long long	done_e;
	int					r_fork;
	int					l_fork;
	int					count_e;
	struct s_data		*dat;
	pthread_t			thread;
}	t_philo;

typedef struct s_data
{
	int					ac;
	char				**av;
	int					nb_p;
	int					time_td;
	int					time_te;
	int					time_ts;
	int					count_opt;
	int					full_opt;
	int					p_dead;
	unsigned long long	time_start;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printing;
}	t_data;

//-------------UTILS-------------//
int					ft_atoi(const char *str);
unsigned long long	get_time(void);
void				print_road(t_philo *p, char *str);
void				sleeping_time(unsigned long long ms);
void				ft_free_all(t_data *data);
void				ft_error_nrm(char *str);

//-------------CHECK--------------//
int					check_value(char **argv);
int					verif_init(t_data *data);
void				check_df(t_data *data);
int					check_finish(t_data *data);
void				check_eat(t_data *data);

//-------------INIT----------------//
int					init_value(t_data *data, char **argv, int argc);
int					init_philo(t_data *data);
int					init_mutex(t_data *data);

//------------THREAD----------------//
void				*road_th(void *philo);
void				eat_th(t_philo *p);

#endif