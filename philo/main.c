/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:38:23 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/08 16:02:56 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_data *data)
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && (argc < 5 || argc > 6))
		ft_error_nrm("TOO FEW OR MORE ARG");
	else
	{
		if (check_value(argv) == 1)
		{
			if (init_value(&data, argv, argc) == 0)
				ft_error_nrm("WRONG ARG!");
			else if (init_mutex(&data) == 1)
			{
				init_philo(&data);
				while (1)
				{
					if (check_finish(&data) == 1)
					{
						ft_free_all(&data);
						break ;
					}
				}
			}
		}
	}
	return (0);
}
