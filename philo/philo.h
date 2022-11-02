/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:41:35 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/31 17:50:43 by tboumadj@student ###   ########.fr       */
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
}	t_philo;

typedef struct s_data
{
	//int	cnt_arg;
	int		ac;
	char 	**av;
	int		nb_p;
	int		time_td;
	int		time_te;
	int		time_ts;
	int		count_opt;
	t_philo	*philo;
}	t_data;

//-------------ERROR--------------//
void	ft_error_nrm(char *str);

//-------------UTILS-------------//
int		ft_atoi(const char *str);

//-------------CHECK--------------//
int		init_value(t_data *data);
int		check_value(char **argv);
int		verif_init(t_data *data);

//--------OPT ARG--------------//
//int	check_onearg(t_philo *philo, char *argv);
//int	check_nb(char *str);
//int	count_arg(char *str);

#endif