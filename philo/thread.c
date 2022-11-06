/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:55:32 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/06 18:17:53 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_th(t_philo *p)
{
	if (p->dat->p_dead == 1 || p->dat->full_opt == 1)
		return ;
	pthread_mutex_lock(&(p->dat->forks[p->r_fork]));
	print_road(p, "has taken a fork");
	if (p->l_fork == p->r_fork)
		sleeping_time(p->dat->time_td + 77);
	pthread_mutex_lock(&(p->dat->forks[p->l_fork]));
	print_road(p, "has taken a fork");
	//pthread_mutex_lock(&(p->dat->eating));
	print_road(p, "is eating");
	p->done_e = get_time();
	if (p->dat->count_opt > 0)
		p->count_e += 1;
	sleeping_time(p->dat->time_te);
	//pthread_mutex_unlock(&(p->dat->eating));
	pthread_mutex_unlock(&(p->dat->forks[p->r_fork]));
	pthread_mutex_unlock(&(p->dat->forks[p->l_fork]));
	//usleep(77);//----------TEST
	return ;
}

void	*road_th(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->n % 2 == 0)
		usleep(300);
	while (p->dat->p_dead == 0 && p->dat->full_opt == 0)
	{
		eat_th(p);
		if (p->dat->p_dead == 1 || p->dat->full_opt == 1)
			break ;
		print_road(p, "is sleeping");
		sleeping_time(p->dat->time_ts);
		if (p->dat->p_dead == 1 || p->dat->full_opt == 1)
			break ;
		print_road(p, "is thinking");
		usleep(150);//----------TEST
	}
	return (NULL);
}
