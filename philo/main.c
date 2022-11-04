/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:38:23 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/04 18:43:26 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	/*if (argc == 2)
	{
		if (check_onearg(&philo, argv[1]) == 0)
			return (0);
	}*/
	if (argc != 2 && (argc < 5 || argc > 6))
		ft_error_nrm("TOO FEW OR MORE ARG");
	else
	{
		data.ac = argc;
		data.av = argv;
		if (check_value(argv) == 1)
		{
			if(init_value(&data) == 0)
				ft_error_nrm("WRONG ARG!");
			if(init_mutex(&data) == 1)
			{
				init_philo(&data);
				if (check_finish(&data) == 1)
					ft_free_all(&data);
			}
		}
	}
	//-----TMP-----------//
	//printf("END!\n");
	return (0);
}