/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:13:19 by tboumadj          #+#    #+#             */
/*   Updated: 2022/11/04 14:45:37 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_p);
	if (!data->forks)
		return (0);
	while (i < data->nb_p)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->printing, NULL);
	pthread_mutex_init(&data->eating, NULL);
	return (1);
}
int	init_philo(t_data *data)
{
    int i;

    i = 0;
    data->philo = malloc(sizeof(t_philo) * data->nb_p);
    if(!data->philo)
        return (0);
    while(i < data->nb_p)
        {
            data->philo[i].n = i + 1;
            data->philo[i].done_e = data->time_start;
            data->philo[i].count_e = 0;
            data->philo[i].r_fork = (i + 1);
            if (i == data->nb_p - 1)
                    data->philo[i].l_fork = 1;
            else
                    data->philo[i].l_fork = (i + 2);
			data->philo[i].dat = data;
			if (pthread_create(&data->philo[i].thread, NULL, road_th, &data->philo[i]) != 0)
				return (0);
            /*//-----------PRINT VAL-----------//
            printf("-----------------\n");
            if (data->philo[i].n)
                printf("philo -> %d\n", data->philo[i].n);
            if (data->philo[i].done_e)
                printf("time = %llu\n", data->philo[i].done_e);
            if (data->philo[i].count_e > -1)
                printf("count eat = %d\n", data->philo[i].count_e);
            if (data->philo[i].l_fork > -1)
                printf("L fork = %d\n", data->philo[i].l_fork);
            if (data->philo[i].r_fork > -1)
                printf("R fork = %d\n", data->philo[i].r_fork);
            //--------------------------------//*/
            i++;
        }
		i = 0;
		while(i < data->nb_p)
			pthread_detach(data->philo[i++].thread);
    return (1);
}

int	init_value(t_data *data)
{
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
	/*//-----------PRINT VAL-----------//
	if(data->time_start)
		printf("time start = %llu\n", data->time_start);
	if(data->nb_p)
		printf("nb_p = %d\n", data->nb_p);
	if(data->time_td)
		printf("time_td = %d\n", data->time_td);
	if(data->time_te)
		printf("time_te = %d\n", data->time_te);
	if(data->time_ts)
		printf("time_ts = %d\n", data->time_ts);
	if(data->count_opt)
		printf("count_opt = %d\n", data->count_opt);
	//--------------------------------//*/
	return (1);
}