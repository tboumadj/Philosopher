/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:32:42 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/04 14:44:46 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_data *data)
{
	int	i;

	i = -1;
	while (i < data->nb_p)
		pthread_mutex_destroy(&(data->forks[++i]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->printing));
	free(data->philo);
	data->philo = NULL;
	free(data->forks);
}

void	sleeping_time(unsigned long long ms)
{
	unsigned long long	now;

	now = get_time();
	while (ms > (get_time() - now))
		usleep(50);
	return ;
}

void	print_road(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->dat->printing);
	printf("%llu philo : %d %s\n", get_time() - p->dat->time_start, p->n, str);
	pthread_mutex_unlock(&p->dat->printing);
	return ;
}

unsigned long long get_time(void)
{
    struct timeval tv;
    unsigned long long ms;

    gettimeofday(&tv, NULL);
    ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (ms);
}

int ft_atoi(const char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] <= 32 || str[i] == 43)
    i++;
    if (str[i] == 45)
    {
        neg *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
    {
        nb *= 10;
        nb += str[i] - 48;
        i++;
    }
    return (nb * neg);
}
