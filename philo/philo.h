/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:41:35 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/02 17:23:22 by tboumadj         ###   ########.fr       */
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

typedef struct s_philo
{
	//-----info philo
	int					n;
	unsigned long long 	done_e;
	int					r_fork;
	int					l_fork;
	int					count_e;
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
	unsigned long long 	time_start;// a verif
	t_philo				*philo;
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

//--------OPT ARG--------------//
//int	check_onearg(t_philo *philo, char *argv);
//int	check_nb(char *str);
//int	count_arg(char *str);

#endif