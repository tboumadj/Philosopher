/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:53 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/30 22:20:00 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_init(t_philo *philo)
{
	if (philo->nb_p < 1)
		return (0);
	if (philo->time_td < 1)
		return (0);
	if (philo->time_te < 1)
		return (0);
	if (philo->time_ts < 1)
		return (0);
	if (philo->data.ac > 5)
		{
			if (philo->count_opt < 1)
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
			if (argv[i][j] < 48 || argv[i][j] > 57)
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
	if (verif_init(philo) == 0)
		return (0);
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