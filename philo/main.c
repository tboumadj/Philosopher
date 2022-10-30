/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:38:23 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/30 22:14:32 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	/*if (argc == 2)
	{
		if (check_onearg(&philo, argv[1]) == 0)
			return (0);
	}*/
	if (argc != 2 && (argc < 5 || argc > 6))
		ft_error_nrm("TOO FEW OR MORE ARG");
	else
	{
		philo.data.ac = argc;
		philo.data.av = argv;
		if (check_value(argv) == 1)
		{
			if(init_value(&philo) == 0)
				ft_error_nrm("WRONG ARG!");
		}
	}
	//-----TMP-----------//
	printf("END!\n");
	return (0);
}