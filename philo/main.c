/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:38:23 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/29 22:08:22 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

 int	init_value(t_philo *philo)
 {
	
	philo->nb_p = ft_atoi(philo->data.av[1]);
	philo->time_td = ft_atoi(philo->data.av[2]);
	philo->time_te = ft_atoi(philo->data.av[3]);
	philo->time_ts = ft_atoi(philo->data.av[4]);
	if (philo->data.ac > 5)
		philo->count_opt = ft_atoi(philo->data.av[5]);
	else 
		philo->count_opt = 0;
	//-----------PRINT VAL-----------//
	if(philo->nb_p)
		printf("nb_p = %d\n", philo->nb_p);
	if(philo->time_td)
		printf("time_td = %d\n", philo->time_td);
	if(philo->time_te)
		printf("time_te = %d\n", philo->time_te);
	if(philo->time_ts)
		printf("time_ts = %d\n", philo->time_ts);
	if(philo->count_opt)
		printf("count_opt = %d\n", philo->count_opt);
	//--------------------------------//
	return (1);
 }

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		ft_error_nrm("TOO FEW OR MORE ARG");
	philo.data.ac = argc;
	philo.data.av = argv;
	if(init_value(&philo) == 0)
		ft_error_nrm("WRONG ARG!");
	//-----TMP-----------//
	printf("END!\n");
	return (0);
}