/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:53:40 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/29 21:52:56 by tboumadj@student ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_nrm(char *str)
{
	int	count;

	count = 0;
	while(str[count])
		count++;
	write(2, "Philo : Error : ", 17);
	write(2, str, count);
	write(2, "\n", 1);
    exit(EXIT_FAILURE);
	return ;
}
