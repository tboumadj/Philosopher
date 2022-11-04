/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:53 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/04 14:46:32 by tboumadj@student ###   ########.fr       */
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
	int j;

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
	int i;

	i = -1;
	while (++i < data->nb_p && data->p_dead == 0)
	{
		pthread_mutex_lock(&(data->eating));
		if(get_time() - data->philo[i].done_e > data->time_td)
		{
			data->p_dead = 1;
			print_road(data->philo, "is dead");
		}
		pthread_mutex_unlock(&(data->eating));
		i = 0;
		while (data->philo[i].count_e >= data->count_opt)
			i++;
		if (i == data->nb_p)
			data->full_opt = 1;
	}
}

int		check_finish(t_data *data)
{
	check_df(data);
	if (data->p_dead == 1)
		return (1);
	if (data->count_opt > 0)
	{
		if (data->full_opt == 1)
			return (1);
	}
	return (0);
}

/*int	count_arg(char *str)
{
	int i;
	int	count;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32 && str[i +1] > 32)
			count++;
		i++;
	}
	return (count);
}

int	check_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] <= 32)
			i++;
		if (str[i] < 48 || str[i] > 57)
			return(0);
		i++;
	}
	return (1);
}

int	check_onearg(t_philo *philo, char *argv)
{
	int i;

	i = 0;
	if (check_nb(argv) == 0)
		return (0);
	philo->data.cnt_arg = count_arg(argv);
	printf("%d\n", philo->data.cnt_arg);
	if (philo->data.cnt_arg != 5 || philo->data.cnt_arg != 6)
		return(0);
	
	
}*/