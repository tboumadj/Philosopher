/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:13:19 by tboumadj          #+#    #+#             */
/*   Updated: 2022/11/07 18:15:14 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->nb_p + 1));
	if (!data->forks)
		return (0);
	while (i <= data->nb_p)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->printing, NULL);
	return (1);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_p);
	if (!data->philo)
		return (0);
	while (i < data->nb_p)
	{
		data->philo[i].n = i + 1;
		data->philo[i].done_e = get_time();
		data->philo[i].count_e = 0;
		data->philo[i].r_fork = (i + 1);
		if (i == data->nb_p - 1)
			data->philo[i].l_fork = 1;
		else
			data->philo[i].l_fork = (i + 2);
		data->philo[i].dat = data;
		if (pthread_create(&data->philo[i].thread,
				NULL, road_th, &data->philo[i]))
			return (0);
		i++;
	}
	return (1);
}

int	init_value(t_data *data, char **argv, int argc)
{
	data->ac = argc;
	data->av = argv;
	data->p_dead = 0;
	data->full_opt = 0;
	data->nb_p = ft_atoi(data->av[1]);
	data->time_td = ft_atoi(data->av[2]);
	data->time_te = ft_atoi(data->av[3]);
	data->time_ts = ft_atoi(data->av[4]);
	if (data->ac > 5)
		data->count_opt = ft_atoi(data->av[5]);
	else
		data->count_opt = 0;
	if (verif_init(data) == 0)
		return (0);
	data->time_start = get_time();
	if (!data->time_start)
	{
		ft_error_nrm("TIME ERROR");
		return (0);
	}
	return (1);
}
