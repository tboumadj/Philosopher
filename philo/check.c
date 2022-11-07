/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:53 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/07 18:14:39 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_init(t_data *data)
{
	if (data->nb_p < 1)
		return (0);
	if (data->time_td < 1)
		return (0);
	if (data->time_te < 1)
		return (0);
	if (data->time_ts < 1)
		return (0);
	if (data->ac > 5)
	{
		if (data->count_opt < 1)
			return (0);
	}
	return (1);
}

int	check_value(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != 43 && (argv[i][j] < 48 || argv[i][j] > 57))
			{
				ft_error_nrm("ARG INVALID");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	check_df(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while ((i < data->nb_p) && data->p_dead == 0)
	{
		if ((get_time() - data->philo[i].done_e) > data->time_td)
		{
			data->p_dead = 1;
			pthread_mutex_lock(&data->printing);
			printf("%llu philo : %d is dead\n",
				get_time() - data->time_start, data->philo[i].n);
			return ;
		}
		i++;
	}
	i = 0;
	j = 0;
	if (data->count_opt > 0)
		check_eat(data);
	usleep(777);
}

void	check_eat(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->nb_p)
	{
		if (data->philo[i].count_e >= data->count_opt)
			j++;
		i++;
	}
	if (j == data->nb_p)
		data->full_opt = 1;
}

void	ft_error_nrm(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	write(2, "Philo : Error : ", 17);
	write(2, str, count);
	write(2, "\n", 1);
	return ;
}
