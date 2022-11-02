/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:41:35 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/03 00:22:29 by tboumadj@student ###   ########.fr       */
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

struct s_data;

typedef struct s_philo
{
	int					n;
	unsigned long long 	done_e;
	int					r_fork;
	int					l_fork;
	int					count_e;
	struct s_data		*dat;
	pthread_t			thread;
}	t_philo;

typedef struct s_data
{
	//int	cnt_arg;
	int					ac;
	char 				**av;
	int					nb_p;
	int					time_td;
	int					time_te;
	int					time_ts;
	int					count_opt;
	unsigned long long 	time_start;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t 	print;
}	t_data;

//-------------ERROR--------------//
void	ft_error_nrm(char *str);

//-------------UTILS-------------//
int					ft_atoi(const char *str);
unsigned long long	get_time(void);

//-------------CHECK--------------//
int		check_value(char **argv);
int		verif_init(t_data *data);

//-------------INIT----------------//
int		init_value(t_data *data);
int		init_philo(t_data *data);
int		init_mutex(t_data *data);

//------------THREAD----------------//
void	road_th(void *philo);

//--------OPT ARG--------------//
//int	check_onearg(t_philo *philo, char *argv);
//int	check_nb(char *str);
//int	count_arg(char *str);

#endif